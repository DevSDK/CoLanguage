#ifndef __LEXER_H__
#define __LEXER_H__
#include <iostream>
#include <istream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <cwchar>
#include <fstream>

namespace col
{

	struct TokenSet;

	class Lexer
	{

	public:

		static enum Tokens
		{
			T_EOF = 256,
			T_KEYWORD,
			T_OPERATOR,
			T_IDENTIFIER,
			T_INTEGER_CONST,
			T_FLOAT_CONST,
			T_DOUBLE_CONST,
			T_STRINGLITERAL,
			T_CHAR_CONST,
			T_TOKEN

		};
		~Lexer()
		{

		}

		TokenSet NextToken();

		const std::wstring TESTER = L"import a.b.c;  \n\
		class abc\n\
		{ \n\
			/*a aa */ \n\
			 void main() \n\
			{ \n \
				string a =  \"HI! \\\" 아\"; \n\
				int b = 10; \n\
				float fv = 10.1f;\n\
				double ff = 110.100;\n\
				char c = 'a' \n\
				char eq = '\\\"' \n\
			}   \n\
		} ";
		int Curser = 0;

		std::wregex letter = std::wregex(L"[^0-9|!|@|#|$|%|^|&|*|(|)|.|,|/|\||?|>|<|-|=|;|\"|\'|\\[\\]|`| |\{|\}|\t|\n]");
		std::wregex digit = std::wregex(L"[0-9]");

		const std::vector<std::wstring> token_string_set = { L"import", L"class", L"case", L"component", L"continue", L"if", L"interface", L"else"
		,L"enum",L"return", L"switch",L"for", L"jump", L"break", L"new", L"old", L"public", L"protected", L"private", L"static",  L"default", L"while"
		, L"do" };


		const wchar_t * token_import = L"import";
		const wchar_t * token_class = L"class";
		const wchar_t * token_case = L"case";
		const wchar_t * token_component = L"component";
		const wchar_t * token_continue = L"continue";
		const wchar_t * token_if = L"if";
		const wchar_t * token_interface = L"interface";
		const wchar_t * token_else = L"else";
		const wchar_t * token_enum = L"enum";
		const wchar_t * token_return = L"return";
		const wchar_t * token_switch = L"switch";
		const wchar_t * token_for = L"for";
		const wchar_t * token_jump = L"jump";
		const wchar_t * token_break = L"break";
		const wchar_t * token_new = L"new";
		const wchar_t * token_old = L"old";
		const wchar_t * token_public = L"public";
		const wchar_t * token_protected = L"protected";
		const wchar_t * token_private = L"private";
		const wchar_t * token_static = L"static";
		const wchar_t * token_default = L"default";
		const wchar_t * token_while = L"while";
		const wchar_t * token_do = L"do";



	private:
		wchar_t nextChar();
		wchar_t LookAhead(int);
		bool isLetter(wchar_t);
		bool isDigit(wchar_t);
		bool char_Regex(wchar_t, std::wregex);
	private:
		std::wstring LexingString;
		bool isComment = false;
		bool isString = false;
		int Status = 0;
		int LineNo = 1;
	};
	struct TokenSet
	{
		Lexer::Tokens Token;
		std::wstring Value;
		int LineNo = 0;
	};

}



#endif
