#ifndef __LEXER_H__
#define __LEXER_H__
#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <fstream>



struct TokenSet;

class Lexer
{

public:
		
	static enum Tokens
	{
		KEYWORD,

		OPERATOR,

		IDENTIFIER,
		NUMBER,
		STRINGLITERAL

	};
	~Lexer()
	{

	}

	TokenSet NextToken();
	wstring test = L"import a.b.c;  class {  /*a aa */  void main() {  string a = \"HI! 아\"; }    } ";
	int Curser;

	wregex letter = wregex(L"[^0-9|!|@|#|$|%|^|&|*|(|)|/|\||?|>|<|-|=|;|\"|\'|\\[\\]|`]");


	const std::vector<std::string> token_string_set = { "import", "class", "case", "component", "continue", "if", "interface", "else"
	,"enum","return", "switch","for", "jump", "break", "new", "old", "public", "protected", "private", "static",  "default", "while"
	 };


	const char * token_import = "import";
	const char * token_class = "class";
	const char * token_case = "case";
	const char * token_component = "component";
	const char * token_continue = "continue";
	const char * token_if = "if";
	const char * token_interface = "interface";
	const char * token_else = "else";
	const char * token_enum = "enum";
	const char * token_return = "return";
	const char * token_switch = "switch";
	const char * token_for = "for";
	const char * token_jump = "jump";
	const char * token_break = "break";
	const char * token_new = "new";
	const char * token_old = "old";
	const char * token_public = "public";
	const char * token_protected = "protected";
	const char * token_private = "private";
	const char * token_static = "static";
	const char * token_default = "default";
	const char * token_while = "while";



private:
	wchar_t nextChar();


private:
	std::wstring LexingString;

};
struct TokenSet
{
	Lexer::Tokens Token;
	std::string Value;
};




#endif
