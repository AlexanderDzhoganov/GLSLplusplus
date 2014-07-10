#ifndef __GLSLPP_GLSL_H
#define __GLSLPP_GLSL_H

#include <exception>
#include <string>
#include <sstream>

namespace GLSLPP
{
	
	class Program;
	extern Program* currentProgram;

}

#include "stringutil.h"
#include "exception.h"
#include "forwarddeclarations.h"
#include "program.h"
#include "type.h"
#include "swizzle.h"
#include "detail.h"
#include "gentype.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat2.h"
#include "mat3.h"
#include "mat4.h"
#include "sampler2d.h"
#include "sampler2dms.h"
#include "trig_functions.h"
#include "exp_functions.h"
#include "common_functions.h"
#include "geom_functions.h"
#include "matrix_functions.h"
#include "vector_rel_functions.h"
#include "integer_functions.h"
#include "tex_query_functions.h"
#include "tex_lookup_functions.h"
#include "tex_gather_functions.h"
#include "compat_tex_functions.h"
#include "atom_count_functions.h"
#include "atom_memory_functions.h"
#include "image_functions.h"
#include "frag_process_functions.h"
#include "noise_functions.h"
#include "geom_shader_functions.h"
#include "shader_control_functions.h"
#include "functions.h"
#include "operators.h"
#include "controlflow.h"

#endif
