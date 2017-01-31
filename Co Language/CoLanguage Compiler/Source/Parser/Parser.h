#ifndef _DEF_PARSER_H_
#define _DEF_PARSER_H_
#include "Lexer.h"
#include "..\Tree\Node.h"
namespace col
{

	class Parser
	{
	public:
		Parser(Lexer &);
		Node* Parse();
		~Parser();

	private:
		Lexer & lexer;

		Node * AST = nullptr;
		std::vector<Node*> Stack;
		int Stat =0;
	};

}



#endif



