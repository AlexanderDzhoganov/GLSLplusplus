#ifndef __GLSLPP_VEC_DETAIL_H
#define __GLSLPP_VEC_DETAIL_H

namespace GLSLPP
{

	class gentype_bool_detail
	{

		public:
		typedef bool native_type;

		static inline const char* glsl_type_string()
		{
			return "bool";
		}

	};

	class gentype_int_detail
	{

		public:
		typedef int native_type;

		static inline const char* glsl_type_string()
		{
			return "int";
		}

	};

	class gentype_uint_detail
	{

		public:
		typedef unsigned int native_type;

		static inline const char* glsl_type_string()
		{
			return "uint";
		}

	};

	class gentype_float_detail
	{

		public:
		typedef float native_type;

		static inline const char* glsl_type_string()
		{
			return "float";
		}

	};

	class gentype_double_detail
	{

		public:
		typedef double native_type;

		static inline const char* glsl_type_string()
		{
			return "double";
		}

	};

	template <typename T>
	struct AbstractType
	{
		typedef T type;
	};

	template <>
	struct AbstractType<bool>
	{
		typedef GenType<gentype_bool_detail> type;
	};

	template <>
	struct AbstractType<int>
	{
		typedef GenType<gentype_int_detail> type;
	};

	template <>
	struct AbstractType<unsigned int>
	{
		typedef GenType<gentype_uint_detail> type;
	};

	template <>
	struct AbstractType<float>
	{
		typedef GenType<gentype_float_detail> type;
	};

	template <>
	struct AbstractType<double>
	{
		typedef GenType<gentype_double_detail> type;
	};

	typedef GenType<gentype_bool_detail> Bool;
	typedef GenType<gentype_int_detail> Int;
	typedef GenType<gentype_uint_detail> Uint;
	typedef GenType<gentype_float_detail> Float;
	typedef GenType<gentype_double_detail> Double;

	class vec2_bool_detail
	{

		public:
		typedef bool native_type;
		typedef GenType<gentype_bool_detail> abstract_type;

		static inline const char* glsl_type_string()
		{
			return "bvec2";
		}

	};

	class vec2_int_detail
	{

		public:
		typedef int native_type;
		typedef GenType<gentype_int_detail> abstract_type;

		static inline const char* glsl_type_string()
		{
			return "ivec2";
		}

	};

	class vec2_uint_detail
	{

		public:
		typedef unsigned int native_type;
		typedef GenType<gentype_uint_detail> abstract_type;

		static inline const char* glsl_type_string()
		{
			return "uvec2";
		}

	};

	class vec2_float_detail
	{

		public:
		typedef float native_type;
		typedef GenType<gentype_float_detail> abstract_type;

		static inline const char* glsl_type_string()
		{
			return "vec2";
		}

	};

	class vec2_double_detail
	{

		public:
		typedef double native_type;
		typedef GenType<gentype_double_detail> abstract_type;

		static inline const char* glsl_type_string()
		{
			return "dvec2";
		}

	};

	typedef generic_vec2<vec2_bool_detail> bvec2;
	typedef generic_vec2<vec2_int_detail> ivec2;
	typedef generic_vec2<vec2_uint_detail> uvec2;
	typedef generic_vec2<vec2_float_detail> vec2;
	typedef generic_vec2<vec2_double_detail> dvec2;

	class vec3_bool_detail
	{

		public:
		typedef bool native_type;
		typedef GenType<gentype_bool_detail> abstract_type;
		typedef vec2_bool_detail vec2_detail;

		static inline const char* glsl_type_string()
		{
			return "bvec3";
		}

	};

	class vec3_int_detail
	{

		public:
		typedef int native_type;
		typedef GenType<gentype_int_detail> abstract_type;
		typedef vec2_int_detail vec2_detail;

		static inline const char* glsl_type_string()
		{
			return "ivec3";
		}

	};


	class vec3_uint_detail
	{

		public:
		typedef unsigned int native_type;
		typedef GenType<gentype_uint_detail> abstract_type;
		typedef vec2_uint_detail vec2_detail;

		static inline const char* glsl_type_string()
		{
			return "uvec3";
		}

	};

	class vec3_float_detail
	{

		public:
		typedef float native_type;
		typedef GenType<gentype_float_detail> abstract_type;
		typedef vec2_float_detail vec2_detail;

		static inline const char* glsl_type_string()
		{
			return "vec3";
		}

	};

	class vec3_double_detail
	{

		public:
		typedef double native_type;
		typedef GenType<gentype_double_detail> abstract_type;
		typedef vec2_double_detail vec2_detail;

		static inline const char* glsl_type_string()
		{
			return "dvec3";
		}

	};

	typedef generic_vec3<vec3_bool_detail> bvec3;
	typedef generic_vec3<vec3_int_detail> ivec3;
	typedef generic_vec3<vec3_uint_detail> uvec3;
	typedef generic_vec3<vec3_float_detail> vec3;
	typedef generic_vec3<vec3_double_detail> dvec3;

	class vec4_bool_detail
	{

		public:
		typedef bool native_type;
		typedef GenType<gentype_bool_detail> abstract_type;
		typedef vec2_bool_detail vec2_detail;
		typedef vec3_bool_detail vec3_detail;

		static inline const char* glsl_type_string()
		{
			return "bvec4";
		}

	};

	class vec4_int_detail
	{

		public:
		typedef int native_type;
		typedef GenType<gentype_int_detail> abstract_type;
		typedef vec2_int_detail vec2_detail;
		typedef vec3_int_detail vec3_detail;

		static inline const char* glsl_type_string()
		{
			return "ivec4";
		}

	};

	class vec4_uint_detail
	{

		public:
		typedef unsigned int native_type;
		typedef GenType<gentype_int_detail> abstract_type;
		typedef vec2_uint_detail vec2_detail;
		typedef vec3_uint_detail vec3_detail;

		static inline const char* glsl_type_string()
		{
			return "uvec4";
		}

	};

	class vec4_float_detail
	{

		public:
		typedef float native_type;
		typedef GenType<gentype_float_detail> abstract_type;
		typedef vec2_float_detail vec2_detail;
		typedef vec3_float_detail vec3_detail;

		static inline const char* glsl_type_string()
		{
			return "vec4";
		}

	};

	class vec4_double_detail
	{

		public:
		typedef double native_type;
		typedef GenType<gentype_double_detail> abstract_type;
		typedef vec2_double_detail vec2_detail;
		typedef vec3_double_detail vec3_detail;

		static inline const char* glsl_type_string()
		{
			return "dvec4";
		}

	};

	typedef generic_vec4<vec4_bool_detail> bvec4;
	typedef generic_vec4<vec4_int_detail> ivec4;
	typedef generic_vec4<vec4_uint_detail> uvec4;
	typedef generic_vec4<vec4_float_detail> vec4;
	typedef generic_vec4<vec4_double_detail> dvec4;

}

#endif
