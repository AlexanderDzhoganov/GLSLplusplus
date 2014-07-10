#ifndef __GLSLPP_VEC3_H
#define __GLSLPP_VEC3_H

namespace GLSLPP
{

	template <typename vec_detail>
	class generic_vec3 : public Type
	{

		private:
		typedef generic_vec2<typename vec_detail::vec2_detail> t_vec2;
		typedef typename vec_detail::abstract_type t_abstract;
		typedef typename vec_detail::native_type t_native;

		template <typename vec_detail>
		friend class generic_vec4;

		template <typename vec_detail>
		friend generic_vec3<vec_detail> operator+(const generic_vec3<vec_detail>&, const generic_vec3<vec_detail>&);

		template <typename vec_detail>
		friend generic_vec3<vec_detail> operator-(const generic_vec3<vec_detail>&, const generic_vec3<vec_detail>&);

		template <typename vec_detail>
		friend generic_vec3<vec_detail> operator*(const generic_vec3<vec_detail>&, const generic_vec3<vec_detail>&);

		template <typename vec_detail>
		friend generic_vec3<vec_detail> operator/(const generic_vec3<vec_detail>&, const generic_vec3<vec_detail>&);

		template <typename vec_detail>
		friend generic_vec3<vec_detail> operator*(const generic_vec3<vec_detail>&, const t_abstract&);

		template <typename vec_detail>
		friend generic_vec3<vec_detail> operator/(const generic_vec3<vec_detail>&, const t_abstract&);

		template <typename vec_detail>
		friend generic_vec3<vec_detail> operator*(const generic_vec3<vec_detail>&, t_native);

		template <typename vec_detail>
		friend generic_vec3<vec_detail> operator/(const generic_vec3<vec_detail>&, t_native);

		template <typename vec_detail>
		friend generic_vec3<vec_detail> operator*(const mat3&, const generic_vec3<vec_detail>&);

		public:
		generic_vec3() :
			Type(Variable, vec_detail::glsl_type_string(), currentProgram->GenerateName())
		{
		}

		explicit generic_vec3(VariableType type) :
			m_Declared(type != Variable),
			Type(type, vec_detail::glsl_type_string(), currentProgram->GenerateName())
		{
		}

		generic_vec3(VariableType type, int layoutPosition) :
			m_Declared(type != Variable),
			Type(type, vec_detail::glsl_type_string(), currentProgram->GenerateName(), layoutPosition)
		{
		}

		generic_vec3(VariableType type, const std::string& name) :
			Type(type, vec_detail::glsl_type_string(), name) 
		{
		}

		generic_vec3(VariableType type, const std::string& name, int layoutPosition) :
			Type(type, vec_detail::glsl_type_string(), name, layoutPosition)
		{
		}

		generic_vec3(const t_abstract& x, const t_abstract& y, const t_abstract& z) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %, %)", vec_detail::glsl_type_string(), x.Definition(), y.Definition(), z.Definition()))
		{
		}

