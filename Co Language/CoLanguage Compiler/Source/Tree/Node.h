#ifndef _DEF_NODE_H_
#define _DEF_NODE_H_

#include "Visitor\Visitor.h"

class Node
{
	enum NODE_ENUM;
public:

	virtual void accept(Visitor * vis) = 0;

private:
	NODE_ENUM Type;
	
public:
	
	NODE_ENUM getType()
	{
		return Type;
	}



	enum NODE_ENUM
	{
		N_NULL,N_PROGRAM, N_AST, N_EXPRESSION, N_ABSTRACT_ASSIGN,
		N_ASSIGN, N_ASSIGN_OP, N_BINARY_OP, LOGICAL_AND, LOGICAL_OR,
		N_CAST, N_COND_EXPR, N_FUNC_CALL_EXPR, N_LHS, N_ARRAY_INDEX, N_MEMBER, N_VARIABLE,
		N_LITERAL, N_INTEGER_LITERAL, N_STRING_LITERAL, N_FLOAT_LITERAL,
		N_DOUBLE_LITERAL, N_CHAR_LITERAL, N_INSTANCE_OP, N_UNARY, N_PREFIX_OP, N_POSTFIX_OP,
		N_OBJECT, N_NEW_OP, N_OLD_OP, N_SEMENTIC, N_IF, N_FOR, N_WHILE, N_DO_WHILE, N_EXPR_STMT, N_JUMP,
		N_RETURN, N_SWITCH, N_CONTINUE, N_BREAK, N_CASE, N_BLOCK, N_DEFALUT, N_DEFINITION,
		N_CLASS_DEFINITION, N_COMPONENT_DEFINITION, N_INTERFACE_DEFINITION
	};


};

#endif
