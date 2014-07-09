#ifndef __GLSLPP_VEC4_H
#define __GLSLPP_VEC4_H

namespace GLSLPP
{

	template <typename vec_detail>
	class generic_vec4 : public Type
	{

		private:
		typedef generic_vec2<typename vec_detail::vec2_detail> t_vec2;
		typedef generic_vec3<typename vec_detail::vec3_detail> t_vec3;
		typedef typename vec_detail::abstract_type t_abstract;
		typedef typename vec_detail::native_type t_native;

		friend class Program;

		friend generic_vec4 texture(const sampler2D&, const vec2&);
		friend generic_vec4 texelFetch(const sampler2D& sampler, const ivec2& texCoords, const Int& lod);
		friend generic_vec4 texelFetch(const sampler2D& sampler, const ivec2& texCoords, int lod);
		friend generic_vec4 texelFetch(const sampler2DMS& sampler, const ivec2& texCoords, const Int& lod);
		friend generic_vec4 texelFetch(const sampler2DMS& sampler, const ivec2& texCoords, int lod);

		template <typename vec_detail>
		friend generic_vec4<vec_detail> operator+(const generic_vec4<vec_detail>& a, const generic_vec4<vec_detail>& b);

		template <typename vec_detail>
		friend generic_vec4<vec_detail> operator-(const generic_vec4<vec_detail>&, const generic_vec4<vec_detail>&);

		template <typename vec_detail>
		friend generic_vec4<vec_detail> operator*(const generic_vec4<vec_detail>&, const generic_vec4<vec_detail>&);

		template <typename vec_detail>
		friend generic_vec4<vec_detail> operator/(const generic_vec4<vec_detail>&, const generic_vec4<vec_detail>&);

		template <typename vec_detail>
		friend generic_vec4<vec_detail> operator*(const generic_vec4<vec_detail>& a, const Float& b);

		template <typename vec_detail>
		friend generic_vec4<vec_detail> operator/(const generic_vec4<vec_detail>&, const Float&);

		template <typename vec_detail>
		friend generic_vec4<vec_detail> operator*(const generic_vec4<vec_detail>&, float);

		template <typename vec_detail>
		friend generic_vec4<vec_detail> operator/(const generic_vec4<vec_detail>&, float);

		template <typename vec_detail>
		friend generic_vec4<vec_detail> operator*(const mat4& m, const generic_vec4<vec_detail>& v);

		public:
		generic_vec4() :
			Type(Variable, vec_detail::glsl_type_string(), currentProgram->GenerateName())
		{
		}

		explicit generic_vec4(VariableType type) :
			Type(type, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_Declared(type != Variable)
		{
		}

		generic_vec4(VariableType type, int layoutPosition) :
			Type(type, vec_detail::glsl_type_string(), currentProgram->GenerateName(), layoutPosition),
			m_Declared(type != Variable)
		{
		}

		generic_vec4(VariableType type, const std::string& name) :
			Type(type, vec_detail::glsl_type_string(), name),
			m_Declared(type != Variable)
		{
		}

		generic_vec4(VariableType type, const std::string& name, int layoutPosition) :
			Type(type, vec_detail::glsl_type_string(), name, layoutPosition),
			m_Declared(type != Variable)
		{
		}

		template <typename T>
		generic_vec4(const generic_vec4<T>& value) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%)", vec_detail::glsl_type_string(), value.ExtendedName()))
		{
		}

		generic_vec4(const t_abstract& x, const t_abstract& y, const t_abstract& z, const t_abstract& w) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %, %, %)", vec_detail::glsl_type_string(), x.ExtendedName(), y.ExtendedName(), z.ExtendedName(), w.ExtendedName()))
		{
		}