		generic_vec3(const t_vec2& xy, const t_abstract& z) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %)", vec_detail::glsl_type_string(), xy.Definition(), z.Definition()))
		{
		}

		generic_vec3(const t_vec2& xy, t_native z) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %)", vec_detail::glsl_type_string(), xy.Definition(), z))
		{
		}

		generic_vec3& operator=(const generic_vec3& v)
		{
			if (&v == this)
			{
				return *this;
			}

			if (!m_Declared)
			{
				currentProgram->InjectCode(xs("% % = %", vec_detail::glsl_type_string(), GetName(), v.Definition()));
				m_Declared = true;
			}
			else
			{
				currentProgram->InjectCode(xs("% = %", GetName(), v.Definition()));
			}

			return *this;
		}

		generic_vec3& operator=(generic_vec3&& v)
		{
			if (&v == this)
			{
				return *this;
			}

			if (v.GetType() == Variable)
			{
				SetName(v.GetName());
				SetType(v.GetType());
				m_Declared = v.m_Declared;
			}
			else
			{
				if (!m_Declared)
				{
					currentProgram->InjectCode(xs("% % = %", vec_detail::glsl_type_string(), GetName(), v.Definition()));
					m_Declared = true;
					SetType(Variable);
				}
				else
				{
					currentProgram->InjectCode(xs("% = %", GetName(), v.Definition()));
				}
			}

			v.SetName("DELETED");
			return *this;
		}

		t_abstract operator [] (int index) const
		{
			return t_abstract(xs("%[%]", Definition(), index));
		}

		t_abstract operator [] (const Int& index) const
		{
			return t_abstract(xs("%[%]", Definition(), index.Definition()));
		}

		t_abstract operator [] (const Uint& index) const
		{
			return t_abstract(xs("%[%]", Definition(), index.Definition()));
		}

		SWIZZLE_OP(t_abstract, x); SWIZZLE_OP(t_abstract, y); SWIZZLE_OP(t_abstract, z);
		SWIZZLE_OP(t_vec2, xx); SWIZZLE_OP(t_vec2, xy); SWIZZLE_OP(t_vec2, xz); SWIZZLE_OP(t_vec2, yx);
		SWIZZLE_OP(t_vec2, yy); SWIZZLE_OP(t_vec2, yz); SWIZZLE_OP(t_vec2, zx); SWIZZLE_OP(t_vec2, zy);
		SWIZZLE_OP(t_vec2, zz); SWIZZLE_OP(t_vec2, wx); SWIZZLE_OP(t_vec2, wy); SWIZZLE_OP(t_vec2, wz);

		SWIZZLE_OP(generic_vec3, xxx); SWIZZLE_OP(generic_vec3, xxy); SWIZZLE_OP(generic_vec3, xxz); 
		SWIZZLE_OP(generic_vec3, xyx); SWIZZLE_OP(generic_vec3, xyy); SWIZZLE_OP(generic_vec3, xyz);
		SWIZZLE_OP(generic_vec3, xzx); SWIZZLE_OP(generic_vec3, xzy); SWIZZLE_OP(generic_vec3, xzz);
		SWIZZLE_OP(generic_vec3, yxx); SWIZZLE_OP(generic_vec3, yxy); SWIZZLE_OP(generic_vec3, yxz);
		SWIZZLE_OP(generic_vec3, yyx); SWIZZLE_OP(generic_vec3, yyy); SWIZZLE_OP(generic_vec3, yyz);
		SWIZZLE_OP(generic_vec3, yzx); SWIZZLE_OP(generic_vec3, yzy); SWIZZLE_OP(generic_vec3, yzz);

		SWIZZLE_OP(t_abstract, r); SWIZZLE_OP(t_abstract, g); SWIZZLE_OP(t_abstract, b);
		SWIZZLE_OP(t_vec2, rr); SWIZZLE_OP(t_vec2, rg); SWIZZLE_OP(t_vec2, rb);
		SWIZZLE_OP(t_vec2, gr); SWIZZLE_OP(t_vec2, gg); SWIZZLE_OP(t_vec2, gb);
		SWIZZLE_OP(t_vec2, br); SWIZZLE_OP(t_vec2, bg); SWIZZLE_OP(t_vec2, bb);

		SWIZZLE_OP(generic_vec3, rrr); SWIZZLE_OP(generic_vec3, rrg); SWIZZLE_OP(generic_vec3, rrb);
		SWIZZLE_OP(generic_vec3, rgr); SWIZZLE_OP(generic_vec3, rgg); SWIZZLE_OP(generic_vec3, rgb);
		SWIZZLE_OP(generic_vec3, rbr); SWIZZLE_OP(generic_vec3, rbg); SWIZZLE_OP(generic_vec3, rbb);
		SWIZZLE_OP(generic_vec3, grr); SWIZZLE_OP(generic_vec3, grg); SWIZZLE_OP(generic_vec3, grb);
		SWIZZLE_OP(generic_vec3, ggr); SWIZZLE_OP(generic_vec3, ggg); SWIZZLE_OP(generic_vec3, ggb);
		SWIZZLE_OP(generic_vec3, gbr); SWIZZLE_OP(generic_vec3, gbg); SWIZZLE_OP(generic_vec3, gbb);
		SWIZZLE_OP(generic_vec3, brr); SWIZZLE_OP(generic_vec3, brg); SWIZZLE_OP(generic_vec3, brb);
		SWIZZLE_OP(generic_vec3, bgr); SWIZZLE_OP(generic_vec3, bgg); SWIZZLE_OP(generic_vec3, bgb);
		SWIZZLE_OP(generic_vec3, bbr); SWIZZLE_OP(generic_vec3, bbg); SWIZZLE_OP(generic_vec3, bbb);

		inline std::string Definition() const
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

		generic_vec3(VariableType type, const std::string& name, Swizzle swizzle) :
			Type(type, vec_detail::glsl_type_string(), name),
			m_Swizzle(swizzle)
		{
		}

		generic_vec3(const std::string& temporaryInitialization) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(temporaryInitialization)
		{
		}

		private:
		Swizzle m_Swizzle = Swizzle::NoSwizzle;
		bool m_Declared = false;
		std::string m_TemporaryInitialization;

	};

}

#endif
