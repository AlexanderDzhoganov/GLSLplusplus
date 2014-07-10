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
#include "functions.h"
#include "operators.h"
#include "controlflow.h"

#endif
