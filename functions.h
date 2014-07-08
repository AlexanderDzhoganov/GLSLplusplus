#ifndef __GLSLPP_FUNCTIONS_H
#define __GLSLPP_FUNCTIONS_H

// GLSL functions as defined in http://www.opengl.org/registry/doc/GLSLangSpec.4.40.pdf

namespace GLSLPP
{

	// Angle and Trigonometry Functions(8.1)

	template <typename detail>
	inline GenType<detail> radians(const GenType<detail>& degrees)
	{
		return GenType<detail>(xs("radians(%)", y_over_x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> degrees(const GenType<detail>& radians)
	{
		return GenType<detail>(xs("degrees(%)", y_over_x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> sin(const GenType<detail>& angle)
	{
		return GenType<detail>(xs("sin(%)", angle.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> cos(const GenType<detail>& angle)
	{
		return GenType<detail>(xs("cos(%)", angle.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> tan(const GenType<detail>& angle)
	{
		return GenType<detail>(xs("tan(%)", angle.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> asin(const GenType<detail>& x)
	{
		return GenType<detail>(xs("asin(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> acos(const GenType<detail>& x)
	{
		return GenType<detail>(xs("acos(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> atan(const GenType<detail>& y, const GenType<detail>& x)
	{
		return GenType<detail>(xs("atan(%, %)", y.ExtendedName(), x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> atan(const GenType<detail>& y_over_x)
	{
		return GenType<detail>(xs("atan(%)", y_over_x.ExtendedName()));
	}

	// Common Functions(8.3)

	template <typename detail>
	inline GenType<detail> abs(const GenType<detail>& x)
	{
		return GenType<detail>(xs("abs(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> ceil(const GenType<detail>& x)
	{
		return GenType<detail>(xs("ceil(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> clamp(const GenType<detail>& x, const GenType<detail>& minVal, const GenType<detail>& maxVal)
	{
		return GenType<detail>(xs("clamp(%, %, %)", x.ExtendedName(), minVal.ExtendedName(), maxVal.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> clamp(const GenType<detail>& genType, float minVal, float maxVal)
	{
		return GenType<detail>(xs("clamp(%, %, %)", x.ExtendedName(), minVal, maxVal));
	}

	template <typename detail>
	inline GenType<detail> floor(const GenType<detail>& x)
	{
		return GenType<detail>(xs("floor(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> fract(const GenType<detail>& x)
	{
		return GenType<detail>(xs("fract(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> max(const GenType<detail>& x, const GenType<detail>& y)
	{
		return GenType<detail>(xs("max(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> max(const GenType<detail>& x, float y)
	{
		return GenType<detail>(xs("max(%, %)", x.ExtendedName(), y));
	}

	template <typename detail>
	inline GenType<detail> min(const GenType<detail>& x, const GenType<detail>& y)
	{
		return GenType<detail>(xs("min(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> min(const GenType<detail>& x, float y)
	{
		return GenType<detail>(xs("min(%, %)", x.ExtendedName(), y));
	}

	template <typename detail>
	inline GenType<detail> mix(const GenType<detail>& x, const GenType<detail>& y, const GenType<detail>& a)
	{
		return GenType<detail>(xs("mix(%, %, %)", x.ExtendedName(), y.ExtendedName(), a.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> mix(const GenType<detail>& x, const GenType<detail>& y, float a)
	{
		return GenType<detail>(xs("mix(%, %, %)", x.ExtendedName(), y.ExtendedName(), a));
	}

	template <typename detail>
	inline GenType<detail> mod(const GenType<detail>& x, const GenType<detail>& y)
	{
		return GenType<detail>(xs("mod(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> mod(const GenType<detail>& x, float y)
	{
		return GenType<detail>(xs("mod(%, %)", x.ExtendedName(), y));
	}

	template <typename detail>
	inline GenType<detail> sign(const GenType<detail>& x)
	{
		return GenType<detail>(xs("sign(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> smoothstep(const GenType<detail>& edge0, const GenType<detail>& edge1, const GenType<detail>& x)
	{
		return GenType<detail>(xs("smoothstep(%, %, %)", edge0.ExtendedName(), edge1.ExtendedName(), x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> smoothstep(float edge0, float edge1, const GenType<detail>& x)
	{
		return GenType<detail>(xs("smoothstep(%, %, %)", edge0, edge1, x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> step(const GenType<detail>& edge, const GenType<detail>& x)
	{
		return GenType<detail>(xs("step(%, %)", edge.ExtendedName(), x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> step(float edge, const GenType<detail>& x)
	{
		return GenType<detail>(xs("step(%, %)", edge, x.ExtendedName()));
	}

	//Exponential Functions(8.2)

	template <typename detail>
	inline GenType<detail> pow(const GenType<detail>& x, const GenType<detail>& y)
	{
		return GenType<detail>(xs("pow(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> exp(const GenType<detail>& x)
	{
		return GenType<detail>(xs("exp(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> log(const GenType<detail>& x)
	{
		return GenType<detail>(xs("log(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> exp2(const GenType<detail>& x)
	{
		return GenType<detail>(xs("exp2(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> log2(const GenType<detail>& x)
	{
		return GenType<detail>(xs("log2(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> sqrt(const GenType<detail>& x)
	{
		return GenType<detail>(xs("sqrt(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> inversesqrt(const GenType<detail>& x)
	{
		return GenType<detail>(xs("inversesqrt(%)", x.ExtendedName()));
	}

	// Geometric Functions(8.4)

	template <typename detail>
	inline vec4 ftransform()
	{
		return vec4("ftransform()");
	}

	template <typename detail>
	inline vec3 cross(const vec3& x, const vec3& y)
	{
		return vec3(xs("cross(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	template <typename T>
	inline Float distance(const T& x, const T& y)
	{
		return Float(xs("distance(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	template <typename T>
	inline Float dot(const T& x, const T& y)
	{
		return Float(xs("dot(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	template <typename T>
	inline T faceforward(const T& v, const T& i, const T& n)
	{
		return Float(xs("faceforward(%, %, %)", v.ExtendedName(), i.ExtendedName(), n.ExtendedName()));
	}

	template <typename T>
	inline Float length(const T& x)
	{
		return Float(xs("length(%)", x.ExtendedName()));
	}

	template <typename T>
	inline T normalize(const T& x)
	{
		return Float(xs("normalize(%)", x.ExtendedName()));
	}

	template <typename T>
	inline T reflect(const T& i, const T& n)
	{
		return T(xs("refract(%, %)", i.ExtendedName(), n.ExtendedName()));
	}

	template <typename T>
	inline T refract(const T& i, const T& n, float eta)
	{
		return T(xs("refract(%, %, %)", i.ExtendedName(), n.ExtendedName(), eta));
	}

	// Fragment Processing Functions(8.8) Fragment ONLY
	template <typename T>
	inline T dFdx(const T& x)
	{
		return T(xs("dFdx(%)", x.ExtendedName()));
	}

	template <typename T>
	inline T dFdy(const T& x)
	{
		return T(xs("dFdy(%)", x.ExtendedName()));
	}

	template <typename T>
	inline T fwidth(const T& x)
	{
		return T(xs("fwidth(%)", x.ExtendedName()));
	}

	inline vec4 texture(const sampler2D& sampler, const vec2& texCoords)
	{
		vec4 result(Variable);
		result.m_Declared = true;
		currentProgram->InjectCode(xs("vec4 % = texture(%, %)", result.GetName(), sampler.GetName(), texCoords.ExtendedName()));
		return result;
	}

	inline vec4 texelFetch(const sampler2D& sampler, const ivec2& texCoords, const Int& lod)
	{
		vec4 result(Variable);
		result.m_Declared = true;
		currentProgram->InjectCode(xs("vec4 % = texelFetch(%, %, %)", result.GetName(), sampler.GetName(), texCoords.ExtendedName(), lod.GetName()));
		return result;
	}

	inline vec4 texelFetch(const sampler2D& sampler, const ivec2& texCoords, int lod)
	{
		vec4 result(Variable);
		result.m_Declared = true;
		currentProgram->InjectCode(xs("vec4 % = texelFetch(%, %, %)", result.GetName(), sampler.GetName(), texCoords.ExtendedName(), lod));
		return result;
	}

	inline vec4 texelFetch(const sampler2DMS& sampler, const ivec2& texCoords, const Int& lod)
	{
		vec4 result(Variable);
		result.m_Declared = true;
		currentProgram->InjectCode(xs("vec4 % = texelFetch(%, %, %)", result.GetName(), sampler.GetName(), texCoords.ExtendedName(), lod.GetName()));
		return result;
	}

	inline vec4 texelFetch(const sampler2DMS& sampler, const ivec2& texCoords, int lod)
	{
		vec4 result(Variable);
		result.m_Declared = true;
		currentProgram->InjectCode(xs("vec4 % = texelFetch(%, %, %)", result.GetName(), sampler.GetName(), texCoords.ExtendedName(), lod));
		return result;
	}

	template <typename T>
	inline T NoTemp(const T& t)
	{
		if (t.GetType() == Temporary)
		{
			T result(Variable);
			result.m_Declared = true;
			currentProgram->InjectCode(xs("% % = %", result.GetTypeName(), result.GetName(), t.ExtendedName()));
			return result;
		}
		else
		{
			return t;
		}
		
	}

}

#endif
