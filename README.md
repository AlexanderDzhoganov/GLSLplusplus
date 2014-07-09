GLSLplusplus
============

**GLSL++ allows you to write C++ code which will (at runtime) output a valid GLSL shader.**

The goal of the library is twofold:
- Define a domain-specific language within C++ that looks and feels as similar to GLSL as possible. This will allow us  to leverage C++'s type system, compile-time checks and extensive tooling, therefore eliminating many problems associated with writing GLSL (e.g. mistyped variable names, incorrect assignments, etc.) without an additional compilation phase. (This is mostly implemented. See below for GLSL features that are still missing.)
- Provide a testing environment where GLSL++ code can be compiled as C++ and stepped through with any C++ debugger. (This part of the project is still in planning phase.)

This approach also greatly simplifies writing (uber-)shaders that depend on run-time parameters without the #ifdef clutter.

**Example:**
The following C++ code:

```
Program program;

vec3 position_in(VertexIn, "PositionIn", 0);
vec2 uvs_in(VertexIn, "UVsIn", 1);

vec4 gl_Position(VertexOut, "gl_Position");
vec2 uvs_out(VertexOut, "UVsOut");

// vertex main()
program.VertexMain();

gl_Position = vec4(position_in.xy(), 1.0, 1.0);
uvs_out = uvs_in;

program.EndVertexMain();
//

sampler2D source(FragmentUniform, "Source");
vec4 fragment(FragmentOut);

// fragment main()
program.FragmentMain("main");

fragment = vec4(texture(source, uvs_out).rgb(), 1.0);

program.EndFragmentMain();
```

translates to:

Vertex shader:
```
in (layout=0) vec3 PositionIn;
in (layout=1) vec2 UVsIn;
out vec4 gl_Position;
out vec2 UVsOut;

void main()
{
    gl_Position = vec4(PositionIn.xy, 1, 1);
    UVsOut = UVsIn;
}
```

Fragment shader:
```
in vec2 UVsOut;
uniform sampler2D Source;
out vec4 temp_4;

void main()
{
    vec4 temp_5 = texture(Source, UVsOut);
    temp_4 = vec4(temp_5.xyz, 1);
}
```

**Note: GLSL++ is still in rapid development (as in, not everything works correctly, not all GLSL features are supported and syntax may change at any time). Pull requests are welcome.**

Currently supported GLSL features:
* Types: int, float, vec2, vec3, vec4, mat3, mat4, sampler2D, sampler2DMS
* All GLSL functions as of GLSL 4.40
* Attribute layout
* Uniform binding
* Swizzling
* "Special" GLSL variables (e.g. gl_FragCoord)
* Control flow - if & while
* Extensions: GL_ARB_explicit_attrib_location, GL_ARB_explicit_uniform_location, GL_ARB_shading_language_420pack

Not supported:
* Function definitions
* matNxM
* Uniform blocks
* Geometry shaders
* Compute shaders
* GLSL macros
* const
* control flow - for
