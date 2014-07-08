#ifndef __GLSLPP_SAMPLER2D_H
#define __GLSLPP_SAMPLER2D_H

namespace GLSLPP
{

	class sampler2D : public Type
	{

		template <typename vec_detail>
		friend generic_vec4<vec_detail> texture(const sampler2D&, const vec2&);
		friend vec4 texelFetch(const sampler2D& sampler, const ivec2& texCoords, const Int& lod);
		friend vec4 texelFetch(const sampler2D& sampler, const ivec2& texCoords, int lod);

		public:
		explicit sampler2D(VariableType type) :
			Type(type, "sampler2D", currentProgram->GenerateName())
		{
		}

		sampler2D(VariableType type, int layoutLocation) :
			Type(type, "sampler2D", currentProgram->GenerateName(), layoutLocation)
		{
		}

		sampler2D(VariableType type, const std::string& name) :
			Type(type, "sampler2D", name)
		{
		}

		sampler2D(VariableType type, const std::string& name, int layoutLocation) :
			Type(type, "sampler2D", name, layoutLocation)
		{
		}

	};

}

#endif
