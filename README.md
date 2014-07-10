GLSLplusplus
============

**GLSL++ allows you to write C++ code which will (at runtime) output a valid GLSL shader.**

The goal of the library is twofold:
- Define a domain-specific language within C++ that looks and feels as similar to GLSL as possible. This will allow us  to leverage C++'s type system, compile-time checks and extensive tooling, therefore eliminating many problems associated with writing GLSL (e.g. mistyped variable names, incorrect assignments, etc.) without an additional compilation phase. (This is mostly implemented. See below for GLSL features that are still missing.)
- Provide a testing environment where GLSL++ code can be compiled as C++ and stepped through with any C++ debugger. (This part of the project is still in planning phase.)

This approach also greatly simplifies writing (uber-)shaders that depend on run-time parameters without the #ifdef clutter.

**Note: GLSL++ is still in early stages of development (as in, documentation is practically nonexistent, not everything works correctly, not all GLSL features are supported and syntax may change at any time). Look at the samples/ folder for example usage. Pull and feature requests are welcome.**

**Example:**
The following C++ code:

```
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
}
```

translates to:

Vertex shader:
```
#version 440

#extension GL_ARB_explicit_attrib_location : enable
layout(location = 0) in vec4 temp_1;
layout(location = 1) in vec4 temp_2;
uniform mat4 ModelViewProjection;
uniform mat4 InverseTransposeViewProjection;
out vec3 temp_3;
out vec4 gl_Position;

void main()
{
    temp_3 = (InverseTransposeViewProjection * vec4(temp_2.xyz, 0.000000e+000)).xyz;
    gl_Position = vec4((ModelViewProjection * vec4(temp_1.xyz, 1.000000e+000)).xyz, 1.000000e+000);
}
```

Fragment shader:
```
#version 440

#extension GL_ARB_explicit_attrib_location : enable
in vec3 temp_3;
out vec4 ColorOut;
uniform vec3 DiffuseColor;
uniform vec3 LightDirection;

void main()
{
    ColorOut = vec4((DiffuseColor * dot(temp_3, LightDirection)), 1.000000e+000);
}
```

Currently supported GLSL features:
* Types: bool, int, uint, float, double, bvecN, ivecN, uvecN, vecN, dvecN, matN, sampler2D, sampler2DMS
* Most GLSL functions as of GLSL 4.40
* Attribute layout
* Uniform binding
* Swizzling
* "Special" GLSL variables (e.g. gl_FragCoord)
* Control flow - if & while
* Extensions: GL_ARB_explicit_attrib_location, GL_ARB_explicit_uniform_location, GL_ARB_shading_language_420pack

Not supported:
* matNxM
* Uniform arrays
* Uniform blocks
* Geometry, compute and tessalate shaders
* GLSL macros
* const
* control flow - for
