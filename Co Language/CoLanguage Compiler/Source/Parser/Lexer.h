#ifndef __LEXER_H__
#define __LEXER_H__
#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <fstream>

class Lexer
{

public:

	static enum Tokens
	{
		TOKEN_IMPORT = 200,
		TOKEN_CLASS,
		TOKEN_IF,
		TOKEN_ELSE,
		TOKEN_RETURN,

		TOKEN_SWITCH,
		TOKEN_CASE,
		TOKEN_FOR,
		TOKEN_WHILE,
		TOKEN_JUMP,
		TOKEN_COMPONENT,
		TOKEN_CONTINUE,
		TOKEN_DEFAULT,
		TOKEN_ENUM,
		TOKEN_INTERFACE,
		TOKEN_BREAK,
		TOKEN_NEW,
		TOKEN_DELETE,
		TOKEN_STATIC,
		TOKEN_PUBLIC,
		TOKEN_PRIVATE,
		TOKEN_PROTECTED,


		PLUS, // +
		PLUSPLUS, //++
		MINUS, // -
		MINUSMINUS,//--
		STAR, // *
		DIV, // /
		REMAIN,// %
		LOWER, // <
		LOWER_EQUAL, // <=
		GREATER, // >
		GREATER_EQUAL, // >=
		EQUALEQAL, // ==
		EQUAL_NOT, // !=
		DOT, // .
		COMMA, // ,
		BEGIN_PAR, // (
		END_PAR, // )
		BEGIN_INDEX, //[
		END_INDEX, // ]
		AND, // &
		ANDAND, // &&
		OR, //|
		OROR, //||
		NOT, //!
		BIT_NOT, // ~
		XOR, // ^
		LSHIFT, // <<
		RSHIFT, // >>
		LOGICAL_OPERATOR, // ?( ) :

		EQUAL, // =
		ADDEQUAL, // +=
		MINUSQAUL, // -=
		MULEQUAL, // *=
		DIVEQUAL, // /=


		IDENTIFIER,
		STRINGLITERAL

	};

public:
	
	std::vector<Tokens> Parse(std::istream);
	std::vector<Tokens> Parse(std::string&);
	std::vector<Tokens> Parse(std::ifstream );





private:
	
	Tokens GetToken(std::string& tokstr);

};




#endif
