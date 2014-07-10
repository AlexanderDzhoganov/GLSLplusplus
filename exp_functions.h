#ifndef __GLSLPP_EXP_FUNCTIONS_H
#define __GLSLPP_EXP_FUNCTIONS_H

namespace GLSLPP
{

	//Exponential Functions(8.2)

	// genType pow (genType x, genType y)
	template <typename T>
	inline typename AbstractType<T>::type pow(const T& x, const T& y)
	{
		return xs("pow(%, %)", x, y);
	}

	// genType exp (genType x)
	template <typename T>
	inline typename AbstractType<T>::type exp(const T& x)
	{
		return xs("exp(%)", x);
	}

	// genType log (genType x) 
	template <typename T>
	inline typename AbstractType<T>::type log(const T& x)
	{
		return xs("log(%)", x);
	}

	// genType exp2 (genType x) 
	template <typename T>
	inline typename AbstractType<T>::type exp2(const T& x)
	{
		return xs("exp2(%)", x);
	}

	// genType log2 (genType x)
	template <typename T>
	inline typename AbstractType<T>::type log2(const T& x)
	{
		return xs("log2(%)", x);
	}

	// genType sqrt (genType x)
	template <typename T>
	inline typename AbstractType<T>::type sqrt(const T& x)
	{
		return xs("sqrt(%)", x);
	}

	// genType inversesqrt (genType x)
	template <typename T>
	inline typename AbstractType<T>::type inversesqrt(const T& x)
	{
		return xs("inversesqrt(%)", x);
	}

}

#endif