		generic_vec4(const t_abstract& x, const t_abstract& y, const t_abstract& z, t_native w) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %, %, %)", vec_detail::glsl_type_string(), x.ExtendedName(), y.ExtendedName(), z.ExtendedName(), w))
		{
		}

		generic_vec4(t_native x, t_native y, t_native z, t_native w) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %, %, %)", vec_detail::glsl_type_string(), x, y, z, w))
		{
		}

		generic_vec4(const t_vec2& xy, t_native z, t_native w) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %, %)", vec_detail::glsl_type_string(), xy.ExtendedName(), z, w))
		{
		}

		generic_vec4(t_native x, const t_vec2& yz, t_native w) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %, %)", vec_detail::glsl_type_string(), x, yz.ExtendedName(), w))
		{
		}

		generic_vec4(t_native x, t_native y, const t_vec2& zw) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %, %)", vec_detail::glsl_type_string(), x, y, zw.ExtendedName()))
		{
		}

		generic_vec4(const t_vec3& xyz, t_native w) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %)", vec_detail::glsl_type_string(), xyz.ExtendedName(), w))
		{
		}

		generic_vec4(const t_vec3& xyz, const t_abstract& w) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %)", vec_detail::glsl_type_string(), xyz.ExtendedName(), w.ExtendedName()))
		{
		}

		generic_vec4(t_native x, const t_vec3& yzw) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName()),
			m_TemporaryInitialization(xs("%(%, %)", vec_detail::glsl_type_string(), x, yzw.ExtendedName()))
		{
		}

		generic_vec4(const t_abstract& x, const t_vec3& yzw) :
			Type(Temporary, vec_detail::glsl_type_string(), currentProgram->GenerateName())
			m_TemporaryInitialization(xs("%(%, %)", vec_detail::glsl_type_string(), x.ExtendedName(), yzw.ExtendedName()))
		{
		}

		generic_vec4& operator=(const generic_vec4& v)
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

		generic_vec4& operator=(generic_vec4&& v)
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

		SWIZZLE_OP(t_abstract, x); SWIZZLE_OP(t_abstract, y); SWIZZLE_OP(t_abstract, z); SWIZZLE_OP(t_abstract, w);

		SWIZZLE_OP(t_vec2, xx); SWIZZLE_OP(t_vec2, xy); SWIZZLE_OP(t_vec2, xz); SWIZZLE_OP(t_vec2, xw);
		SWIZZLE_OP(t_vec2, yx); SWIZZLE_OP(t_vec2, yy); SWIZZLE_OP(t_vec2, yz); SWIZZLE_OP(t_vec2, yw);
		SWIZZLE_OP(t_vec2, zx); SWIZZLE_OP(t_vec2, zy); SWIZZLE_OP(t_vec2, zz); SWIZZLE_OP(t_vec2, zw);
		SWIZZLE_OP(t_vec2, wx); SWIZZLE_OP(t_vec2, wy); SWIZZLE_OP(t_vec2, wz); SWIZZLE_OP(t_vec2, ww);

		SWIZZLE_OP(t_vec3, xxx); SWIZZLE_OP(t_vec3, xxy); SWIZZLE_OP(t_vec3, xxz); SWIZZLE_OP(t_vec3, xxw);
		SWIZZLE_OP(t_vec3, xyx); SWIZZLE_OP(t_vec3, xyy); SWIZZLE_OP(t_vec3, xyz); SWIZZLE_OP(t_vec3, xyw);
		SWIZZLE_OP(t_vec3, xzx); SWIZZLE_OP(t_vec3, xzy); SWIZZLE_OP(t_vec3, xzz); SWIZZLE_OP(t_vec3, xzw);
		SWIZZLE_OP(t_vec3, xwx); SWIZZLE_OP(t_vec3, xwy); SWIZZLE_OP(t_vec3, xwz); SWIZZLE_OP(t_vec3, xww);
		SWIZZLE_OP(t_vec3, yxx); SWIZZLE_OP(t_vec3, yxy); SWIZZLE_OP(t_vec3, yxz); SWIZZLE_OP(t_vec3, yxw);
		SWIZZLE_OP(t_vec3, yyx); SWIZZLE_OP(t_vec3, yyy); SWIZZLE_OP(t_vec3, yyz); SWIZZLE_OP(t_vec3, yyw);
		SWIZZLE_OP(t_vec3, yzx); SWIZZLE_OP(t_vec3, yzy); SWIZZLE_OP(t_vec3, yzz); SWIZZLE_OP(t_vec3, yzw);
		SWIZZLE_OP(t_vec3, ywx); SWIZZLE_OP(t_vec3, ywy); SWIZZLE_OP(t_vec3, ywz); SWIZZLE_OP(t_vec3, yww);
		SWIZZLE_OP(t_vec3, wxx); SWIZZLE_OP(t_vec3, wxy); SWIZZLE_OP(t_vec3, wxz); SWIZZLE_OP(t_vec3, wxw);
		SWIZZLE_OP(t_vec3, wyx); SWIZZLE_OP(t_vec3, wyy); SWIZZLE_OP(t_vec3, wyz); SWIZZLE_OP(t_vec3, wyw);
		SWIZZLE_OP(t_vec3, wzx); SWIZZLE_OP(t_vec3, wzy); SWIZZLE_OP(t_vec3, wzz); SWIZZLE_OP(t_vec3, wzw);
		SWIZZLE_OP(t_vec3, wwx); SWIZZLE_OP(t_vec3, wwy); SWIZZLE_OP(t_vec3, wwz); SWIZZLE_OP(t_vec3, www);

		SWIZZLE_OP(generic_vec4, xxxx); SWIZZLE_OP(generic_vec4, xxxy); SWIZZLE_OP(generic_vec4, xxxz); SWIZZLE_OP(generic_vec4, xxxw);
		SWIZZLE_OP(generic_vec4, xxyx); SWIZZLE_OP(generic_vec4, xxyy); SWIZZLE_OP(generic_vec4, xxyz); SWIZZLE_OP(generic_vec4, xxyw);
		SWIZZLE_OP(generic_vec4, xxzx); SWIZZLE_OP(generic_vec4, xxzy); SWIZZLE_OP(generic_vec4, xxzz); SWIZZLE_OP(generic_vec4, xxzw);
		SWIZZLE_OP(generic_vec4, xxwx); SWIZZLE_OP(generic_vec4, xxwy); SWIZZLE_OP(generic_vec4, xxwz); SWIZZLE_OP(generic_vec4, xxww);

		SWIZZLE_OP(generic_vec4, xyxx); SWIZZLE_OP(generic_vec4, xyxy); SWIZZLE_OP(generic_vec4, xyxz); SWIZZLE_OP(generic_vec4, xyxw);
		SWIZZLE_OP(generic_vec4, xyyx); SWIZZLE_OP(generic_vec4, xyyy); SWIZZLE_OP(generic_vec4, xyyz); SWIZZLE_OP(generic_vec4, xyyw);
		SWIZZLE_OP(generic_vec4, xyzx); SWIZZLE_OP(generic_vec4, xyzy); SWIZZLE_OP(generic_vec4, xyzz); SWIZZLE_OP(generic_vec4, xyzw); 
		SWIZZLE_OP(generic_vec4, xywx); SWIZZLE_OP(generic_vec4, xywy); SWIZZLE_OP(generic_vec4, xywz); SWIZZLE_OP(generic_vec4, xyww);

		SWIZZLE_OP(generic_vec4, xzxx); SWIZZLE_OP(generic_vec4, xzxy); SWIZZLE_OP(generic_vec4, xzxz); SWIZZLE_OP(generic_vec4, xzxw);
		SWIZZLE_OP(generic_vec4, xzyx); SWIZZLE_OP(generic_vec4, xzyy); SWIZZLE_OP(generic_vec4, xzyz); SWIZZLE_OP(generic_vec4, xzyw);
		SWIZZLE_OP(generic_vec4, xzzx); SWIZZLE_OP(generic_vec4, xzzy); SWIZZLE_OP(generic_vec4, xzzz); SWIZZLE_OP(generic_vec4, xzzw);
		SWIZZLE_OP(generic_vec4, xzwx); SWIZZLE_OP(generic_vec4, xzwy); SWIZZLE_OP(generic_vec4, xzwz); SWIZZLE_OP(generic_vec4, xzww);

		SWIZZLE_OP(generic_vec4, xwxx); SWIZZLE_OP(generic_vec4, xwxy); SWIZZLE_OP(generic_vec4, xwxz); SWIZZLE_OP(generic_vec4, xwxw);
		SWIZZLE_OP(generic_vec4, xwyx); SWIZZLE_OP(generic_vec4, xwyy); SWIZZLE_OP(generic_vec4, xwyz); SWIZZLE_OP(generic_vec4, xwyw);
		SWIZZLE_OP(generic_vec4, xwzx); SWIZZLE_OP(generic_vec4, xwzy); SWIZZLE_OP(generic_vec4, xwzz); SWIZZLE_OP(generic_vec4, xwzw);
		SWIZZLE_OP(generic_vec4, xwwx); SWIZZLE_OP(generic_vec4, xwwy); SWIZZLE_OP(generic_vec4, xwwz); SWIZZLE_OP(generic_vec4, xwww);

		SWIZZLE_OP(generic_vec4, yxxx); SWIZZLE_OP(generic_vec4, yxxy); SWIZZLE_OP(generic_vec4, yxxz); SWIZZLE_OP(generic_vec4, yxxw);
		SWIZZLE_OP(generic_vec4, yxyx); SWIZZLE_OP(generic_vec4, yxyy); SWIZZLE_OP(generic_vec4, yxyz); SWIZZLE_OP(generic_vec4, yxyw);
		SWIZZLE_OP(generic_vec4, yxzx); SWIZZLE_OP(generic_vec4, yxzy); SWIZZLE_OP(generic_vec4, yxzz); SWIZZLE_OP(generic_vec4, yxzw);
		SWIZZLE_OP(generic_vec4, yxwx); SWIZZLE_OP(generic_vec4, yxwy); SWIZZLE_OP(generic_vec4, yxwz); SWIZZLE_OP(generic_vec4, yxww);

		SWIZZLE_OP(generic_vec4, yyxx); SWIZZLE_OP(generic_vec4, yyxy); SWIZZLE_OP(generic_vec4, yyxz); SWIZZLE_OP(generic_vec4, yyxw);
		SWIZZLE_OP(generic_vec4, yyyx); SWIZZLE_OP(generic_vec4, yyyy); SWIZZLE_OP(generic_vec4, yyyz); SWIZZLE_OP(generic_vec4, yyyw);
		SWIZZLE_OP(generic_vec4, yyzx); SWIZZLE_OP(generic_vec4, yyzy); SWIZZLE_OP(generic_vec4, yyzz); SWIZZLE_OP(generic_vec4, yyzw);
		SWIZZLE_OP(generic_vec4, yywx); SWIZZLE_OP(generic_vec4, yywy); SWIZZLE_OP(generic_vec4, yywz); SWIZZLE_OP(generic_vec4, yyww);

		SWIZZLE_OP(generic_vec4, yzxx); SWIZZLE_OP(generic_vec4, yzxy); SWIZZLE_OP(generic_vec4, yzxz); SWIZZLE_OP(generic_vec4, yzxw);
		SWIZZLE_OP(generic_vec4, yzyx); SWIZZLE_OP(generic_vec4, yzyy); SWIZZLE_OP(generic_vec4, yzyz); SWIZZLE_OP(generic_vec4, yzyw);
		SWIZZLE_OP(generic_vec4, yzzx); SWIZZLE_OP(generic_vec4, yzzy); SWIZZLE_OP(generic_vec4, yzzz); SWIZZLE_OP(generic_vec4, yzzw);
		SWIZZLE_OP(generic_vec4, yzwx); SWIZZLE_OP(generic_vec4, yzwy); SWIZZLE_OP(generic_vec4, yzwz); SWIZZLE_OP(generic_vec4, yzww);

		SWIZZLE_OP(generic_vec4, ywxx); SWIZZLE_OP(generic_vec4, ywxy); SWIZZLE_OP(generic_vec4, ywxz); SWIZZLE_OP(generic_vec4, ywxw);
		SWIZZLE_OP(generic_vec4, ywyx); SWIZZLE_OP(generic_vec4, ywyy); SWIZZLE_OP(generic_vec4, ywyz); SWIZZLE_OP(generic_vec4, ywyw);
		SWIZZLE_OP(generic_vec4, ywzx); SWIZZLE_OP(generic_vec4, ywzy); SWIZZLE_OP(generic_vec4, ywzz); SWIZZLE_OP(generic_vec4, ywzw);
		SWIZZLE_OP(generic_vec4, ywwx); SWIZZLE_OP(generic_vec4, ywwy); SWIZZLE_OP(generic_vec4, ywwz); SWIZZLE_OP(generic_vec4, ywww);

		SWIZZLE_OP(generic_vec4, zxxx); SWIZZLE_OP(generic_vec4, zxxy); SWIZZLE_OP(generic_vec4, zxxz); SWIZZLE_OP(generic_vec4, zxxw);
		SWIZZLE_OP(generic_vec4, zxyx); SWIZZLE_OP(generic_vec4, zxyy); SWIZZLE_OP(generic_vec4, zxyz); SWIZZLE_OP(generic_vec4, zxyw);
		SWIZZLE_OP(generic_vec4, zxzx); SWIZZLE_OP(generic_vec4, zxzy); SWIZZLE_OP(generic_vec4, zxzz); SWIZZLE_OP(generic_vec4, zxzw);
		SWIZZLE_OP(generic_vec4, zxwx); SWIZZLE_OP(generic_vec4, zxwy); SWIZZLE_OP(generic_vec4, zxwz); SWIZZLE_OP(generic_vec4, zxww);

		SWIZZLE_OP(generic_vec4, zyxx); SWIZZLE_OP(generic_vec4, zyxy); SWIZZLE_OP(generic_vec4, zyxz); SWIZZLE_OP(generic_vec4, zyxw);
		SWIZZLE_OP(generic_vec4, zyyx); SWIZZLE_OP(generic_vec4, zyyy); SWIZZLE_OP(generic_vec4, zyyz); SWIZZLE_OP(generic_vec4, zyyw);
		SWIZZLE_OP(generic_vec4, zyzx); SWIZZLE_OP(generic_vec4, zyzy); SWIZZLE_OP(generic_vec4, zyzz); SWIZZLE_OP(generic_vec4, zyzw);
		SWIZZLE_OP(generic_vec4, zywx); SWIZZLE_OP(generic_vec4, zywy); SWIZZLE_OP(generic_vec4, zywz); SWIZZLE_OP(generic_vec4, zyww);

		SWIZZLE_OP(generic_vec4, zzxx); SWIZZLE_OP(generic_vec4, zzxy); SWIZZLE_OP(generic_vec4, zzxz); SWIZZLE_OP(generic_vec4, zzxw);
		SWIZZLE_OP(generic_vec4, zzyx); SWIZZLE_OP(generic_vec4, zzyy); SWIZZLE_OP(generic_vec4, zzyz); SWIZZLE_OP(generic_vec4, zzyw);
		SWIZZLE_OP(generic_vec4, zzzx); SWIZZLE_OP(generic_vec4, zzzy); SWIZZLE_OP(generic_vec4, zzzz); SWIZZLE_OP(generic_vec4, zzzw);
		SWIZZLE_OP(generic_vec4, zzwx); SWIZZLE_OP(generic_vec4, zzwy); SWIZZLE_OP(generic_vec4, zzwz); SWIZZLE_OP(generic_vec4, zzww);

		SWIZZLE_OP(generic_vec4, zwxx); SWIZZLE_OP(generic_vec4, zwxy); SWIZZLE_OP(generic_vec4, zwxz); SWIZZLE_OP(generic_vec4, zwxw);
		SWIZZLE_OP(generic_vec4, zwyx); SWIZZLE_OP(generic_vec4, zwyy); SWIZZLE_OP(generic_vec4, zwyz); SWIZZLE_OP(generic_vec4, zwyw);
		SWIZZLE_OP(generic_vec4, zwzx); SWIZZLE_OP(generic_vec4, zwzy); SWIZZLE_OP(generic_vec4, zwzz); SWIZZLE_OP(generic_vec4, zwzw);
		SWIZZLE_OP(generic_vec4, zwwx); SWIZZLE_OP(generic_vec4, zwwy); SWIZZLE_OP(generic_vec4, zwwz); SWIZZLE_OP(generic_vec4, zwww);

		SWIZZLE_OP(generic_vec4, wxxx); SWIZZLE_OP(generic_vec4, wxxy); SWIZZLE_OP(generic_vec4, wxxz); SWIZZLE_OP(generic_vec4, wxxw);
		SWIZZLE_OP(generic_vec4, wxyx); SWIZZLE_OP(generic_vec4, wxyy); SWIZZLE_OP(generic_vec4, wxyz); SWIZZLE_OP(generic_vec4, wxyw);
		SWIZZLE_OP(generic_vec4, wxzx); SWIZZLE_OP(generic_vec4, wxzy); SWIZZLE_OP(generic_vec4, wxzz); SWIZZLE_OP(generic_vec4, wxzw);
		SWIZZLE_OP(generic_vec4, wxwx); SWIZZLE_OP(generic_vec4, wxwy); SWIZZLE_OP(generic_vec4, wxwz); SWIZZLE_OP(generic_vec4, wxww);

		SWIZZLE_OP(generic_vec4, wyxx); SWIZZLE_OP(generic_vec4, wyxy); SWIZZLE_OP(generic_vec4, wyxz); SWIZZLE_OP(generic_vec4, wyxw);
		SWIZZLE_OP(generic_vec4, wyyx); SWIZZLE_OP(generic_vec4, wyyy); SWIZZLE_OP(generic_vec4, wyyz); SWIZZLE_OP(generic_vec4, wyyw);
		SWIZZLE_OP(generic_vec4, wyzx); SWIZZLE_OP(generic_vec4, wyzy); SWIZZLE_OP(generic_vec4, wyzz); SWIZZLE_OP(generic_vec4, wyzw);
		SWIZZLE_OP(generic_vec4, wywx); SWIZZLE_OP(generic_vec4, wywy); SWIZZLE_OP(generic_vec4, wywz); SWIZZLE_OP(generic_vec4, wyww);

		SWIZZLE_OP(generic_vec4, wzxx); SWIZZLE_OP(generic_vec4, wzxy); SWIZZLE_OP(generic_vec4, wzxz); SWIZZLE_OP(generic_vec4, wzxw);
		SWIZZLE_OP(generic_vec4, wzyx); SWIZZLE_OP(generic_vec4, wzyy); SWIZZLE_OP(generic_vec4, wzyz); SWIZZLE_OP(generic_vec4, wzyw);
		SWIZZLE_OP(generic_vec4, wzzx); SWIZZLE_OP(generic_vec4, wzzy); SWIZZLE_OP(generic_vec4, wzzz); SWIZZLE_OP(generic_vec4, wzzw);
		SWIZZLE_OP(generic_vec4, wzwx); SWIZZLE_OP(generic_vec4, wzwy); SWIZZLE_OP(generic_vec4, wzwz); SWIZZLE_OP(generic_vec4, wzww);

		SWIZZLE_OP(generic_vec4, wwxx); SWIZZLE_OP(generic_vec4, wwxy); SWIZZLE_OP(generic_vec4, wwxz); SWIZZLE_OP(generic_vec4, wwxw);
		SWIZZLE_OP(generic_vec4, wwyx); SWIZZLE_OP(generic_vec4, wwyy); SWIZZLE_OP(generic_vec4, wwyz); SWIZZLE_OP(generic_vec4, wwyw);
		SWIZZLE_OP(generic_vec4, wwzx); SWIZZLE_OP(generic_vec4, wwzy); SWIZZLE_OP(generic_vec4, wwzz); SWIZZLE_OP(generic_vec4, wwzw);
		SWIZZLE_OP(generic_vec4, wwwx); SWIZZLE_OP(generic_vec4, wwwy); SWIZZLE_OP(generic_vec4, wwwz); SWIZZLE_OP(generic_vec4, wwww);

		SWIZZLE_OP(t_abstract, r); SWIZZLE_OP(t_abstract, g); SWIZZLE_OP(t_abstract, b); SWIZZLE_OP(t_abstract, a);

		SWIZZLE_OP(t_vec2, rr); SWIZZLE_OP(t_vec2, rg); SWIZZLE_OP(t_vec2, rb); SWIZZLE_OP(t_vec2, ra);
		SWIZZLE_OP(t_vec2, gr); SWIZZLE_OP(t_vec2, gg); SWIZZLE_OP(t_vec2, gb); SWIZZLE_OP(t_vec2, ga);
		SWIZZLE_OP(t_vec2, br); SWIZZLE_OP(t_vec2, bg); SWIZZLE_OP(t_vec2, bb); SWIZZLE_OP(t_vec2, ba);
		SWIZZLE_OP(t_vec2, ar); SWIZZLE_OP(t_vec2, ag); SWIZZLE_OP(t_vec2, ab); SWIZZLE_OP(t_vec2, aa);

		SWIZZLE_OP(t_vec3, rrr); SWIZZLE_OP(t_vec3, rrg); SWIZZLE_OP(t_vec3, rrb); SWIZZLE_OP(t_vec3, rra);
		SWIZZLE_OP(t_vec3, rgr); SWIZZLE_OP(t_vec3, rgg); SWIZZLE_OP(t_vec3, rgb); SWIZZLE_OP(t_vec3, rga);
		SWIZZLE_OP(t_vec3, rbr); SWIZZLE_OP(t_vec3, rbg); SWIZZLE_OP(t_vec3, rbb); SWIZZLE_OP(t_vec3, rba);
		SWIZZLE_OP(t_vec3, rar); SWIZZLE_OP(t_vec3, rag); SWIZZLE_OP(t_vec3, rab); SWIZZLE_OP(t_vec3, raa);
		SWIZZLE_OP(t_vec3, grr); SWIZZLE_OP(t_vec3, grg); SWIZZLE_OP(t_vec3, grb); SWIZZLE_OP(t_vec3, gra);
		SWIZZLE_OP(t_vec3, ggr); SWIZZLE_OP(t_vec3, ggg); SWIZZLE_OP(t_vec3, ggb); SWIZZLE_OP(t_vec3, gga);
		SWIZZLE_OP(t_vec3, gbr); SWIZZLE_OP(t_vec3, gbg); SWIZZLE_OP(t_vec3, gbb); SWIZZLE_OP(t_vec3, gba);
		SWIZZLE_OP(t_vec3, gar); SWIZZLE_OP(t_vec3, gag); SWIZZLE_OP(t_vec3, gab); SWIZZLE_OP(t_vec3, gaa);
		SWIZZLE_OP(t_vec3, brr); SWIZZLE_OP(t_vec3, brg); SWIZZLE_OP(t_vec3, brb); SWIZZLE_OP(t_vec3, bra);
		SWIZZLE_OP(t_vec3, bgr); SWIZZLE_OP(t_vec3, bgg); SWIZZLE_OP(t_vec3, bgb); SWIZZLE_OP(t_vec3, bga);
		SWIZZLE_OP(t_vec3, bbr); SWIZZLE_OP(t_vec3, bbg); SWIZZLE_OP(t_vec3, bbb); SWIZZLE_OP(t_vec3, bba);
		SWIZZLE_OP(t_vec3, bar); SWIZZLE_OP(t_vec3, bag); SWIZZLE_OP(t_vec3, bab); SWIZZLE_OP(t_vec3, baa);
		SWIZZLE_OP(t_vec3, arr); SWIZZLE_OP(t_vec3, arg); SWIZZLE_OP(t_vec3, arb); SWIZZLE_OP(t_vec3, ara);
		SWIZZLE_OP(t_vec3, agr); SWIZZLE_OP(t_vec3, agg); SWIZZLE_OP(t_vec3, agb); SWIZZLE_OP(t_vec3, aga);
		SWIZZLE_OP(t_vec3, abr); SWIZZLE_OP(t_vec3, abg); SWIZZLE_OP(t_vec3, abb); SWIZZLE_OP(t_vec3, aba);
		SWIZZLE_OP(t_vec3, aar); SWIZZLE_OP(t_vec3, aag); SWIZZLE_OP(t_vec3, aab); SWIZZLE_OP(t_vec3, aaa);

		SWIZZLE_OP(generic_vec4, rrrr); SWIZZLE_OP(generic_vec4, rrrg); SWIZZLE_OP(generic_vec4, rrrb); SWIZZLE_OP(generic_vec4, rrra);
		SWIZZLE_OP(generic_vec4, rrgr); SWIZZLE_OP(generic_vec4, rrgg); SWIZZLE_OP(generic_vec4, rrgb); SWIZZLE_OP(generic_vec4, rrga);
		SWIZZLE_OP(generic_vec4, rrbr); SWIZZLE_OP(generic_vec4, rrbg); SWIZZLE_OP(generic_vec4, rrbb); SWIZZLE_OP(generic_vec4, rrba);
		SWIZZLE_OP(generic_vec4, rrar); SWIZZLE_OP(generic_vec4, rrag); SWIZZLE_OP(generic_vec4, rrab); SWIZZLE_OP(generic_vec4, rraa);

		SWIZZLE_OP(generic_vec4, rgrr); SWIZZLE_OP(generic_vec4, rgrg); SWIZZLE_OP(generic_vec4, rgrb); SWIZZLE_OP(generic_vec4, rgra);
		SWIZZLE_OP(generic_vec4, rggr); SWIZZLE_OP(generic_vec4, rggg); SWIZZLE_OP(generic_vec4, rggb); SWIZZLE_OP(generic_vec4, rgga);
		SWIZZLE_OP(generic_vec4, rgbr); SWIZZLE_OP(generic_vec4, rgbg); SWIZZLE_OP(generic_vec4, rgbb); SWIZZLE_OP(generic_vec4, rgba);
		SWIZZLE_OP(generic_vec4, rgar); SWIZZLE_OP(generic_vec4, rgag); SWIZZLE_OP(generic_vec4, rgab); SWIZZLE_OP(generic_vec4, rgaa);

		SWIZZLE_OP(generic_vec4, rbrr); SWIZZLE_OP(generic_vec4, rbrg); SWIZZLE_OP(generic_vec4, rbrb); SWIZZLE_OP(generic_vec4, rbra);
		SWIZZLE_OP(generic_vec4, rbgr); SWIZZLE_OP(generic_vec4, rbgg); SWIZZLE_OP(generic_vec4, rbgb); SWIZZLE_OP(generic_vec4, rbga);
		SWIZZLE_OP(generic_vec4, rbbr); SWIZZLE_OP(generic_vec4, rbbg); SWIZZLE_OP(generic_vec4, rbbb); SWIZZLE_OP(generic_vec4, rbba);
		SWIZZLE_OP(generic_vec4, rbar); SWIZZLE_OP(generic_vec4, rbag); SWIZZLE_OP(generic_vec4, rbab); SWIZZLE_OP(generic_vec4, rbaa);

		SWIZZLE_OP(generic_vec4, rarr); SWIZZLE_OP(generic_vec4, rarg); SWIZZLE_OP(generic_vec4, rarb); SWIZZLE_OP(generic_vec4, rara);
		SWIZZLE_OP(generic_vec4, ragr); SWIZZLE_OP(generic_vec4, ragg); SWIZZLE_OP(generic_vec4, ragb); SWIZZLE_OP(generic_vec4, raga);
		SWIZZLE_OP(generic_vec4, rabr); SWIZZLE_OP(generic_vec4, rabg); SWIZZLE_OP(generic_vec4, rabb); SWIZZLE_OP(generic_vec4, raba);
		SWIZZLE_OP(generic_vec4, raar); SWIZZLE_OP(generic_vec4, raag); SWIZZLE_OP(generic_vec4, raab); SWIZZLE_OP(generic_vec4, raaa);

		SWIZZLE_OP(generic_vec4, grrr); SWIZZLE_OP(generic_vec4, grrg); SWIZZLE_OP(generic_vec4, grrb); SWIZZLE_OP(generic_vec4, grra);
		SWIZZLE_OP(generic_vec4, grgr); SWIZZLE_OP(generic_vec4, grgg); SWIZZLE_OP(generic_vec4, grgb); SWIZZLE_OP(generic_vec4, grga);
		SWIZZLE_OP(generic_vec4, grbr); SWIZZLE_OP(generic_vec4, grbg); SWIZZLE_OP(generic_vec4, grbb); SWIZZLE_OP(generic_vec4, grba);
		SWIZZLE_OP(generic_vec4, grar); SWIZZLE_OP(generic_vec4, grag); SWIZZLE_OP(generic_vec4, grab); SWIZZLE_OP(generic_vec4, graa);

		SWIZZLE_OP(generic_vec4, ggrr); SWIZZLE_OP(generic_vec4, ggrg); SWIZZLE_OP(generic_vec4, ggrb); SWIZZLE_OP(generic_vec4, ggra);
		SWIZZLE_OP(generic_vec4, gggr); SWIZZLE_OP(generic_vec4, gggg); SWIZZLE_OP(generic_vec4, gggb); SWIZZLE_OP(generic_vec4, ggga);
		SWIZZLE_OP(generic_vec4, ggbr); SWIZZLE_OP(generic_vec4, ggbg); SWIZZLE_OP(generic_vec4, ggbb); SWIZZLE_OP(generic_vec4, ggba);
		SWIZZLE_OP(generic_vec4, ggar); SWIZZLE_OP(generic_vec4, ggag); SWIZZLE_OP(generic_vec4, ggab); SWIZZLE_OP(generic_vec4, ggaa);

		SWIZZLE_OP(generic_vec4, gbrr); SWIZZLE_OP(generic_vec4, gbrg); SWIZZLE_OP(generic_vec4, gbrb); SWIZZLE_OP(generic_vec4, gbra);
		SWIZZLE_OP(generic_vec4, gbgr); SWIZZLE_OP(generic_vec4, gbgg); SWIZZLE_OP(generic_vec4, gbgb); SWIZZLE_OP(generic_vec4, gbga);
		SWIZZLE_OP(generic_vec4, gbbr); SWIZZLE_OP(generic_vec4, gbbg); SWIZZLE_OP(generic_vec4, gbbb); SWIZZLE_OP(generic_vec4, gbba);
		SWIZZLE_OP(generic_vec4, gbar); SWIZZLE_OP(generic_vec4, gbag); SWIZZLE_OP(generic_vec4, gbab); SWIZZLE_OP(generic_vec4, gbaa);

		SWIZZLE_OP(generic_vec4, garr); SWIZZLE_OP(generic_vec4, garg); SWIZZLE_OP(generic_vec4, garb); SWIZZLE_OP(generic_vec4, gara);
		SWIZZLE_OP(generic_vec4, gagr); SWIZZLE_OP(generic_vec4, gagg); SWIZZLE_OP(generic_vec4, gagb); SWIZZLE_OP(generic_vec4, gaga);
		SWIZZLE_OP(generic_vec4, gabr); SWIZZLE_OP(generic_vec4, gabg); SWIZZLE_OP(generic_vec4, gabb); SWIZZLE_OP(generic_vec4, gaba);
		SWIZZLE_OP(generic_vec4, gaar); SWIZZLE_OP(generic_vec4, gaag); SWIZZLE_OP(generic_vec4, gaab); SWIZZLE_OP(generic_vec4, gaaa);

		SWIZZLE_OP(generic_vec4, brrr); SWIZZLE_OP(generic_vec4, brrg); SWIZZLE_OP(generic_vec4, brrb); SWIZZLE_OP(generic_vec4, brra);
		SWIZZLE_OP(generic_vec4, brgr); SWIZZLE_OP(generic_vec4, brgg); SWIZZLE_OP(generic_vec4, brgb); SWIZZLE_OP(generic_vec4, brga);
		SWIZZLE_OP(generic_vec4, brbr); SWIZZLE_OP(generic_vec4, brbg); SWIZZLE_OP(generic_vec4, brbb); SWIZZLE_OP(generic_vec4, brba);
		SWIZZLE_OP(generic_vec4, brar); SWIZZLE_OP(generic_vec4, brag); SWIZZLE_OP(generic_vec4, brab); SWIZZLE_OP(generic_vec4, braa);

		SWIZZLE_OP(generic_vec4, bgrr); SWIZZLE_OP(generic_vec4, bgrg); SWIZZLE_OP(generic_vec4, bgrb); SWIZZLE_OP(generic_vec4, bgra);
		SWIZZLE_OP(generic_vec4, bggr); SWIZZLE_OP(generic_vec4, bggg); SWIZZLE_OP(generic_vec4, bggb); SWIZZLE_OP(generic_vec4, bgga);
		SWIZZLE_OP(generic_vec4, bgbr); SWIZZLE_OP(generic_vec4, bgbg); SWIZZLE_OP(generic_vec4, bgbb); SWIZZLE_OP(generic_vec4, bgba);
		SWIZZLE_OP(generic_vec4, bgar); SWIZZLE_OP(generic_vec4, bgag); SWIZZLE_OP(generic_vec4, bgab); SWIZZLE_OP(generic_vec4, bgaa);

		SWIZZLE_OP(generic_vec4, bbrr); SWIZZLE_OP(generic_vec4, bbrg); SWIZZLE_OP(generic_vec4, bbrb); SWIZZLE_OP(generic_vec4, bbra);
		SWIZZLE_OP(generic_vec4, bbgr); SWIZZLE_OP(generic_vec4, bbgg); SWIZZLE_OP(generic_vec4, bbgb); SWIZZLE_OP(generic_vec4, bbga);
		SWIZZLE_OP(generic_vec4, bbbr); SWIZZLE_OP(generic_vec4, bbbg); SWIZZLE_OP(generic_vec4, bbbb); SWIZZLE_OP(generic_vec4, bbba);
		SWIZZLE_OP(generic_vec4, bbar); SWIZZLE_OP(generic_vec4, bbag); SWIZZLE_OP(generic_vec4, bbab); SWIZZLE_OP(generic_vec4, bbaa);

		SWIZZLE_OP(generic_vec4, barr); SWIZZLE_OP(generic_vec4, barg); SWIZZLE_OP(generic_vec4, barb); SWIZZLE_OP(generic_vec4, bara);
		SWIZZLE_OP(generic_vec4, bagr); SWIZZLE_OP(generic_vec4, bagg); SWIZZLE_OP(generic_vec4, bagb); SWIZZLE_OP(generic_vec4, baga);
		SWIZZLE_OP(generic_vec4, babr); SWIZZLE_OP(generic_vec4, babg); SWIZZLE_OP(generic_vec4, babb); SWIZZLE_OP(generic_vec4, baba);
		SWIZZLE_OP(generic_vec4, baar); SWIZZLE_OP(generic_vec4, baag); SWIZZLE_OP(generic_vec4, baab); SWIZZLE_OP(generic_vec4, baaa);

		SWIZZLE_OP(generic_vec4, arrr); SWIZZLE_OP(generic_vec4, arrg); SWIZZLE_OP(generic_vec4, arrb); SWIZZLE_OP(generic_vec4, arra);
		SWIZZLE_OP(generic_vec4, argr); SWIZZLE_OP(generic_vec4, argg); SWIZZLE_OP(generic_vec4, argb); SWIZZLE_OP(generic_vec4, arga);
		SWIZZLE_OP(generic_vec4, arbr); SWIZZLE_OP(generic_vec4, arbg); SWIZZLE_OP(generic_vec4, arbb); SWIZZLE_OP(generic_vec4, arba);
		SWIZZLE_OP(generic_vec4, arar); SWIZZLE_OP(generic_vec4, arag); SWIZZLE_OP(generic_vec4, arab); SWIZZLE_OP(generic_vec4, araa);

		SWIZZLE_OP(generic_vec4, agrr); SWIZZLE_OP(generic_vec4, agrg); SWIZZLE_OP(generic_vec4, agrb); SWIZZLE_OP(generic_vec4, agra);
		SWIZZLE_OP(generic_vec4, aggr); SWIZZLE_OP(generic_vec4, aggg); SWIZZLE_OP(generic_vec4, aggb); SWIZZLE_OP(generic_vec4, agga);
		SWIZZLE_OP(generic_vec4, agbr); SWIZZLE_OP(generic_vec4, agbg); SWIZZLE_OP(generic_vec4, agbb); SWIZZLE_OP(generic_vec4, agba);
		SWIZZLE_OP(generic_vec4, agar); SWIZZLE_OP(generic_vec4, agag); SWIZZLE_OP(generic_vec4, agab); SWIZZLE_OP(generic_vec4, agaa);

		SWIZZLE_OP(generic_vec4, abrr); SWIZZLE_OP(generic_vec4, abrg); SWIZZLE_OP(generic_vec4, abrb); SWIZZLE_OP(generic_vec4, abra);
		SWIZZLE_OP(generic_vec4, abgr); SWIZZLE_OP(generic_vec4, abgg); SWIZZLE_OP(generic_vec4, abgb); SWIZZLE_OP(generic_vec4, abga);
		SWIZZLE_OP(generic_vec4, abbr); SWIZZLE_OP(generic_vec4, abbg); SWIZZLE_OP(generic_vec4, abbb); SWIZZLE_OP(generic_vec4, abba);
		SWIZZLE_OP(generic_vec4, abar); SWIZZLE_OP(generic_vec4, abag); SWIZZLE_OP(generic_vec4, abab); SWIZZLE_OP(generic_vec4, abaa);

		SWIZZLE_OP(generic_vec4, aarr); SWIZZLE_OP(generic_vec4, aarg); SWIZZLE_OP(generic_vec4, aarb); SWIZZLE_OP(generic_vec4, aara);
		SWIZZLE_OP(generic_vec4, aagr); SWIZZLE_OP(generic_vec4, aagg); SWIZZLE_OP(generic_vec4, aagb); SWIZZLE_OP(generic_vec4, aaga);
		SWIZZLE_OP(generic_vec4, aabr); SWIZZLE_OP(generic_vec4, aabg); SWIZZLE_OP(generic_vec4, aabb); SWIZZLE_OP(generic_vec4, aaba);
		SWIZZLE_OP(generic_vec4, aaar); SWIZZLE_OP(generic_vec4, aaag); SWIZZLE_OP(generic_vec4, aaab); SWIZZLE_OP(generic_vec4, aaaa);
		
		generic_vec4(VariableType type, const std::string& name, Swizzle swizzle) :
			Type(type, vec_detail::glsl_type_string(), name),
			m_Swizzle(swizzle)
		{
		}
			
		generic_vec4(const std::string& temporaryInitialization) :
			Type(Temporary, "vec4", currentProgram->GenerateName()),
			m_TemporaryInitialization(temporaryInitialization)
		{
		}			

		std::string ExtendedName() const
		{
			if (GetType() == Temporary)
			{
				return m_TemporaryInitialization;
			}

			if (!m_Declared)
			{
				throw UseBeforeAssignment();
			}

			return GetName();
		}

		private:
		bool m_Declared = false;
		std::string m_TemporaryInitialization;
		Swizzle m_Swizzle = Swizzle::NoSwizzle;

	};

	class vec4_int_detail
	{

		public:
		typedef int native_type;
		typedef GenType<gentype_int_detail> abstract_type;
		typedef vec2_int_detail vec2_detail;
		typedef vec3_int_detail vec3_detail;

		static inline const char* glsl_type_string()
		{
			return "ivec4";
		}

	};

	class vec4_float_detail
	{

		public:
		typedef float native_type;
		typedef GenType<gentype_float_detail> abstract_type;
		typedef vec2_float_detail vec2_detail;
		typedef vec3_float_detail vec3_detail;

		static inline const char* glsl_type_string()
		{
			return "vec4";
		}

	};

	typedef generic_vec4<vec4_float_detail> vec4;
	typedef generic_vec4<vec4_int_detail> ivec4;

}

#endif
