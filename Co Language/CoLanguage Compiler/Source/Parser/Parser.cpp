
#include "Parser.h"

using namespace col;

Parser::Parser(Lexer & lex) : lexer(lex)
{
		
}

Node * Parser::Parse()
{

	TokenSet tok;
	while ((tok = lexer.NextToken()).Token != Lexer::Tokens::T_EOF)
	{
		
	}
}


Parser::~Parser()
{
	if(AST)
		delete AST;
}