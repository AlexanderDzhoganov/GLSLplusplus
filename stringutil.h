#ifndef __GLSLPP_STRINGUTIL_H
#define __GLSLPP_STRINGUTIL_H

template <typename T>
inline std::string Flatten(const T& t)
{
	return t.Definition();
}

template <>
inline std::string Flatten<bool>(const bool& t)
{
	std::stringstream stream;
	stream << t;
	return stream.str();
}

template <>
inline std::string Flatten<int>(const int& t)
{
	std::stringstream stream;
	stream << t;
	return stream.str();
}

template <>
inline std::string Flatten<unsigned int>(const unsigned int& t)
{
	std::stringstream stream;
	stream << t;
	return stream.str();
}

template <>
inline std::string Flatten<float>(const float& t)
{
	std::stringstream stream;
	stream << std::scientific << t;
	return stream.str();
}

template <>
inline std::string Flatten<double>(const double& t)
{
	std::stringstream stream;
	stream << std::scientific << t;
	return stream.str();
}

void xs(std::string& result, const char* s);

template<typename T, typename... Args>
inline void xs(std::string& result, const char* s, T value, Args... args)
{
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%')
			{
				++s;
			}
			else
			{
				std::stringstream stream;
				stream << Flatten(value);
				result += stream.str();
				xs(result, s + 1, args...); // call even when *s == 0 to detect extra arguments
				return;
			}
		}
		result += *s++;
	}
	throw std::logic_error("extra arguments provided to printf");
}

template<typename... Args>
inline void xs(std::string& result, const char* s, std::string value, Args... args)
{
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%')
			{
				++s;
			}
			else
			{
				std::stringstream stream;
				stream << value;
				result += stream.str();
				xs(result, s + 1, args...); // call even when *s == 0 to detect extra arguments
				return;
			}
		}
		result += *s++;
	}
	throw std::logic_error("extra arguments provided to printf");
}

template<typename... Args>
inline void xs(std::string& result, const char* s, const char* value, Args... args)
{
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%')
			{
				++s;
			}
			else
			{
				std::stringstream stream;
				stream << value;
				result += stream.str();
				xs(result, s + 1, args...); // call even when *s == 0 to detect extra arguments
				return;
			}
		}
		result += *s++;
	}
	throw std::logic_error("extra arguments provided to printf");
}

template<typename... Args>
inline std::string xs(const char* s, Args... args)
{
	std::string buf;
	xs(buf, s, args...);
	return buf;
}

inline void xs(std::string& result, const char* s)
{
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%')
			{
				++s;
			}
			else
			{
				throw std::runtime_error("invalid format string: missing arguments");
			}
		}

		result += *s++;
	}
}

#endif
