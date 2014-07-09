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
