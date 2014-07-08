#ifndef __GLSLPP_PROGRAM_H
#define __GLSLPP_PROGRAM_H

namespace GLSLPP
{

	class Program
	{

		friend class Type;

		template <typename detail>
		friend class GenType;

		template <typename vec_detail>
		friend class generic_vec2;

		template <typename vec_detail>
		friend class generic_vec3;

		template <typename vec_detail>
		friend class generic_vec4;

		friend class mat3;
		friend class mat4;
		friend class sampler2D;
		friend class sampler2DMS;

		public:
		Program()
		{
			m_VertexSource += "#version 150\n\n";
			m_FragmentSource += "#version 150\n\n";

			if (enable_explicit_locations)
			{
				m_VertexSource += "#extension GL_ARB_explicit_attrib_location : enable\n\n";
				m_VertexSource += "#extension GL_ARB_explicit_uniform_location : enable\n\n";
				m_VertexSource += "#extension GL_ARB_shading_language_420pack : enable\n\n";
				m_FragmentSource += "#extension GL_ARB_explicit_attrib_location : enable\n\n";
				m_FragmentSource += "#extension GL_ARB_explicit_uniform_location : enable\n\n";
				m_FragmentSource += "#extension GL_ARB_shading_language_420pack : enable\n\n";
			}

			Bind();
		}

		~Program()
		{
			if (m_Bound == true && currentProgram == this)
			{
				//assert(currentProgram == this);

				currentProgram = nullptr;
			}
		}

		void Bind()
		{
			if (currentProgram != nullptr)
			{
				currentProgram->m_Bound = false;
			}

			currentProgram = this;
			m_Bound = true;
		}

		void BeginVertexShaderFunction(const std::string& name)
		{
			m_VertexSource += xs("\nvoid %()\n{\n", name);
			m_InVertexShader = true;
			m_InFragmentShader = false;
		}

		void EndVertexShaderFunction()
		{
			m_VertexSource += "}\n";
			m_InVertexShader = false;
		}

		void BeginFragmentShaderFunction(const std::string& name)
		{
			m_FragmentSource += xs("\nvoid %()\n{\n", name);
			m_InFragmentShader = true;
			m_InVertexShader = false;
		}

		void EndFragmentShaderFunction()
		{
			m_InFragmentShader = false;
			m_FragmentSource += "}\n";
		}

		void InjectCode(const std::string& code)
		{
			if (m_InVertexShader)
			{
				m_VertexSource += xs("    %;\n", code);
			}
			else if (m_InFragmentShader)
			{
				m_FragmentSource += xs("    %;\n", code);
			}
		}

		void InjectVertexCode(const std::string& code)
		{
			m_VertexSource += xs("%;\n", code);
		}

		void InjectFragmentCode(const std::string& code)
		{
			m_FragmentSource += xs("%;\n", code);
		}

		const std::string& GetVertexSource()
		{
			return m_VertexSource;
		}

		const std::string& GetFragmentSource()
		{
			return m_FragmentSource;
		}

		bool IsInFragmentShader()
		{
			return m_InFragmentShader;
		}

		bool InVertexShader()
		{
			return m_InVertexShader;
		}

		bool InFragmentShader()
		{
			return m_InFragmentShader;
		}

		private:
		std::string GenerateName()
		{
			return xs("temp_%", ++m_NextName);
		}

		size_t m_NextName = 0;

		bool m_InVertexShader = false;
		bool m_InFragmentShader = false;

		std::string m_VertexSource;
		std::string m_FragmentSource;

		bool m_Bound = false;

	};
	
}

#endif
