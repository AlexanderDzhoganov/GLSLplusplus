#include <iostream>
#include <glsl++.h>

using namespace GLSLPP;

void SimpleDiffuseVertex
(
	const vec4& position,
	const vec4& normal,
	const mat4& modelViewProj,
	const mat4& inverseTransposeViewProj,
	vec3& worldNormal,
	vec4& gl_Position
)
{
	vec4 worldPosition = modelViewProj * vec4(position.xyz(), 1.0);
	worldNormal = (inverseTransposeViewProj * vec4(normal.xyz(), 0.0)).xyz();
	Float d = distance(worldPosition, vec4(worldNormal, 0.0));
	gl_Position = vec4(worldPosition.xyz(), 1.0);
}

void SimpleDiffuseFragment
(
	const vec3& diffuseColor,
	const vec3& lightDirection,
	const vec3& worldNormal,
	vec4& colorOut
)
{
	Float d = dot(worldNormal, lightDirection);
	colorOut = vec4(diffuseColor * d, 1.0);
}

int main()
{
	Program program(GLSLVersion::GLSL440);
	program.EnableExtension(GL_ARB_explicit_attrib_location);

	// vertex shader definitions
	vec4 position(VertexIn, 0);
	vec4 normal(VertexIn, 1);

	mat4 modelViewProj(VertexUniform, "ModelViewProjection");
	mat4 inverseTransposeViewProj(VertexUniform, "InverseTransposeViewProjection");

	vec3 worldNormal(VertexOut);
	vec4 gl_Position(VertexOut, "gl_Position");

	// vertex main()
	program.SetVertexShader([&]() { SimpleDiffuseVertex(position, normal, modelViewProj, inverseTransposeViewProj, worldNormal, gl_Position); });

	// fragment shader definitions
	vec4 colorOut(FragmentOut, "ColorOut");

	vec3 diffuseColor(FragmentUniform, "DiffuseColor");
	vec3 lightDirection(FragmentUniform, "LightDirection");

	// fragment main()
	program.SetFragmentShader([&]() { SimpleDiffuseFragment(diffuseColor, lightDirection, worldNormal, colorOut); });

	// print result
	std::cout << "Vertex source: " << program.GetVertexSource() << std::endl << std::endl;
	std::cout << "Fragment source: " << program.GetFragmentSource() << std::endl;
}