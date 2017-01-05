#include "Source\Parser\Lexer.h"
#include "boost\algorithm\string.hpp"
using namespace std;


vector<Lexer::Tokens> Lexer::Parse(istream is)
{
	std::istreambuf_iterator<char> eos;
	std::string str(std::istreambuf_iterator<char>(is), eos);
	Parse(str);
}

vector<Lexer::Tokens> Lexer::Parse(std::ifstream fs)
{
	std::string str((std::istreambuf_iterator<char>(fs)),
		std::istreambuf_iterator<char>());
	Parse(str);
}

vector<Lexer::Tokens> Lexer::Parse(string &str)
{
	vector<string> tokedString;
}


Lexer::Tokens Lexer::GetToken(string& tokstr)
{

}