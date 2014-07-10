#ifndef __GLSLPP_TRIG_FUNCTIONS_H
#define __GLSLPP_TRIG_FUNCTIONS_H

namespace GLSLPP
{

	// Angle and Trigonometry Functions(8.1)

	// genType radians (genType degrees)
	template <typename detail>
	inline GenType<detail> radians(const GenType<detail>& degrees)
	{
		return GenType<detail>(xs("radians(%)", degrees.Definition()));
	}

	inline Float radians(float degrees)
	{
		return Float(xs("radians(%)", degrees));
	}

	inline Double radians(double degrees)
	{
		return Double(xs("radians(%)", degrees));
	}

	// genType degrees (genType radians)
	template <typename detail>
	inline GenType<detail> degrees(const GenType<detail>& radians)
	{
		return GenType<detail>(xs("degrees(%)", radians.Definition()));
	}

	inline Float degrees(float radians)
	{
		return Float(xs("degrees(%)", radians));
	}

	inline Double degrees(double radians)
	{
		return Double(xs("degrees(%)", radians));
	}

	// genType sin (genType angle)
	template <typename detail>
	inline GenType<detail> sin(const GenType<detail>& angle)
	{
		return GenType<detail>(xs("sin(%)", angle.Definition()));
	}

	inline Float sin(float angle)
	{
		return Float(xs("sin(%)", angle));
	}

	inline Double sin(double angle)
	{
		return Double(xs("sin(%)", angle));
	}

	// genType cos (genType angle)
	template <typename detail>
	inline GenType<detail> cos(const GenType<detail>& angle)
	{
		return GenType<detail>(xs("cos(%)", angle.Definition()));
	}

	inline Float cos(float angle)
	{
		return Float(xs("cos(%)", angle));
	}

	inline Double cos(double angle)
	{
		return Double(xs("cos(%)", angle));
	}

	// genType tan (genType angle) 
	template <typename detail>
	inline GenType<detail> tan(const GenType<detail>& angle)
	{
		return GenType<detail>(xs("tan(%)", angle.Definition()));
	}

	inline Float tan(float angle)
	{
		return Float(xs("tan(%)", angle));
	}

	inline Double tan(double angle)
	{
		return Double(xs("tan(%)", angle));
	}

	// genType asin (genType x) 
	template <typename detail>
	inline GenType<detail> asin(const GenType<detail>& x)
	{
		return GenType<detail>(xs("asin(%)", x.Definition()));
	}

	inline Float asin(float x)
	{
		return Float(xs("asin(%)", x));
	}

	inline Double asin(double x)
	{
		return Double(xs("asin(%)", x));
	}

	// genType acos (genType x)
	template <typename detail>
	inline GenType<detail> acos(const GenType<detail>& x)
	{
		return GenType<detail>(xs("acos(%)", x.Definition()));
	}

	inline Float acos(float x)
	{
		return Float(xs("acos(%)", x));
	}

	inline Double acos(double x)
	{
		return Double(xs("acos(%)", x));
	}

	// genType atan (genType y, genType x) 
	template <typename detail>
	inline GenType<detail> atan(const GenType<detail>& y, const GenType<detail>& x)
	{
		return GenType<detail>(xs("atan(%, %)", y.Definition(), x.Definition()));
	}

	inline Float atan(float y, const Float& x)
	{
		return Float(xs("atan(%, %)", y, x.Definition()));
	}

	inline Float atan(const Float& y, float x)
	{
		return Float(xs("atan(%, %)", y.Definition(), x));
	}

	inline Float atan(float y, float x)
	{
		return Float(xs("atan(%, %)", y, x));
	}

	inline Double atan(double y, const Double& x)
	{
		return Double(xs("atan(%, %)", y, x.Definition()));
	}

	inline Double atan(const Double& y, double x)
	{
		return Double(xs("atan(%, %)", y.Definition(), x));
	}

	inline Double atan(double y, double x)
	{
		return Double(xs("atan(%, %)", y, x));
	}

	// genType atan (genType y_over_x) 
	template <typename detail>
	inline GenType<detail> atan(const GenType<detail>& y_over_x)
	{
		return GenType<detail>(xs("atan(%)", y_over_x.Definition()));
	}

	inline Float atan(float y_over_x)
	{
		return Float(xs("atan(%)", y_over_x));
	}

	inline Double atan(double y_over_x)
	{
		return Double(xs("atan(%)", y_over_x));
	}

	// genType sinh (genType x) 
	template <typename detail>
	inline GenType<detail> sinh(const GenType<detail>& x)
	{
		return GenType<detail>(xs("sinh(%)", x.Definition()));
	}

	inline Float sinh(float x)
	{
		return Float(xs("sinh(%)", x));
	}

	inline Double sinh(double x)
	{
		return Double(xs("sinh(%)", x));
	}

	// genType cosh (genType x)
	template <typename detail>
	inline GenType<detail> cosh(const GenType<detail>& x)
	{
		return GenType<detail>(xs("cosh(%)", x.Definition()));
	}

	inline Float cosh(float x)
	{
		return Float(xs("cosh(%)", x));
	}

	inline Double cosh(double x)
	{
		return Double(xs("cosh(%)", x));
	}

	// genType tanh (genType x) 
	template <typename detail>
	inline GenType<detail> tanh(const GenType<detail>& x)
	{
		return GenType<detail>(xs("tanh(%)", x.Definition()));
	}

	inline Float tanh(float x)
	{
		return Float(xs("tanh(%)", x));
	}

	inline Double tanh(double x)
	{
		return Double(xs("tanh(%)", x));
	}

	// genType asinh (genType x) 
	template <typename detail>
	inline GenType<detail> asinh(const GenType<detail>& x)
	{
		return GenType<detail>(xs("asinh(%)", x.Definition()));
	}

	inline Float asinh(float x)
	{
		return Float(xs("asinh(%)", x));
	}

	inline Double asinh(double x)
	{
		return Double(xs("asinh(%)", x));
	}

	// genType acosh (genType x)
	template <typename detail>
	inline GenType<detail> acosh(const GenType<detail>& x)
	{
		return GenType<detail>(xs("acosh(%)", x.Definition()));
	}

	inline Float acosh(float x)
	{
		return Float(xs("acosh(%)", x));
	}

	inline Double acosh(double x)
	{
		return Double(xs("acosh(%)", x));
	}

	// genType atanh (genType x) 
	template <typename detail>
	inline GenType<detail> atanh(const GenType<detail>& x)
	{
		return GenType<detail>(xs("atanh(%)", x.Definition()));
	}

	inline Float atanh(float x)
	{
		return Float(xs("atanh(%)", x));
	}

	inline Double atanh(double x)
	{
		return Double(xs("atanh(%)", x));
	}

}

#endif
