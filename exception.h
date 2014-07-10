#ifndef __GLSLPP_EXCEPTION_H
#define __GLSLPP_EXCEPTION_H

namespace GLSLPP
{

	class InvalidVariableDeclaration : public std::exception
	{
	};

	class UseBeforeAssignment : public std::exception
	{
	};

	class ArithmeticOnBuiltIn : public std::exception
	{
	};

	class InvalidLayoutLocation : public std::exception
	{
	};

	class OutOfBoundsAccess : public std::exception
	{
	};

}

#endif
