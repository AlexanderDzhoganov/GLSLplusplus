#ifndef __GLSLPP_MAT3_H
#define __GLSLPP_MAT3_H

namespace GLSLPP
{

	class mat3 : public Type
	{

		public:
		mat3() : Type(Variable, "mat3", currentProgram->GenerateName()) {}

		explicit mat3(VariableType type) : Type(type, "mat3", currentProgram->GenerateName()) {}

		mat3(VariableType type, const std::string& name) : Type(type, "mat3", name) {}

		vec3 operator[] (size_t i) const
		{
			return vec3(xs("%[%]", ExtendedName(), i));
		}

		vec3 operator[] (const Int& i) const
		{
			return vec3(xs("%[%]", ExtendedName(), i.ExtendedName()));
		}

		vec3 operator[] (const Uint& i) const
		{
			return vec3(xs("%[%]", ExtendedName(), i.ExtendedName()));
		}

		std::string ExtendedName() const
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

	class dmat3 : public Type
	{

		public:
		dmat3() : Type(Variable, "dmat3", currentProgram->GenerateName()) {}

		explicit dmat3(VariableType type) : Type(type, "dmat3", currentProgram->GenerateName()) {}

		dmat3(VariableType type, const std::string& name) : Type(type, "dmat3", name) {}

		dvec3 operator[] (size_t i) const
		{
			return dvec3(xs("%[%]", ExtendedName(), i));
		}

		dvec3 operator[] (const Int& i) const
		{
			return dvec3(xs("%[%]", ExtendedName(), i.ExtendedName()));
		}

		dvec3 operator[] (const Uint& i) const
		{
			return dvec3(xs("%[%]", ExtendedName(), i.ExtendedName()));
		}

		std::string ExtendedName() const
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
