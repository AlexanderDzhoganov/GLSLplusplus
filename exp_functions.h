#ifndef __GLSLPP_EXP_FUNCTIONS_H
#define __GLSLPP_EXP_FUNCTIONS_H

namespace GLSLPP
{

	//Exponential Functions(8.2)

	// genType pow (genType x, genType y)
	template <typename detail>
	inline GenType<detail> pow(const GenType<detail>& x, const GenType<detail>& y)
	{
		return GenType<detail>(xs("pow(%, %)", x.ExtendedName(), y.ExtendedName()));
	}

	inline Float pow(const Float& x, float y)
	{
		return Float(xs("pow(%, %)", x.ExtendedName(), y));
	}

	inline Float pow(float x, const Float& y)
	{
		return Float(xs("pow(%, %)", x, y.ExtendedName()));
	}

	inline Float pow(float x, float y)
	{
		return Float(xs("pow(%, %)", x, y));
	}

	inline Double pow(const Double& x, double y)
	{
		return Double(xs("pow(%, %)", x.ExtendedName(), y));
	}

	inline Double pow(double x, const Double& y)
	{
		return Double(xs("pow(%, %)", x, y.ExtendedName()));
	}

	inline Double pow(double x, double y)
	{
		return Double(xs("pow(%, %)", x, y));
	}

	// genType exp (genType x)
	template <typename detail>
	inline GenType<detail> exp(const GenType<detail>& x)
	{
		return GenType<detail>(xs("exp(%)", x.ExtendedName()));
	}

	inline Float exp(float x)
	{
		return Float(xs("exp(%)", x));
	}

	inline Double exp(double x)
	{
		return Double(xs("exp(%)", x));
	}

	// genType log (genType x) 
	template <typename detail>
	inline GenType<detail> log(const GenType<detail>& x)
	{
		return GenType<detail>(xs("log(%)", x.ExtendedName()));
	}

	inline Float log(float x)
	{
		return Float(xs("log(%)", x));
	}

	inline Double log(double x)
	{
		return Double(xs("log(%)", x));
	}

	// genType exp2 (genType x) 
	template <typename detail>
	inline GenType<detail> exp2(const GenType<detail>& x)
	{
		return GenType<detail>(xs("exp2(%)", x.ExtendedName()));
	}

	inline Float exp2(float x)
	{
		return Float(xs("exp2(%)", x));
	}

	inline Double exp2(double x)
	{
		return Double(xs("exp2(%)", x));
	}

	// genType log2 (genType x)
	template <typename detail>
	inline GenType<detail> log2(const GenType<detail>& x)
	{
		return GenType<detail>(xs("log2(%)", x.ExtendedName()));
	}

	inline Float log2(float x)
	{
		return Float(xs("log2(%)", x));
	}

	// genType sqrt (genType x)
	template <typename detail>
	inline GenType<detail> sqrt(const GenType<detail>& x)
	{
		return GenType<detail>(xs("sqrt(%)", x.ExtendedName()));
	}

	inline Float sqrt(float x)
	{
		return Float(xs("sqrt(%)", x));
	}

	inline Double sqrt(double x)
	{
		return Double(xs("sqrt(%)", x));
	}

	// genType inversesqrt (genType x)
	template <typename detail>
	inline GenType<detail> inversesqrt(const GenType<detail>& x)
	{
		return GenType<detail>(xs("inversesqrt(%)", x.ExtendedName()));
	}

	inline Float inversesqrt(float x)
	{
		return Float(xs("inversesqrt(%)", x));
	}

}

#endif
