#include <iostream>

#include "Source\Parser\Lexer.h"

#include <clocale>
#include <regex>
#include <Windows.h>
using namespace std;
using namespace col;






int main()
{
	setlocale(LC_ALL, "");
	wcin.imbue(locale(""));
	wcout.imbue(locale(""));
	Lexer lex;
	TokenSet tok;
	wcout << lex.TESTER << endl;
	



	system("pause");

}