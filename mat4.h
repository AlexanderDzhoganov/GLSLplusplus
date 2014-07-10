#ifndef __GLSLPP_MAT4_H
#define __GLSLPP_MAT4_H

namespace GLSLPP
{

	class mat4 : public Type
	{

		public:
		mat4() :
			Type(Variable, "mat4", currentProgram->GenerateName())
		{
		}

		explicit mat4(VariableType type) :
			Type(type, "mat4", currentProgram->GenerateName())
		{
		}

		mat4(VariableType type, const std::string& name) :
			Type(type, "mat4", name)
		{
		}

		vec4 operator[] (size_t i) const
		{
			if (i > 15)
			{
				throw OutOfBoundsAccess();
			}

			return vec4(xs("%[%]", Definition(), i));
		}

		vec4 operator[] (const Int& i) const
		{
			return vec4(xs("%[%]", Definition(), i.Definition()));
		}

		vec4 operator[] (const Uint& i) const
		{
			return vec4(xs("%[%]", Definition(), i.Definition()));
		}

		std::string Definition() const
		{
			if (GetType() == Temporary)
			{
				return m_TemporaryInitialization;
			}

			return xs("%", GetName());
		}

		private:
		bool m_Declared = true;
		std::string m_TemporaryInitialization;

	};

	class dmat4 : public Type
	{

		public:
		dmat4() :
			Type(Variable, "dmat4", currentProgram->GenerateName())
		{
		}

		explicit dmat4(VariableType type) :
			Type(type, "dmat4", currentProgram->GenerateName())
		{
		}

		dmat4(VariableType type, const std::string& name) :
			Type(type, "dmat4", name)
		{
		}

		dvec4 operator[] (size_t i) const
		{
			return vec4(xs("%[%]", Definition(), i));
		}

		dvec4 operator[] (const Int& i) const
		{
			return vec4(xs("%[%]", Definition(), i.Definition()));
		}

		dvec4 operator[] (const Uint& i) const
		{
			return vec4(xs("%[%]", Definition(), i.Definition()));
		}

		std::string Definition() const
		{
			if (GetType() == Temporary)
			{
				return m_TemporaryInitialization;
			}

			return xs("%", GetName());
		}

		private:
		bool m_Declared = true;
		std::string m_TemporaryInitialization;

	};

}

#endif
