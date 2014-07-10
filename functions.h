#ifndef __GLSLPP_FUNCTIONS_H
#define __GLSLPP_FUNCTIONS_H

// GLSL functions as defined in http://www.opengl.org/registry/doc/GLSLangSpec.4.40.pdf

namespace GLSLPP
{

	// Geometric Functions(8.4)

	template <typename detail>
	inline vec4 ftransform()
	{
		return vec4("ftransform()");
	}

	template <typename detail>
	inline generic_vec3<detail> cross(const generic_vec3<detail>& x, const generic_vec3<detail>& y)
	{
		return generic_vec3<detail>(xs("cross(%, %)", x.Definition(), y.Definition()));
	}

	template <typename detail>
	inline typename detail::abstract_type distance(const generic_vec2<detail>& x, const generic_vec2<detail>& y)
	{
		return typename detail::abstract_type(xs("distance(%, %)", x.Definition(), y.Definition()));
	}

	template <typename detail>
	inline typename detail::abstract_type distance(const generic_vec3<detail>& x, const generic_vec3<detail>& y)
	{
		return typename detail::abstract_type(xs("distance(%, %)", x.Definition(), y.Definition()));
	}

	template <typename detail>
	inline typename detail::abstract_type distance(const generic_vec4<detail>& x, const generic_vec4<detail>& y)
	{
		return typename detail::abstract_type(xs("distance(%, %)", x.Definition(), y.Definition()));
	}

	template <typename detail>
	inline typename detail::abstract_type dot(const generic_vec2<detail>& x, const generic_vec2<detail>& y)
	{
		return typename detail::abstract_type(xs("dot(%, %)", x.Definition(), y.Definition()));
	}

	template <typename detail>
	inline typename detail::abstract_type dot(const generic_vec3<detail>& x, const generic_vec3<detail>& y)
	{
		return typename detail::abstract_type(xs("dot(%, %)", x.Definition(), y.Definition()));
	}

	template <typename detail>
	inline typename detail::abstract_type dot(const generic_vec4<detail>& x, const generic_vec4<detail>& y)
	{
		return typename detail::abstract_type(xs("dot(%, %)", x.Definition(), y.Definition()));
	}

	template <typename T>
	inline T faceforward(const T& v, const T& i, const T& n)
	{
		return Float(xs("faceforward(%, %, %)", v.Definition(), i.Definition(), n.Definition()));
	}

	template <typename T>
	inline Float length(const T& x)
	{
		return Float(xs("length(%)", x.Definition()));
	}

	template <typename detail>
	inline generic_vec2<detail> normalize(const generic_vec2<detail>& x)
	{
		return generic_vec2<detail>(xs("normalize(%)", x.Definition()));
	}

	template <typename detail>
	inline generic_vec3<detail> normalize(const generic_vec3<detail>& x)
	{
		return generic_vec3<detail>(xs("normalize(%)", x.Definition()));
	}

	template <typename detail>
	inline generic_vec4<detail> normalize(const generic_vec4<detail>& x)
	{
		return generic_vec4<detail>(xs("normalize(%)", x.Definition()));
	}

	template <typename detail>
	inline generic_vec2<detail> reflect(const generic_vec2<detail>& i, const generic_vec2<detail>& n)
	{
		return generic_vec2<detail>(xs("refract(%, %)", i.Definition(), n.Definition()));
	}

	template <typename detail>
	inline generic_vec3<detail> reflect(const generic_vec3<detail>& i, const generic_vec3<detail>& n)
	{
		return generic_vec3<detail>(xs("refract(%, %)", i.Definition(), n.Definition()));
	}

	template <typename detail>
	inline generic_vec4<detail> reflect(const generic_vec4<detail>& i, const generic_vec4<detail>& n)
	{
		return generic_vec4<detail>(xs("refract(%, %)", i.Definition(), n.Definition()));
	}

	template <typename detail>
	inline generic_vec2<detail> refract(const generic_vec2<detail>& i, const generic_vec2<detail>& n, float eta)
	{
		return generic_vec2<detail>(xs("refract(%, %, %)", i.Definition(), n.Definition(), eta));
	}

	template <typename detail>
	inline generic_vec3<detail> refract(const generic_vec3<detail>& i, const generic_vec3<detail>& n, float eta)
	{
		return generic_vec3<detail>(xs("refract(%, %, %)", i.Definition(), n.Definition(), eta));
	}

	template <typename detail>
	inline generic_vec4<detail> refract(const generic_vec4<detail>& i, const generic_vec4<detail>& n, float eta)
	{
		return generic_vec4<detail>(xs("refract(%, %, %)", i.Definition(), n.Definition(), eta));
	}

	// Fragment Processing Functions(8.8) Fragment ONLY
	template <typename T>
	inline T dFdx(const T& x)
	{
		return T(xs("dFdx(%)", x.Definition()));
	}

	template <typename T>
	inline T dFdy(const T& x)
	{
		return T(xs("dFdy(%)", x.Definition()));
	}

	template <typename T>
	inline T fwidth(const T& x)
	{
		return T(xs("fwidth(%)", x.Definition()));
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
			texCoords.Definition())
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
			texCoords.Definition(),
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
			texCoords.Definition(), 
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
			texCoords.Definition(), 
			lod.GetName())
		);
		return result;
	}

	inline vec4 texelFetch(const sampler2DMS& sampler, const ivec2& texCoords, int lod)
	{
		vec4 result(Variable);
		result.m_Declared = true;
		currentProgram->InjectCode(xs("vec4 % = texelFetch(%, %, %)", result.GetName(), sampler.GetName(), texCoords.Definition(), lod));
		return result;
	}

	template <typename T>
	inline T NoTemp(const T& t)
	{
		if (t.GetType() == Temporary)
		{
			T result(Variable);
			result.m_Declared = true;
			currentProgram->InjectCode(xs("% % = %", result.GetTypeName(), result.GetName(), t.Definition()));
			return result;
		}
		else
		{
			return t;
		}
		
	}

}

#endif
