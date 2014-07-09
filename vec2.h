#ifndef __GLSLPP_VEC2_H
#define __GLSLPP_VEC2_H

namespace GLSLPP
{

	template <typename vec_detail>
	class generic_vec2 : public Type
	{

		private:
		typedef typename vec_detail::abstract_type t_abstract;
		typedef typename vec_detail::native_type t_native;

		template <typename vec_detail>
		friend class generic_vec3;

		template <typename vec_detail>
		friend class generic_vec4;

		friend vec4 texture(const sampler2D&, const generic_vec2&);
		friend vec4 texelFetch(const sampler2D& sampler, const generic_vec2& texCoords, const Int& lod);
		friend vec4 texelFetch(const sampler2D& sampler, const generic_vec2& texCoords, int lod);
		friend vec4 texelFetch(const sampler2DMS& sampler, const generic_vec2& texCoords, const Int& lod);
		friend vec4 texelFetch(const sampler2DMS& sampler, const generic_vec2& texCoords, int lod);

		friend generic_vec2 operator+(const generic_vec2&, const generic_vec2&);
		friend generic_vec2 operator-(const generic_vec2&, const generic_vec2&);
		friend generic_vec2 operator*(const generic_vec2&, const generic_vec2&);
		friend generic_vec2 operator/(const generic_vec2&, const generic_vec2&);
		friend generic_vec2 operator*(const generic_vec2&, const t_abstract&);
		friend generic_vec2 operator/(const generic_vec2&, const t_abstract&);
		friend generic_vec2 operator*(const generic_vec2&, t_native);
		friend generic_vec2 operator/(const generic_vec2&, t_native);

		public:
		generic_vec2() :
			Type(Variable, vec_detail::glsl_type_string(), currentProgram->GenerateName())
		{
		}

		explicit generic_vec2(VariableType type) :
			Type(type, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_Declared(type != Variable)
		{
		}

		generic_vec2(VariableType type, int layoutPosition) :
			Type(type, vec_detail::glsl_type_string(), currentProgram->GenerateName(), layoutPosition),
			m_Declared(type != Variable)
		{
		}

		generic_vec2(VariableType type, const std::string& name) :
			Type(type, vec_detail::glsl_type_string(), name),
			m_Declared(type != Variable)
		{
		}

		generic_vec2(VariableType type, const std::string& name, int layoutPosition) :
			Type(type, vec_detail::glsl_type_string(), name, layoutPosition),
			m_Declared(type != Variable)
		{
		}

		template <typename T>
		generic_vec2(const generic_vec2<T>& value) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%)", vec_detail::glsl_type_string(), value.ExtendedName()))
		{
		}

		template <typename detail_1, typename detail_2>
		generic_vec2(const GenType<detail_1>& x, const GenType<detail_2>& y) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %)", vec_detail::glsl_type_string(), x.ExtendedName(), y.ExtendedName()))
		{
		}
		
		generic_vec2(t_native x, const t_abstract& y) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %)", vec_detail::glsl_type_string(), x, y.ExtendedName()))
		{
		}

		generic_vec2(const t_abstract& x, t_native y) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %)", vec_detail::glsl_type_string(), x.ExtendedName(), y))
		{
		}

		generic_vec2(t_native x, t_native y) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %)", vec_detail::glsl_type_string(), x, y))
		{
		}

		generic_vec2& operator=(const generic_vec2& v)
		{
			if (&v == this)
			{
				return *this;
			}

			if (!m_Declared)
			{
				currentProgram->InjectCode(xs("% % = %", vec_detail::glsl_type_string(), GetName(), v.ExtendedName()));
				m_Declared = true;
			}
			else
			{
				currentProgram->InjectCode(xs("% = %", GetName(), v.ExtendedName()));
			}

			return *this;
		}

		generic_vec2& operator=(generic_vec2&& v)
		{
			if (&v == this)
			{
				return *this;
			}

			if (v.GetType() == Variable)
			{
				SetName(v.GetName());
				m_Declared = v.m_Declared;
				SetType(v.GetType());
			}
			else
			{
				if (!m_Declared)
				{
					currentProgram->InjectCode(xs("% % = %", vec_detail::glsl_type_string(), GetName(), v.ExtendedName()));
					m_Declared = true;
					SetType(Variable);
				}
				else
				{
					currentProgram->InjectCode(xs("% = %", GetName(), v.ExtendedName()));
				}
			}

			v.SetName("DELETED");
			return *this;
		}

		t_abstract operator [] (int index) const
		{
			return t_abstract(xs("%[%]", ExtendedName(), index));
		}

		SWIZZLE_OP(t_abstract, x); SWIZZLE_OP(t_abstract, y);
		SWIZZLE_OP(generic_vec2, xx); SWIZZLE_OP(generic_vec2, xy); SWIZZLE_OP(generic_vec2, yx); SWIZZLE_OP(generic_vec2, yy);

		SWIZZLE_OP(t_abstract, r); SWIZZLE_OP(t_abstract, g); SWIZZLE_OP(t_abstract, b); SWIZZLE_OP(t_abstract, a);
		SWIZZLE_OP(generic_vec2, rr); SWIZZLE_OP(generic_vec2, rg); SWIZZLE_OP(generic_vec2, gr); SWIZZLE_OP(generic_vec2, gg);

		inline std::string ExtendedName() const
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

		generic_vec2(VariableType type, std::string name, Swizzle swizzle) :
			Type(type, vec_detail::glsl_type_string(), name),
			m_Swizzle(swizzle)
		{
		}

		generic_vec2(const std::string& temporaryInitialization) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(temporaryInitialization)
		{
		}

		private:
		Swizzle m_Swizzle = Swizzle::NoSwizzle;
		bool m_Declared = false;
		std::string m_TemporaryInitialization;

	};

	class vec2_float_detail
	{

		public:
		typedef float native_type;
		typedef GenType<gentype_float_detail> abstract_type;

		static inline const char* glsl_type_string()
		{
			return "vec2";
		}

	};

	class vec2_int_detail
	{

		public:
		typedef int native_type;
		typedef GenType<gentype_int_detail> abstract_type;

		static inline const char* glsl_type_string()
		{
			return "ivec2";
		}

	};

	typedef generic_vec2<vec2_float_detail> vec2;
	typedef generic_vec2<vec2_int_detail> ivec2;

}

#endif
