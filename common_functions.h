#ifndef __GLSLPP_COMMON_FUNCTIONS_H
#define __GLSLPP_COMMON_FUNCTIONS_H

namespace GLSLPP
{

	// Common Functions(8.3)

	template <typename T>
	inline typename AbstractType<T>::type abs(const T& x)
	{
		return xs("abs(%)", x);
	}

	template <typename T>
	inline typename AbstractType<T>::type sign(const T& x)
	{
		return xs("sign(%)", x);
	}

	template <typename T>
	inline typename AbstractType<T>::type floor(const T& x)
	{
		return xs("floor(%)", x);
	}

	template <typename T>
	inline typename AbstractType<T>::type trunc(const T& x)
	{
		return xs("trunc(%)", x);
	}

	template <typename T>
	inline typename AbstractType<T>::type round(const T& x)
	{
		return xs("round(%)", x);
	}

	template <typename T>
	inline typename AbstractType<T>::type roundEven(const T& x)
	{
		return xs("roundEven(%)", x);
	}

	template <typename T>
	inline typename AbstractType<T>::type ceil(const T& x)
	{
		return xs("ceil(%)", x);
	}

	template <typename T>
	inline typename AbstractType<T>::type fract(const T& x)
	{
		return xs("fract(%)", x);
	}

	template <typename T>
	inline typename AbstractType<T>::type mod(const T& x, const T& y)
	{
		return xs("mod(%, %)", x, y);
	}

	template <typename T>
	inline typename AbstractType<T>::type modf(const T& x, const T& i)
	{
		return xs("modf(%, %)", x, i);
	}

	template <typename T>
	inline typename AbstractType<T>::type clamp(const T& x, const T& minVal, const T& maxVal)
	{
		return xs("clamp(%, %, %)", x, minVal, maxVal);
	}

	template <typename T>
	inline typename AbstractType<T>::type clamp(const T& genType, float minVal, float maxVal)
	{
		return xs("clamp(%, %, %)", x, minVal, maxVal);
	}

	template <typename T>
	inline typename AbstractType<T>::type min(const T& x, const T& y)
	{
		return xs("min(%, %)", x, y);
	}

	template <typename T>
	inline typename AbstractType<T>::type max(const T& x, const T& y)
	{
		return xs("max(%, %)", x, y);
	}

	template <typename T>
	inline typename AbstractType<T>::type mix(const T& x, const T& y, const T& a)
	{
		return xs("mix(%, %, %)", x, y, a);
	}

	template <typename T>
	inline typename AbstractType<T>::type step(const T& edge, const T& x)
	{
		return xs("step(%, %)", edge, x);
	}

	template <typename T>
	inline typename AbstractType<T>::type smoothstep(const T& edge0, const T& edge1, const T& x)
	{
		return xs("smoothstep(%, %, %)", edge0, edge1, x);
	}

	template <typename T>
	inline typename AbstractType<T>::type isnan(const T& x)
	{
		return xs("isnan(%)", x);
	}

	template <typename T>
	inline typename AbstractType<T>::type isinf(const T& x)
	{
		return xs("isinf(%)", x);
	}

	inline Int floatBitsToInt(const Float& x)
	{
		return xs("floatBitsToInt(%)", x);
	}

	inline Uint floatBitsToUint(const Float& x)
	{
		return xs("floatBitsToUint(%)", x);
	}

	inline Float intBitsToFloat(const Int& x)
	{
		return xs("intBitsToFloat(%)", x);
	}

	inline Float uintBitsToFloat(const Uint& x)
	{
		return xs("uintBitsToFloat(%)", x);
	}

	template <typename T>
	inline typename AbstractType<T>::type fma(const T& a, const T& b, const T& c)
	{
		return xs("fma(%, %, %)", a, b, c);
	}

	template <typename T>
	inline typename AbstractType<T>::type frexp(const T& x, const T& exp)
	{
		return xs("frexp(%, %)", x, exp);
	}

	template <typename T>
	inline typename AbstractType<T>::type ldexp(const T& x, const T& exp)
	{
		return xs("ldexp(%, %)", x, exp);
	}

}

#endif
