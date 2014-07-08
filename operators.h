#ifndef __GLSLPP_OPERATORS_H
#define __GLSLPP_OPERATORS_H

namespace GLSLPP
{

	// float operators
	template <typename detail>
	inline GenType<detail> operator+(const GenType<detail>& a, typename detail::native_type b)
	{
		return GenType<detail>(xs("(% + %)", a.ExtendedName(), b));
	}

	template <typename detail>
	inline GenType<detail> operator+(const GenType<detail>& a, const GenType<detail>& b)
	{
		return GenType<detail>(xs("(% + %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename detail>
	inline void operator+=(GenType<detail>& a, typename detail::native_type b)
	{
		a = a + b;
	}

	template <typename detail>
	inline void operator+=(GenType<detail>& a, const GenType<detail>& b)
	{
		a = a + b;
	}

	template <typename detail>
	inline GenType<detail> operator-(const GenType<detail>& a, typename detail::native_type b)
	{
		return GenType<detail>(xs("(% - %)", a.ExtendedName(), b));
	}

	template <typename detail>
	inline GenType<detail> operator-(typename detail::native_type a, const GenType<detail>& b)
	{
		return GenType<detail>(xs("(% - %)", a, b.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> operator-(const GenType<detail>& a, const GenType<detail>& b)
	{
		return GenType<detail>(xs("(% - %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename detail>
	inline void operator-=(GenType<detail>& a, typename detail::native_type b)
	{
		a = a - b;
	}

	template <typename detail>
	inline void operator-=(GenType<detail>& a, const GenType<detail>& b)
	{
		a = a - b;
	}

	inline GenType<gentype_float_detail> operator*(const GenType<gentype_float_detail>& a, const GenType<gentype_int_detail>& b)
	{
		return GenType<gentype_float_detail>(xs("(% * %)", a.ExtendedName(), b.ExtendedName()));
	}

	inline GenType<gentype_float_detail> operator*(const GenType<gentype_int_detail>& a, const GenType<gentype_float_detail>& b)
	{
		return GenType<gentype_float_detail>(xs("(% * %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename detail>
	inline GenType<detail> operator*(const GenType<detail>& a, typename detail::native_type b)
	{
		return GenType<detail>(xs("(% * %)", a.ExtendedName(), b));
	}

	template <typename detail>
	inline GenType<detail> operator*(const GenType<detail>& a, const GenType<detail>& b)
	{
		return GenType<detail>(xs("(% * %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename detail>
	inline void operator*=(GenType<detail>& a, typename detail::native_type b)
	{
		a = a * b;
	}

	template <typename detail>
	inline void operator*=(GenType<detail>& a, const GenType<detail>& b)
	{
		a = a * b;
	}

	template <typename detail>
	inline GenType<detail> operator/(const GenType<detail>& a, typename detail::native_type b)
	{
		return GenType<detail>(xs("(% / %)", a.ExtendedName(), b));
	}

	template <typename detail>
	inline GenType<detail> operator/(const GenType<detail>& a, const GenType<detail>& b)
	{
		return GenType<detail>(xs("(% / %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename detail>
	inline void operator/=(GenType<detail>& a, typename detail::native_type b)
	{
		a = a / b;
	}

	template <typename detail>
	inline void operator/=(GenType<detail>& a, const GenType<detail>& b)
	{
		a = a / b;
	}

	template <typename detail>
	inline GenType<detail> operator%(const GenType<detail>& a, typename detail::native_type b)
	{
		return GenType<detail>(xs("(% %% %)", a.ExtendedName(), b));
	}

	template <typename detail>
	inline GenType<detail> operator%(const GenType<detail>& a, const GenType<detail>& b)
	{
		return GenType<detail>(xs("(% %% %)", a.ExtendedName(), b.ExtendedName()));
	}

	// vec2 operators
	inline vec2 operator+(const vec2& a, const vec2& b)
	{
		return vec2(xs("(% + %)", a.ExtendedName(), b.ExtendedName()));
	}

	inline void operator+=(vec2& a, const vec2& b)
	{
		a = a + b;
	}

	inline vec2 operator-(const vec2& a, const vec2& b)
	{
		return vec2(xs("(% - %)", a.ExtendedName(), b.ExtendedName()));
	}

	inline void operator-=(vec2& a, const vec2& b)
	{
		a = a - b;
	}

	inline vec2 operator*(const vec2& a, const vec2& b)
	{
		return vec2(xs("(% * %)", a.ExtendedName(), b.ExtendedName()));
	}

	inline void operator*=(vec2& a, const vec2& b)
	{
		a = a * b;
	}

	inline vec2 operator/(const vec2& a, const vec2& b)
	{
		return vec2(xs("(% / %)", a.ExtendedName(), b.ExtendedName()));
	}

	inline void operator/=(vec2& a, const vec2& b)
	{
		a = a / b;
	}

	inline vec2 operator*(const vec2& a, const Float& b)
	{
		return vec2(xs("(% * %)", a.ExtendedName(), b.ExtendedName()));
	}

	inline void operator*=(vec2& a, const Float& b)
	{
		a = a * b;
	}

	inline vec2 operator/(const vec2& a, const Float& b)
	{
		return vec2(xs("(% / %)", a.ExtendedName(), b.ExtendedName()));
	}

	inline void operator/=(vec2& a, const Float& b)
	{
		a = a / b;
	}

	inline vec2 operator*(const vec2& a, float b)
	{
		return vec2(xs("(% * %)", a.ExtendedName(), b));
	}

	inline void operator*=(vec2& a, float b)
	{
		a = a * b;
	}

	inline vec2 operator/(const vec2& a, float b)
	{
		return vec2(xs("(% / %)", a.ExtendedName(), b));
	}

	inline void operator/=(vec2& a, float b)
	{
		a = a / b;
	}

	// vec3 operators
	template <typename vec_detail>
	inline generic_vec3<vec_detail> operator+(const generic_vec3<vec_detail>& a, const generic_vec3<vec_detail>& b)
	{
		return generic_vec3<vec_detail>(xs("(% + %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename vec_detail>
	inline void operator+=(generic_vec3<vec_detail>& a, const generic_vec3<vec_detail>& b)
	{
		a = a + b;
	}

	template <typename vec_detail>
	inline generic_vec3<vec_detail> operator-(const generic_vec3<vec_detail>& a, const generic_vec3<vec_detail>& b)
	{
		return generic_vec3<vec_detail>(xs("(% - %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename vec_detail>
	inline void operator-=(generic_vec3<vec_detail>& a, const generic_vec3<vec_detail>& b)
	{
		a = a - b;
	}

	template <typename vec_detail>
	inline generic_vec3<vec_detail> operator*(const generic_vec3<vec_detail>& a, const generic_vec3<vec_detail>& b)
	{
		return generic_vec3<vec_detail>(xs("(% * %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename vec_detail>
	inline void operator*=(generic_vec3<vec_detail>& a, const generic_vec3<vec_detail>& b)
	{
		a = a * b;
	}

	template <typename vec_detail>
	inline generic_vec3<vec_detail> operator/(const generic_vec3<vec_detail>& a, const generic_vec3<vec_detail>& b)
	{
		return generic_vec3<vec_detail>(xs("(% / %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename vec_detail>
	inline void operator/=(generic_vec3<vec_detail>& a, const generic_vec3<vec_detail>& b)
	{
		a = a / b;
	}

	template <typename vec_detail>
	inline generic_vec3<vec_detail> operator*(const generic_vec3<vec_detail>& a, const Float& b)
	{
		return generic_vec3<vec_detail>(xs("(% * %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename vec_detail>
	inline generic_vec3<vec_detail> operator/(const generic_vec3<vec_detail>& a, const Float& b)
	{
		return generic_vec3<vec_detail>(xs("(% / %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename vec_detail>
	inline generic_vec3<vec_detail> operator*(const generic_vec3<vec_detail>& a, float b)
	{
		return generic_vec3<vec_detail>(xs("(% * %)", a.ExtendedName(), b));
	}

	template <typename vec_detail>
	inline void operator*=(generic_vec3<vec_detail>& a, const Float& b)
	{
		a = a * b;
	}

	template <typename vec_detail>
	inline void operator*=(generic_vec3<vec_detail>& a, float b)
	{
		a = a * b;
	}

	template <typename vec_detail>
	inline generic_vec3<vec_detail> operator/(const generic_vec3<vec_detail>& a, float b)
	{
		return generic_vec3<vec_detail>(xs("(% / %)", a.ExtendedName(), b));
	}

	template <typename vec_detail>
	inline void operator/=(generic_vec3<vec_detail>& a, float b)
	{
		a = a / b;
	}

	// generic_vec4<Detail> operators
	template <typename vec_detail>
	inline generic_vec4<vec_detail> operator+(const generic_vec4<vec_detail>& a, const generic_vec4<vec_detail>& b)
	{
		return generic_vec4<vec_detail>(xs("(% + %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename vec_detail>
	inline void operator+=(generic_vec4<vec_detail>& a, const generic_vec4<vec_detail>& b)
	{
		a = a + b;
	}

	template <typename vec_detail>
	inline generic_vec4<vec_detail> operator-(const generic_vec4<vec_detail>& a, const generic_vec4<vec_detail>& b)
	{
		return generic_vec4<vec_detail>(xs("(% - %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename vec_detail>
	inline void operator-=(generic_vec4<vec_detail>& a, const generic_vec4<vec_detail>& b)
	{
		a = a - b;
	}

	template <typename vec_detail>
	inline generic_vec4<vec_detail> operator*(const generic_vec4<vec_detail>& a, const generic_vec4<vec_detail>& b)
	{
		return generic_vec4<vec_detail>(xs("(% * %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename vec_detail>
	inline void operator*=(generic_vec4<vec_detail>& a, const generic_vec4<vec_detail>& b)
	{
		a = a * b;
	}

	template <typename vec_detail>
	inline generic_vec4<vec_detail> operator/(const generic_vec4<vec_detail>& a, const generic_vec4<vec_detail>& b)
	{
		return generic_vec4<vec_detail>(xs("(% / %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename vec_detail>
	inline void operator/=(generic_vec4<vec_detail>& a, const generic_vec4<vec_detail>& b)
	{
		a = a / b;
	}

	template <typename vec_detail>
	inline generic_vec4<vec_detail> operator*(const generic_vec4<vec_detail>& a, const Float& b)
	{
		return generic_vec4<vec_detail>(xs("(% * %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename vec_detail>
	inline generic_vec4<vec_detail> operator/(const generic_vec4<vec_detail>& a, const Float& b)
	{
		return generic_vec4<vec_detail>(xs("(% / %)", a.ExtendedName(), b.ExtendedName()));
	}

	template <typename vec_detail>
	inline generic_vec4<vec_detail> operator*(const generic_vec4<vec_detail>& a, float b)
	{
		return generic_vec4<vec_detail>(xs("(% * %)", a.ExtendedName(), b));
	}

	template <typename vec_detail>
	inline void operator*=(generic_vec4<vec_detail>& a, const Float& b)
	{
		a = a * b;
	}

	template <typename vec_detail>
	inline void operator*=(generic_vec4<vec_detail>& a, float b)
	{
		a = a * b;
	}

	template <typename vec_detail>
	inline generic_vec4<vec_detail> operator/(const generic_vec4<vec_detail>& a, float b)
	{
		return generic_vec4<vec_detail>(xs("(% / %)", a.ExtendedName(), b));
	}

	template <typename vec_detail>
	inline void operator/=(generic_vec4<vec_detail>& a, float b)
	{
		a = a / b;
	}
	
	// mat3 operators
	template <typename vec_detail>
	inline generic_vec3<vec_detail> operator*(const mat3& m, const generic_vec3<vec_detail>& v)
	{
		return generic_vec3<vec_detail>(xs("(% * %)", m.ExtendedName(), v.ExtendedName()));
	}

	// mat4 operators
	template <typename vec_detail>
	inline generic_vec4<vec_detail> operator*(const mat4& m, const generic_vec4<vec_detail>& v)
	{
		return generic_vec4<vec_detail>(xs("(% * %)", m.ExtendedName(), v.ExtendedName()));
	}

}

#endif
