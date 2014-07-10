#ifndef __GLSLPP_MAT2_H
#define __GLSLPP_MAT2_H

namespace GLSLPP
{

	class mat2 : public Type
	{

		public:
		mat2() : Type(Variable, "mat2", currentProgram->GenerateName()) {}

		explicit mat2(VariableType type) : Type(type, "mat2", currentProgram->GenerateName()) {}

		mat2(VariableType type, const std::string& name) : Type(type, "mat2", name) {}

		vec2 operator[] (size_t i) const
		{
			return vec2(xs("%[%]", Definition(), i));
		}

		vec2 operator[] (const Int& i) const
		{
			return vec2(xs("%[%]", Definition(), i.Definition()));
		}

		vec2 operator[] (const Uint& i) const
		{
			return vec2(xs("%[%]", Definition(), i.Definition()));
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

	class dmat2 : public Type
	{

		public:
		dmat2() : Type(Variable, "dmat2", currentProgram->GenerateName()) {}

		explicit dmat2(VariableType type) : Type(type, "dmat2", currentProgram->GenerateName()) {}

		dmat2(VariableType type, const std::string& name) : Type(type, "dmat2", name) {}

		dvec2 operator[] (size_t i) const
		{
			return dvec2(xs("%[%]", Definition(), i));
		}

		dvec2 operator[] (const Int& i) const
		{
			return dvec2(xs("%[%]", Definition(), i.Definition()));
		}

		dvec2 operator[] (const Uint& i) const
		{
			return dvec2(xs("%[%]", Definition(), i.Definition()));
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
