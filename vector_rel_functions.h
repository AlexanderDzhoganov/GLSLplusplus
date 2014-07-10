#ifndef __GLSLPPP_VECTOR_REL_FUNCTIONS_H
#define __GLSLPPP_VECTOR_REL_FUNCTIONS_H

namespace GLSLPP
{

	// bvec lessThan (vec x, vec y)
	template <typename T>
	inline bvec2 lessThan(const T& x, const T& y)
	{
		return xs("lessThan(%, %)", x, y);
	}

	template <typename T>
	inline bvec3 lessThan(const T& x, const T& y)
	{
		return xs("lessThan(%, %)", x, y);
	}

	template <typename T>
	inline bvec4 lessThan(const T& x, const T& y)
	{
		return xs("lessThan(%, %)", x, y);
	}

	// bvec lessThanEqual(vec x, vec y)
		template <typename T>
	inline bvec2 lessThanEqual(const T& x, const T& y)
	{
		return xs("lessThanEqual(%, %)", x, y);
	}

	template <typename T>
	inline bvec3 lessThanEqual(const T& x, const T& y)
	{
		return xs("lessThanEqual(%, %)", x, y);
	}

	template <typename T>
	inline bvec4 lessThanEqual(const T& x, const T& y)
	{
		return xs("lessThanEqual(%, %)", x, y);
	}

	// bvec greaterThan(vec x, vec y)
	template <typename T>
	inline bvec2 greaterThan(const T& x, const T& y)
	{
		return xs("greaterThan(%, %)", x, y);
	}

	template <typename T>
	inline bvec3 greaterThan(const T& x, const T& y)
	{
		return xs("greaterThan(%, %)", x, y);
	}

	template <typename T>
	inline bvec4 greaterThan(const T& x, const T& y)
	{
		return xs("greaterThan(%, %)", x, y);
	}

	// bvec greaterThanEqual(vec x, vec y)
	template <typename T>
	inline bvec2 greaterThanEqual(const T& x, const T& y)
	{
		return xs("greaterThanEqual(%, %)", x, y);
	}

	template <typename T>
	inline bvec3 greaterThanEqual(const T& x, const T& y)
	{
		return xs("greaterThanEqual(%, %)", x, y);
	}

	template <typename T>
	inline bvec4 greaterThanEqual(const T& x, const T& y)
	{
		return xs("greaterThanEqual(%, %)", x, y);
	}

	// bvec equal(vec x, vec y)
	template <typename T>
	inline bvec2 equal(const T& x, const T& y)
	{
		return xs("equal(%, %)", x, y);
	}

	template <typename T>
	inline bvec3 equal(const T& x, const T& y)
	{
		return xs("equal(%, %)", x, y);
	}

	template <typename T>
	inline bvec4 equal(const T& x, const T& y)
	{
		return xs("equal(%, %)", x, y);
	}

	// bvec notEqual(vec x, vec y)
	template <typename T>
	inline bvec2 notEqual(const T& x, const T& y)
	{
		return xs("notEqual(%, %)", x, y);
	}

	template <typename T>
	inline bvec3 notEqual(const T& x, const T& y)
	{
		return xs("notEqual(%, %)", x, y);
	}

	template <typename T>
	inline bvec4 notEqual(const T& x, const T& y)
	{
		return xs("notEqual(%, %)", x, y);
	}

	// bvec any(vec x, vec y)
	template <typename T>
	inline bool any(const T& x, const T& y)
	{
		return xs("any(%, %)", x, y);
	}

	template <typename T>
	inline bool any(const T& x, const T& y)
	{
		return xs("any(%, %)", x, y);
	}

	template <typename T>
	inline bool any(const T& x, const T& y)
	{
		return xs("any(%, %)", x, y);
	}

	// bvec all(vec x, vec y)
	template <typename T>
	inline bool all(const T& x, const T& y)
	{
		return xs("all(%, %)", x, y);
	}

	template <typename T>
	inline bool all(const T& x, const T& y)
	{
		return xs("all(%, %)", x, y);
	}

	template <typename T>
	inline bool all(const T& x, const T& y)
	{
		return xs("all(%, %)", x, y);
	}

	// bvec not(vec x, vec y)
	template <typename T>
	inline bvec2 not(const T& x, const T& y)
	{
		return xs("not(%, %)", x, y);
	}

	template <typename T>
	inline bvec3 not(const T& x, const T& y)
	{
		return xs("not(%, %)", x, y);
	}

	template <typename T>
	inline bvec4 not(const T& x, const T& y)
	{
		return xs("not(%, %)", x, y);
	}
}

#endif
