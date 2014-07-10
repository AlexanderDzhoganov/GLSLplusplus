#ifndef __GLSLPP_SAMPLER2D_H
#define __GLSLPP_SAMPLER2D_H

namespace GLSLPP
{

	template <typename detail>
	class generic_sampler2D : public Type
	{

		template <typename detail>
		friend typename detail::sample_type texture(const generic_sampler2D<detail>&, const vec2&);

		friend vec4 texelFetch(const generic_sampler2D& sampler, const ivec2& texCoords, const Int& lod);

		friend vec4 texelFetch(const generic_sampler2D& sampler, const ivec2& texCoords, int lod);

		public:
		explicit generic_sampler2D(VariableQualifier type) :
			Type(type, detail::glsl_type_string(), currentProgram->GenerateName())
		{
		}

		generic_sampler2D(VariableQualifier type, int layoutLocation) :
			Type(type, detail::glsl_type_string(), currentProgram->GenerateName(), layoutLocation)
		{
		}

		generic_sampler2D(VariableQualifier type, const std::string& name) :
			Type(type, detail::glsl_type_string(), name)
		{
		}

		generic_sampler2D(VariableQualifier type, const std::string& name, int layoutLocation) :
			Type(type, detail::glsl_type_string(), name, layoutLocation)
		{
		}

	};

	class sampler2D_int_detail
	{

		public:
		typedef int native_type;
		typedef ivec4 sample_type;

		static inline const char* glsl_type_string()
		{
			return "isampler2D";
		}

	};

	class sampler2D_uint_detail
	{

		public:
		typedef unsigned int native_type;
		typedef uvec4 sample_type;

		static inline const char* glsl_type_string()
		{
			return "usampler2D";
		}

	};

	class sampler2D_float_detail
	{

		public:
		typedef float native_type;
		typedef vec4 sample_type;

		static inline const char* glsl_type_string()
		{
			return "sampler2D";
		}

	};

	typedef generic_sampler2D<sampler2D_int_detail> isampler2D;
	typedef generic_sampler2D<sampler2D_uint_detail> usampler2D;
	typedef generic_sampler2D<sampler2D_float_detail> sampler2D;

}

#endif
