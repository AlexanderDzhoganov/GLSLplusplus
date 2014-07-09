#ifndef __GLSLPP_CONTROLFLOW_H
#define __GLSLPP_CONTROLFLOW_H

namespace GLSLPP
{

	enum GLSLCondition
	{
		Equal,
		NotEqual,
		GreaterOrEqual,
		LessOrEqual,
		Greater,
		Less
	};

	inline std::string ConditionToString(GLSLCondition condition)
	{
		switch (condition)
		{
		case Equal:
			return "==";
		case NotEqual:
			return "!=";
		case GreaterOrEqual:
			return ">=";
		case LessOrEqual:
			return "<=";
		case Greater:
			return ">";
		case Less:
			return "<";
		}

		return "==";
	}

	template <typename A, typename B, typename F>
	void if_(const A& a, GLSLCondition condition, const B& b, F f)
	{
		currentProgram->InjectCode(xs("if (% % %)\n    {\n", a.ExtendedName(), ConditionToString(condition), b.ExtendedName()), false);
		f();
		currentProgram->InjectCode("}\n", false);
	}

	template <typename A, typename B, typename F>
	void while_(const A& a, GLSLCondition condition, const B& b, F f)
	{
		currentProgram->InjectCode(xs("while (% % %)\n    {\n", a.ExtendedName(), ConditionToString(condition), b.ExtendedName()), false);
		f();
		currentProgram->InjectCode("}\n", false);
	}

}

#endif
