#ifndef __GLSLPP_GEOM_FUNCTIONS_H
#define __GLSLPP_GEOM_FUNCTIONS_H

namespace GLSLPP
{

	// Geometric Functions(8.4)

	template <typename T>
	inline typename T::t_abstract length(const T& x)
	{
		return xs("length(%)", x);
	}

	template <typename T>
	inline typename T::t_abstract distance(const T& p0, const T& p1)
	{
		return xs("distance(%, %)", p0, p1);
	}

	template <typename T>
	inline typename T::t_abstract dot(const T& x, const T& y)
	{
		return xs("dot(%, %)", x, y);
	}

	template <typename detail>
	inline generic_vec3<detail> cross(const generic_vec3<detail>& x, const generic_vec3<detail>& y)
	{
		return generic_vec3<detail>(xs("cross(%, %)", x, y));
	}

	template <typename T>
	inline T normalize(const T& x)
	{
		return xs("normalize(%)", x);
	}

	template <typename detail>
	inline vec4 ftransform()
	{
		return vec4("ftransform()");
	}

	template <typename T>
	inline typename T faceforward(const T& N, const T& I, const T& Nref)
	{
		return xs("faceforward(%, %, %)", N, I, Nref);
	}

	template <typename T>
	inline typename T reflect(const T& I, const T& N)
	{
		return xs("reflect(%, %)", I, N);
	}

	template <typename T, typename F>
	inline typename T refract(const T& I, const T& N, const F& eta)
	{
		return xs("refract(%, %, %)", I, N, eta);
	}

}

#endif
