#ifndef __GLSLPP_COMMON_FUNCTIONS_H
#define __GLSLPP_COMMON_FUNCTIONS_H

namespace GLSLPP
{

	// Common Functions(8.3)

	template <typename T>
	inline T abs(const T& x)
	{
		return T(xs("abs(%)", x.Definition()));
	}

	template <typename T>
	inline T sign(const T& x)
	{
		return T(xs("sign(%)", x.Definition()));
	}

	template <typename T>
	inline T floor(const T& x)
	{
		return T(xs("floor(%)", x.Definition()));
	}

	template <typename T>
	inline T trunc(const T& x)
	{
		return T(xs("trunc(%)", x.Definition()));
	}

	template <typename T>
	inline T round(const T& x)
	{
		return T(xs("round(%)", x.Definition()));
	}

	template <typename T>
	inline T roundEven(const T& x)
	{
		return T(xs("roundEven(%)", x.Definition()));
	}

	template <typename T>
	inline T ceil(const T& x)
	{
		return T(xs("ceil(%)", x.Definition()));
	}

	template <typename T>
	inline T fract(const T& x)
	{
		return T(xs("fract(%)", x.Definition()));
	}

	template <typename T>
	inline T mod(const T& x, const T& y)
	{
		return T(xs("mod(%, %)", x.Definition(), y.Definition()));
	}

	template <typename T>
	inline T modf(const T& x, const T& i)
	{
		return T(xs("modf(%, %)", x.Definition(), i.Definition()));
	}

	template <typename T>
	inline T clamp(const T& x, const T& minVal, const T& maxVal)
	{
		return T(xs("clamp(%, %, %)", x.Definition(), minVal.Definition(), maxVal.Definition()));
	}

	template <typename T>
	inline T clamp(const T& genType, float minVal, float maxVal)
	{
		return T(xs("clamp(%, %, %)", x.Definition(), minVal, maxVal));
	}

	template <typename T>
	inline T min(const T& x, const T& y)
	{
		return T(xs("min(%, %)", x.Definition(), y.Definition()));
	}

	template <typename T>
	inline T max(const T& x, const T& y)
	{
		return T(xs("max(%, %)", x.Definition(), y.Definition()));
	}

	template <typename T>
	inline T mix(const T& x, const T& y, const T& a)
	{
		return T(xs("mix(%, %, %)", x.Definition(), y.Definition(), a.Definition()));
	}

	template <typename T>
	inline T step(const T& edge, const T& x)
	{
		return T(xs("step(%, %)", edge.Definition(), x.Definition()));
	}

	template <typename T>
	inline T smoothstep(const T& edge0, const T& edge1, const T& x)
	{
		return T(xs("smoothstep(%, %, %)", edge0.Definition(), edge1.Definition(), x.Definition()));
	}

	template <typename T>
	inline T isnan(const T& x)
	{
		return T(xs("isnan(%)", x.Definition()));
	}

	template <typename T>
	inline T isinf(const T& x)
	{
		return T(xs("isinf(%)", x.Definition()));
	}

	inline Int floatBitsToInt(const Float& x)
	{
		return Int(xs("floatBitsToInt(%)", x.Definition()));
	}

	inline Uint floatBitsToUint(const Float& x)
	{
		return Uint(xs("floatBitsToUint(%)", x.Definition()));
	}

	inline Float intBitsToFloat(const Int& x)
	{
		return Float(xs("intBitsToFloat(%)", x.Definition()));
	}

	inline Float uintBitsToFloat(const Uint& x)
	{
		return Float(xs("uintBitsToFloat(%)", x.Definition()));
	}

	template <typename T>
	inline T fma(const T& a, const T& b, const T& c)
	{
		return T(xs("fma(%, %, %)", a.Definition(), b.Definition(), c.Definition()));
	}

	template <typename T>
	inline T frexp(const T& x, const T& exp)
	{
		return T(xs("frexp(%, %)", x.Definition(), exp.Definition()));
	}

	template <typename T>
	inline T ldexp(const T& x, const T& exp)
	{
		return T(xs("ldexp(%, %)", x.Definition(), exp.Definition()));
	}

}

#endif
