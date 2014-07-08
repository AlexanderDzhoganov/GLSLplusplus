GLSLplusplus
============

GLSL++ allows you to write C++ code which will (at runtime) be translated into a GLSL shader.
This approach greatly simplifies writing shaders that depend on run-time parameters without the #ifdef clutter.

Example:

The following C++ code:

```
Program program;

vec3 position_in(VertexIn, "PositionIn", 0);
vec2 uvs_in(VertexIn, "UVsIn", 1);

vec4 gl_Position(VertexOut, "gl_Position");
vec2 uvs_out(VertexOut, "UVsOut");

// vertex main()
program.BeginVertexShaderFunction("main");

gl_Position = vec4(position_in.xy(), 1.0, 1.0);
uvs_out = uvs_in;

program.EndVertexShaderFunction();
//

sampler2D source(FragmentUniform, "Source");
vec4 fragment(FragmentOut);

// fragment main()
program.BeginFragmentShaderFunction("main");

fragment = vec4(texture(source, uvs_out).rgb(), 1.0);

program.EndFragmentShaderFunction();
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

Note: GLSL++ is still work in progress (as in, not all GLSL features are supported). Pull requests are welcome.

Currently supported GLSL features:
* Types: int, float, vec2, vec3, vec4, mat3, mat4, sampler2D, sampler2DMS
* All GLSL functions as of GLSL 4.40
* Attribute layout
* Uniform binding
* Swizzling
* "special" GLSL variables (e.g. gl_FragCoord)

Not supported:
* Function definitions
