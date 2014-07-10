#ifndef __GLSLPP_GENTYPE_H
#define __GLSLPP_GENTYPE_H

namespace GLSLPP
{

	class gentype_float_detail;
	class gentype_int_detail;

	template <typename detail>
	class GenType : public Type
	{
		
		private:
		typedef typename detail::native_type t_native;

		friend class GenType<gentype_float_detail>;
		friend class GenType<gentype_int_detail>;

		template <typename vec_detail>
		friend class generic_vec2;

		template <typename vec_detail>
		friend class generic_vec3;

		template <typename vec_detail>
		friend class generic_vec4;

		template <typename detail>
		friend GenType<detail> floor(const GenType<detail>&);

		template <typename detail>
		friend GenType<detail> ceil(const GenType<detail>&);

		template <typename detail>
		friend GenType<detail> mod(const GenType<detail>&, float);

		template <typename T>
		friend T NoTemp(const T&);

		template <typename detail>
		friend GenType<detail> operator+(const GenType<detail>&, typename detail::native_type);

		template <typename detail>
		friend GenType<detail> operator+(const GenType<detail>&, const GenType<detail>&);

		template <typename detail>
		friend GenType<detail> operator-(typename detail::native_type a, const GenType<detail>& b);

		template <typename detail>
		friend GenType<detail> operator-(const GenType<detail>&, typename detail::native_type);

		template <typename detail>
		friend GenType<detail> operator-(const GenType<detail>&, const GenType<detail>&);

		template <typename detail>
		friend GenType<detail> operator*(const GenType<detail>&, const GenType<detail>&);

		template <typename detail>
		friend GenType<detail> operator*(const GenType<detail>&, typename detail::native_type);

		friend GenType<gentype_float_detail> operator*(const GenType<gentype_float_detail>&, const GenType<gentype_int_detail>&);

		friend GenType<gentype_float_detail> operator*(const GenType<gentype_int_detail>&, const GenType<gentype_float_detail>&);

		template <typename detail>
		friend GenType<detail> operator/(const GenType<detail>&, const GenType<detail>&);

		template <typename detail>
		friend GenType<detail> operator/(const GenType<detail>&, typename detail::native_type);

		template <typename detail>
		friend GenType<detail> operator%(const GenType<detail>&, typename detail::native_type);

		public:
		GenType() : Type(Variable, "float", currentProgram->GenerateName()) {}

		explicit GenType(VariableType type) :
			Type(type, detail::glsl_type_string(), currentProgram->GenerateName()),
			m_Declared(type != Variable)
		{
		}

		GenType(VariableType type, const std::string& name) :
			Type(type, detail::glsl_type_string(), name),
			m_Declared(type != Variable)
		{
		}

		GenType(float f) :
			Type(Temporary, detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%", f))
		{
		}

		GenType(const GenType& f) :
			Type(f.GetType() == Temporary ? Temporary : Variable, detail::glsl_type_string(), currentProgram->GenerateName()),
			m_Declared(true)
		{
			if (f.GetType() == Temporary)
			{
				m_TemporaryInitialization = f.m_TemporaryInitialization;
			}
			else
			{
				currentProgram->InjectCode(xs("% % = %", detail::glsl_type_string(), GetName(), f.ExtendedName()));
			}
		}

		GenType(GenType&& f) :
			Type(f.GetType() == Temporary ? Temporary : Variable, detail::glsl_type_string(), currentProgram->GenerateName()),
			m_Declared(true)
		{
			if (f.GetType() == Temporary)
			{
				m_TemporaryInitialization = f.m_TemporaryInitialization;
				f.m_TemporaryInitialization = "DELETED";
			}
			else
			{
				currentProgram->InjectCode(xs("% % = %", detail::glsl_type_string(), GetName(), f.ExtendedName()));
			}
		}

		template <typename detail_1>
		GenType(const GenType<detail_1>& f) :
			Type(f.GetType() == Temporary ? Temporary : Variable, detail::glsl_type_string(), currentProgram->GenerateName()),
			m_Declared(true)
		{
			if (f.GetType() == Temporary)
			{
				m_TemporaryInitialization = xs("%(%)", detail::glsl_type_string(), f.m_TemporaryInitialization);
			}
			else
			{
				currentProgram->InjectCode(xs("% % = %(%)", detail::glsl_type_string(), GetName(), detail::glsl_type_string(), f.ExtendedName()));
			}
		}

		template <typename detail_1>
		GenType(GenType<detail_1>&& f) :
			Type(f.GetType() == Temporary ? Temporary : Variable, detail::glsl_type_string(), currentProgram->GenerateName()),
			m_Declared(true)
		{
			if (f.GetType() == Temporary)
			{
				m_TemporaryInitialization = xs("%(%)", detail::glsl_type_string(), f.m_TemporaryInitialization);
			}
			else
			{
				SetName(f.GetName());
				SetType(f.GetType());
				f.SetName("DELETED");
			}
		}

		GenType& operator=(const GenType& f)
		{
			m_Declared = true;

			if (GetType() == Variable)
			{
				currentProgram->InjectCode(xs("% % = %", detail::glsl_type_string(), GetName(), f.ExtendedName()));
			}
			else
			{
				currentProgram->InjectCode(xs("% = %", GetName(), f.ExtendedName()));
			}

			return *this;
		}

		GenType& operator=(GenType&& f)
		{
			m_Declared = true;

			if (f.GetType() == Variable)
			{
				SetName(f.GetName());
				SetType(f.GetType());
				f.SetName("DELETED");					
			}
			else
			{
				if (GetType() == Variable)
				{
					currentProgram->InjectCode(xs("% % = %", detail::glsl_type_string(), GetName(), f.ExtendedName()));
				}
				else
				{
					currentProgram->InjectCode(xs("% = %", ExtendedName(), f.ExtendedName()));
				}
			}

			return *this;
		}

		std::string ExtendedName() const
		{
			if (GetType() == Temporary)
			{
				return m_TemporaryInitialization;
			}

			if (m_Swizzle == Swizzle::NoSwizzle)
			{
				return xs("%", GetName());
			}

			return xs("%.%", GetName(), SwizzleExtension(m_Swizzle));
		}

		void Apply()
		{
			if (!m_Declared || GetType() == Temporary)
			{
				currentProgram->InjectCode(xs("% % = %", detail::glsl_type_string(), GetName(), ExtendedName()));
				m_Declared = true;
				SetType(Variable);
			}
		}

		GenType(VariableType type, std::string name, Swizzle swizzle) :
			Type(type, vec_detail::glsl_type_string(), name),
			m_Swizzle(swizzle)
		{
		}

		GenType(const std::string& temporaryInitilization) :
			Type(Temporary, detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(temporaryInitilization)
		{
		}

		private:
		bool m_Declared = false;
		std::string m_TemporaryInitialization;
		Swizzle m_Swizzle = Swizzle::NoSwizzle;

	};

}

#endif
