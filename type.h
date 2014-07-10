#ifndef __GLSLPP_TYPE_H
#define __GLSLPP_TYPE_H

namespace GLSLPP
{

	enum VariableQualifier
	{

		Variable = 0,
		VertexUniform,
		FragmentUniform,
		VertexIn,
		VertexOut,
		FragmentOut,
		FragmentIn,
		Temporary,

	};

	class Type
	{

		public:
		Type(VariableQualifier type, const std::string& typeName, const std::string& name, int layoutLocation = -1) : m_Type(type), m_TypeName(typeName), m_Name(name)
		{
			if (type == VertexUniform)
			{
				if (currentProgram->m_GL_ARB_explicit_attrib_location && layoutLocation != -1)
				{
					currentProgram->InjectVertexCode(xs("% uniform % %", xs("layout(binding = %)", layoutLocation), m_TypeName, m_Name));
				}
				else
				{
					currentProgram->InjectVertexCode(xs("uniform % %", m_TypeName, m_Name));
				}
			}
			else if (type == FragmentUniform)
			{
				if (currentProgram->m_GL_ARB_explicit_uniform_location && layoutLocation != -1)
				{
					currentProgram->InjectFragmentCode(xs("% uniform % %", xs("layout(binding = %)", layoutLocation), m_TypeName, m_Name));
				}
				else
				{
					currentProgram->InjectFragmentCode(xs("uniform % %", m_TypeName, m_Name));
				}
			}
			else if (type == VertexIn)
			{
				if (currentProgram->m_GL_ARB_explicit_attrib_location && layoutLocation != -1)
				{
					currentProgram->InjectVertexCode(xs("% in % %", xs("layout(location = %)", layoutLocation), m_TypeName, m_Name));
				}
				else
				{
					currentProgram->InjectVertexCode(xs("in % %", m_TypeName, m_Name));
				}
			}
			else if (type == VertexOut)
			{
				currentProgram->InjectVertexCode(xs("out % %", m_TypeName, m_Name));

				if (m_Name != "gl_Position")
				{
					currentProgram->InjectFragmentCode(xs("in % %", m_TypeName, m_Name));
				}
			}
			else if (type == FragmentIn)
			{
				currentProgram->InjectFragmentCode(xs("in % %", m_TypeName, m_Name));
			}
			else if (type == FragmentOut)
			{
				if (currentProgram->m_GL_ARB_explicit_attrib_location && layoutLocation != -1)
				{
					currentProgram->InjectFragmentCode(xs("% out % %", xs("layout(location = %)", layoutLocation), m_TypeName, m_Name));
				}
				else
				{
					currentProgram->InjectFragmentCode(xs("out % %", m_TypeName, m_Name));
				}
			}
		}

		VariableQualifier GetType() const
		{
			return m_Type;
		}

		void SetType(VariableQualifier type)
		{
			m_Type = type;
		}

		void SetName(const std::string& name)
		{
			m_Name = name;
		}

		const std::string& GetName() const
		{
			return m_Name;
		}

		const std::string& GetTypeName() const
		{
			return m_TypeName;
		}

		private:
		VariableQualifier m_Type;
		std::string m_Name;
		std::string m_TypeName;
		size_t m_LayoutLocation = 0;

	};

}

#endif
