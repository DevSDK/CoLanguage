#include <iostream>

#include "Source\Parser\Lexer.h"

#include <clocale>
#include <regex>
#include <Windows.h>
using namespace std;







int main()
{
	setlocale(LC_ALL, "");
	wcin.imbue(locale(""));
	wcout.imbue(locale(""));
	Lexer lex;
	TokenSet tok;
	wcout << lex.TESTER << endl;
	while ((tok = lex.NextToken()).Token != Lexer::T_EOF)
	{
		if(tok.Token == Lexer::T_KEYWORD)
			wcout << "KEYWORD- "<<tok.Value << endl;
		else if (tok.Token == Lexer::T_IDENTIFIER)
			wcout << "IDENTIFIER- " << tok.Value << endl;
		else if(tok.Token == Lexer::T_OPERATOR)
			wcout << "OPERATOR- " << tok.Value << endl;
		else if (tok.Token == Lexer::T_STRINGLITERAL)
			wcout << "STRING LIT- " << tok.Value << endl;


	}
	system("pause");

}