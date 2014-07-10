#ifndef __GLSLPP_FUNCTIONS_H
#define __GLSLPP_FUNCTIONS_H

// GLSL functions as defined in http://www.opengl.org/registry/doc/GLSLangSpec.4.40.pdf

namespace GLSLPP
{

	
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
