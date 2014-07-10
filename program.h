#ifndef __GLSLPP_PROGRAM_H
#define __GLSLPP_PROGRAM_H

namespace GLSLPP
{

	enum GLSLVersion
	{
		GLSL150,
		GLSL440,
	};

	enum GLSLExtension
	{
		GL_ARB_explicit_attrib_location = 0,
		GL_ARB_explicit_uniform_location = 1,
		GL_ARB_shading_language_420pack = 2,
	};

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

		friend class mat2;
		friend class dmat2;

		friend class mat3;
		friend class dmat3;

		friend class mat4;
		friend class dmat4;

		template <typename detail>
		friend class generic_sampler2D;

		friend class sampler2DMS;

		public:
		Program(GLSLVersion version = GLSL440) : m_Version(version)
		{
			switch (m_Version)
			{
			case GLSL150:
				m_VertexSource += "#version 150\n\n";
				m_FragmentSource += "#version 150\n\n";
				break;
			case GLSL440:
				m_VertexSource += "#version 440\n\n";
				m_FragmentSource += "#version 440\n\n";
				break;
			}
			
			Bind();
		}

		~Program()
		{
			if (m_Bound == true && currentProgram == this)
			{
				currentProgram = nullptr;
			}
		}

		void EnableExtension(GLSLExtension extension)
		{
			switch (extension)
			{
			case GLSLExtension::GL_ARB_explicit_attrib_location:
				if (m_GL_ARB_explicit_attrib_location)
				{
					return;
				}
				m_GL_ARB_explicit_attrib_location = true;
				m_VertexSource += "#extension GL_ARB_explicit_attrib_location : enable\n";
				m_FragmentSource += "#extension GL_ARB_explicit_attrib_location : enable\n";
				break;
			case GLSLExtension::GL_ARB_explicit_uniform_location:
				if (m_GL_ARB_explicit_uniform_location)
				{
					return;
				}
				m_GL_ARB_explicit_uniform_location = true;
				m_VertexSource += "#extension GL_ARB_explicit_uniform_location : enable\n";
				m_FragmentSource += "#extension GL_ARB_explicit_uniform_location : enable\n";
				break;
			case GLSLExtension::GL_ARB_shading_language_420pack:
				if (m_GL_ARB_shading_language_420pack)
				{
					return;
				}
				m_GL_ARB_shading_language_420pack = true;
				m_VertexSource += "#extension GL_ARB_shading_language_420pack : enable\n";
				m_FragmentSource += "#extension GL_ARB_shading_language_420pack : enable\n";
				break;
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

		void VertexMain()
		{
			m_VertexSource += "\nvoid main()\n{\n";
			m_InVertexShader = true;
			m_InFragmentShader = false;
		}

		void EndVertexMain()
		{
			m_VertexSource += "}\n";
			m_InVertexShader = false;
		}

		template <typename F>
		void SetVertexShader(F f)
		{
			m_VertexSource += "\nvoid main()\n{\n";
			m_InVertexShader = true;

			f();

			m_VertexSource += "}\n";
			m_InVertexShader = false;
		}

		void FragmentMain()
		{
			m_FragmentSource += "\nvoid main()\n{\n";
			m_InFragmentShader = true;
			m_InVertexShader = false;
		}

		void EndFragmentMain()
		{
			m_InFragmentShader = false;
			m_FragmentSource += "}\n";
		}

		template <typename F>
		void SetFragmentShader(F f)
		{
			m_FragmentSource += "\nvoid main()\n{\n";
			m_InFragmentShader = true;
			m_InVertexShader = false;

			f();

			m_InFragmentShader = false;
			m_FragmentSource += "}\n";
		}

		void InjectCode(const std::string& code, bool endLine = true)
		{
			if (m_InVertexShader)
			{
				if (endLine)
				{
					m_VertexSource += xs("    %;\n", code);
				}
				else
				{
					m_VertexSource += xs("    %", code);
				}
			}
			else if (m_InFragmentShader)
			{
				if (endLine)
				{
					m_FragmentSource += xs("    %;\n", code);
				}
				else
				{
					m_FragmentSource += xs("    %", code);
				}
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

		GLSLVersion m_Version = GLSL440;
		bool m_GL_ARB_explicit_attrib_location = false;
		bool m_GL_ARB_explicit_uniform_location = false;
		bool m_GL_ARB_shading_language_420pack = false;

	};
	
}

#endif
