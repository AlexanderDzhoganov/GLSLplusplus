#include <iostream>
#include <glsl++.h>

using namespace GLSLPP;

int main()
{
	Program program;
	program.EnableExtension(GL_ARB_explicit_attrib_location);

	// vertex shader definitions

	vec4 position(VertexIn, 0);
	vec4 normal(VertexIn, 1);

	vec3 worldNormal(VertexOut);

	mat4 modelViewProj(VertexUniform, "ModelViewProjection");
	mat4 inverseTransposeViewProj(VertexUniform, "InverseTransposeViewProjection");

	vec4 gl_Position(VertexOut, "gl_Position");

	program.VertexMain(); // vertex shader main()

	vec4 worldPosition = modelViewProj * vec4(position.xyz(), 1.0);
	worldNormal = (inverseTransposeViewProj * vec4(normal.xyz(), 0.0)).xyz();
	gl_Position = vec4(worldPosition.xyz(), 1.0);

	program.EndVertexMain();

	// fragment shader definitions
	vec4 colorOut(FragmentOut, "ColorOut");
	
	vec3 diffuseColor(FragmentUniform, "DiffuseColor");
	vec3 lightDirection(FragmentUniform, "LightDirection");

	program.FragmentMain(); // fragment shader main()

	Float d = dot(worldNormal, lightDirection);
	colorOut = vec4(diffuseColor * d, 1.0);

	program.EndFragmentMain();		

	std::cout << "Vertex source: " << program.GetVertexSource() << std::endl << std::endl;
	std::cout << "Fragment source: " << program.GetFragmentSource() << std::endl;
}