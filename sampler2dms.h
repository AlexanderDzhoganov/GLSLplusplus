#ifndef __GLSLPP_SAMPLER2DMS_H
#define __GLSLPP_SAMPLER2DMS_H

namespace GLSLPP
{

	class sampler2DMS : public Type
	{

		friend vec4 texture(const sampler2DMS&, const vec2&);
		friend vec4 texelFetch(const sampler2DMS& sampler, const ivec2& texCoords, const Int& lod);
		friend vec4 texelFetch(const sampler2DMS& sampler, const ivec2& texCoords, int lod);

		public:
		explicit sampler2DMS(VariableQualifier type) : Type(type, "sampler2DMS", currentProgram->GenerateName())
		{
		} 

		sampler2DMS(VariableQualifier type, const std::string& name) : Type(type, "sampler2DMS", name)
		{
		}

	};

}

#endif
