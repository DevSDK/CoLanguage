#include "Lexer.h"
#include "boost\algorithm\string.hpp"
#include <regex>


using namespace std;

TokenSet Lexer::NextToken()
{

}

wchar_t Lexer::nextChar()
{

		if (test[Curser] == L'\0')
			return EOF;

		Curser++;
		return test[Curser++];
}



