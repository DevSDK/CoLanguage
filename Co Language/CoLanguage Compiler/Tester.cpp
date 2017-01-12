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
			wcout << "LINE NO :  " <<tok.LineNo <<"  KEYWORD- "<<tok.Value << endl;
		else if (tok.Token == Lexer::T_IDENTIFIER)
			wcout << "LINE NO :  " << tok.LineNo << "  IDENTIFIER- " << tok.Value << endl;
		else if(tok.Token == Lexer::T_OPERATOR)
			wcout << "LINE NO :  " << tok.LineNo << "  OPERATOR- " << tok.Value << endl;
		else if (tok.Token == Lexer::T_STRINGLITERAL)
			wcout << "LINE NO :  " << tok.LineNo << "  STRING LIT- " << tok.Value << endl;
		else if (tok.Token == Lexer::T_TOKEN)
			wcout << "LINE NO :  " << tok.LineNo << "  TOKEN- " << tok.Value << endl;
		else if(tok.Token == Lexer::T_INTEGER_CONST)
			wcout << "LINE NO :  " << tok.LineNo << "  INTEGER- " << tok.Value << endl;
		else if (tok.Token == Lexer::T_FLOAT_CONST)
			wcout << "LINE NO :  " << tok.LineNo << "  FLOAT- " << tok.Value << endl;
		else if (tok.Token == Lexer::T_DOUBLE_CONST)
			wcout << "LINE NO :  " << tok.LineNo << "DOUBLE- " << tok.Value << endl;


	}
	system("pause");

}