#ifndef __GLSLPP_TRIG_FUNCTIONS_H
#define __GLSLPP_TRIG_FUNCTIONS_H

namespace GLSLPP
{

	// Angle and Trigonometry Functions(8.1)

	// genType radians (genType degrees)
	template <typename T>
	inline typename AbstractType<T>::type radians(const T& degrees)
	{
		return xs("radians(%)", degrees);
	}

	// genType degrees (genType radians)
	template <typename T>
	inline typename AbstractType<T>::type degrees(const T radians)
	{
		return xs("degrees(%)", radians);
	}

	// genType sin (genType angle)
	template <typename T>
	inline typename AbstractType<T>::type sin(const T& angle)
	{
		return GenType<detail>(xs("sin(%)", angle));
	}

	// genType cos (genType angle)
	template <typename T>
	inline typename AbstractType<T>::type cos(const T& angle)
	{
		return GenType<detail>(xs("cos(%)", angle));
	}

	// genType tan (genType angle) 
	template <typename T>
	inline typename AbstractType<T>::type tan(const T& angle)
	{
		return GenType<detail>(xs("tan(%)", angle));
	}

	// genType asin (genType x) 
	template <typename T>
	inline typename AbstractType<T>::type asin(const T& x)
	{
		return GenType<detail>(xs("asin(%)", x));
	}

	// genType acos (genType x)
	template <typename T>
	inline typename AbstractType<T>::type acos(const T& x)
	{
		return GenType<detail>(xs("acos(%)", x));
	}

	// genType atan (genType y, genType x) 
	template <typename T>
	inline typename AbstractType<T>::type atan(const T& y, const T& x)
	{
		return GenType<detail>(xs("atan(%, %)", y, x));
	}

	// genType atan (genType y_over_x) 
	template <typename T>
	inline typename AbstractType<T>::type atan(const T& y_over_x)
	{
		return GenType<detail>(xs("atan(%)", y_over_x));
	}

	// genType sinh (genType x) 
	template <typename T>
	inline typename AbstractType<T>::type sinh(const T& x)
	{
		return GenType<detail>(xs("sinh(%)", x));
	}

	// genType cosh (genType x)
	template <typename T>
	inline typename AbstractType<T>::type cosh(const T& x)
	{
		return GenType<detail>(xs("cosh(%)", x));
	}

	// genType tanh (genType x) 
	template <typename T>
	inline typename AbstractType<T>::type tanh(const T& x)
	{
		return GenType<detail>(xs("tanh(%)", x));
	}

	// genType asinh (genType x) 
	template <typename T>
	inline typename AbstractType<T>::type asinh(const T& x)
	{
		return GenType<detail>(xs("asinh(%)", x));
	}

	// genType acosh (genType x)
	template <typename T>
	inline typename AbstractType<T>::type acosh(const T& x)
	{
		return GenType<detail>(xs("acosh(%)", x));
	}

	// genType atanh (genType x) 
	template <typename T>
	inline typename AbstractType<T>::type atanh(const T& x)
	{
		return GenType<detail>(xs("atanh(%)", x));
	}

}

#endif
