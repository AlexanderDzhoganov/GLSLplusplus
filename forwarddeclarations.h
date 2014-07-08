#ifndef __GLSLPP_FORWARDDECLARATIONS_H
#define __GLSLPP_FORWARDDECLARATIONS_H

namespace GLSLPP
{

	template <typename vec_detail>
	class generic_vec4;

	class vec4_float_detail;

	typedef generic_vec4<vec4_float_detail> vec4;

}

#endif
