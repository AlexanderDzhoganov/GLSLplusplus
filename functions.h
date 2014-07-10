#ifndef __GLSLPP_FUNCTIONS_H
#define __GLSLPP_FUNCTIONS_H

// GLSL functions as defined in http://www.opengl.org/registry/doc/GLSLangSpec.4.40.pdf

namespace GLSLPP
{

	// Common Functions(8.3)

	template <typename detail>
	inline GenType<detail> abs(const GenType<detail>& x)
	{
		return GenType<detail>(xs("abs(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> sign(const GenType<detail>& x)
	{
		return GenType<detail>(xs("sign(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> floor(const GenType<detail>& x)
	{
		return GenType<detail>(xs("floor(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> trunc(const GenType<detail>& x)
	{
		return GenType<detail>(xs("trunc(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> round(const GenType<detail>& x)
	{
		return GenType<detail>(xs("round(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> roundEven(const GenType<detail>& x)
	{
		return GenType<detail>(xs("roundEven(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> ceil(const GenType<detail>& x)
	{
		return GenType<detail>(xs("ceil(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> fract(const GenType<detail>& x)
	{
		return GenType<detail>(xs("fract(%)", x.ExtendedName()));
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

	// Geometric Functions(8.4)

	template <typename detail>
	inline vec4 ftransform()
	{
		return vec4("ftransform()");
	}

	template <typename detail>
	inline generic_vec3<detail> cross(const generic_vec3<detail>& x, const generic_vec3<detail>& y)
	{
		return generic_vec3<detail>(xs("cross(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	template <typename detail>
	inline typename detail::abstract_type distance(const generic_vec2<detail>& x, const generic_vec2<detail>& y)
	{
		return typename detail::abstract_type(xs("distance(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	template <typename detail>
	inline typename detail::abstract_type distance(const generic_vec3<detail>& x, const generic_vec3<detail>& y)
	{
		return typename detail::abstract_type(xs("distance(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	template <typename detail>
	inline typename detail::abstract_type distance(const generic_vec4<detail>& x, const generic_vec4<detail>& y)
	{
		return typename detail::abstract_type(xs("distance(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	template <typename detail>
	inline typename detail::abstract_type dot(const generic_vec2<detail>& x, const generic_vec2<detail>& y)
	{
		return typename detail::abstract_type(xs("dot(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	template <typename detail>
	inline typename detail::abstract_type dot(const generic_vec3<detail>& x, const generic_vec3<detail>& y)
	{
		return typename detail::abstract_type(xs("dot(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	template <typename detail>
	inline typename detail::abstract_type dot(const generic_vec4<detail>& x, const generic_vec4<detail>& y)
	{
		return typename detail::abstract_type(xs("dot(%, %)", x.ExtendedName(), y.ExtendedName()));
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

	template <typename detail>
	inline generic_vec2<detail> normalize(const generic_vec2<detail>& x)
	{
		return generic_vec2<detail>(xs("normalize(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline generic_vec3<detail> normalize(const generic_vec3<detail>& x)
	{
		return generic_vec3<detail>(xs("normalize(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline generic_vec4<detail> normalize(const generic_vec4<detail>& x)
	{
		return generic_vec4<detail>(xs("normalize(%)", x.ExtendedName()));
	}

	template <typename detail>
	inline generic_vec2<detail> reflect(const generic_vec2<detail>& i, const generic_vec2<detail>& n)
	{
		return generic_vec2<detail>(xs("refract(%, %)", i.ExtendedName(), n.ExtendedName()));
	}

	template <typename detail>
	inline generic_vec3<detail> reflect(const generic_vec3<detail>& i, const generic_vec3<detail>& n)
	{
		return generic_vec3<detail>(xs("refract(%, %)", i.ExtendedName(), n.ExtendedName()));
	}

	template <typename detail>
	inline generic_vec4<detail> reflect(const generic_vec4<detail>& i, const generic_vec4<detail>& n)
	{
		return generic_vec4<detail>(xs("refract(%, %)", i.ExtendedName(), n.ExtendedName()));
	}

	template <typename detail>
	inline generic_vec2<detail> refract(const generic_vec2<detail>& i, const generic_vec2<detail>& n, float eta)
	{
		return generic_vec2<detail>(xs("refract(%, %, %)", i.ExtendedName(), n.ExtendedName(), eta));
	}

	template <typename detail>
	inline generic_vec3<detail> refract(const generic_vec3<detail>& i, const generic_vec3<detail>& n, float eta)
	{
		return generic_vec3<detail>(xs("refract(%, %, %)", i.ExtendedName(), n.ExtendedName(), eta));
	}

	template <typename detail>
	inline generic_vec4<detail> refract(const generic_vec4<detail>& i, const generic_vec4<detail>& n, float eta)
	{
		return generic_vec4<detail>(xs("refract(%, %, %)", i.ExtendedName(), n.ExtendedName(), eta));
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
	
	template <typename detail>
	inline typename detail::sample_type texture(const generic_sampler2D<detail>& sampler, const vec2& texCoords)
	{
		typename detail::sample_type result(Variable);
		result.m_Declared = true;
		currentProgram->InjectCode(xs
		(
			"% % = texture(%, %)",
			result.GetTypeName(),
			result.GetName(),
			sampler.GetName(),
			texCoords.ExtendedName())
		);
		return result;
	}

	template <typename detail>
	inline typename detail::sample_type texelFetch(const generic_sampler2D<detail>& sampler, const ivec2& texCoords, const Int& lod)
	{
		typename detail::sample_type result(Variable);
		result.m_Declared = true;
		currentProgram->InjectCode(xs
		(
			"% % = texelFetch(%, %, %)",
			result.GetTypeName(),
			result.GetName(),
			sampler.GetName(),
			texCoords.ExtendedName(),
			lod.GetName())
		);
		return result;
	}

	template <typename detail>
	inline typename detail::sample_type texelFetch(const generic_sampler2D<detail>& sampler, const ivec2& texCoords, int lod)
	{
		typename detail::sample_type result(Variable);
		result.m_Declared = true;
		currentProgram->InjectCode(xs
		(
			"% % = texelFetch(%, %, %)",
			result.GetTypeName(),
			result.GetName(),
			sampler.GetName(),
			texCoords.ExtendedName(), 
			lod)
		);
		return result;
	}

	inline vec4 texelFetch(const sampler2DMS& sampler, const ivec2& texCoords, const Int& lod)
	{
		vec4 result(Variable);
		result.m_Declared = true;
		currentProgram->InjectCode(xs
		(
			"vec4 % = texelFetch(%, %, %)",
			result.GetName(),
			sampler.GetName(),
			texCoords.ExtendedName(), 
			lod.GetName())
		);
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
