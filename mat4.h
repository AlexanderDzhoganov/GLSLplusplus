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
