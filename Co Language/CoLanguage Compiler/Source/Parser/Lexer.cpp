#include "Lexer.h"
#include <strstream>
#include <regex>
#include <algorithm>


using namespace std;

TokenSet Lexer::NextToken()
{
	wchar_t c = 0;
	while ((c = nextChar()) != L'\0')
	{
		wstringstream strstm;
		if (isString)
		{
			while (isString)
			{
				if (c == L'\0')
					break;
				else if (c == L'\\')
				{
					if (LookAhead(0) == L'"')
					{
						strstm << L'"';
						c = nextChar();
						c = nextChar();
						continue;
					}
				}
				else if (c == L'"')
				{
						isString = false;
						TokenSet tok;
						tok.Token = T_STRINGLITERAL;
						tok.Value = strstm.str();
						return tok;
				}
				strstm << c;
				c = nextChar();
			}
		}
		else if (isLetter(c))
		{
			if (isComment)
				continue;
			strstm << c;
			while ((c = nextChar()) != L'\0' && (isLetter(c) || isDigit(c)))
			{
				strstm << c;
			}
			if (find(token_string_set.begin(), token_string_set.end(), strstm.str()) != token_string_set.end())
			{
				TokenSet tok;
				tok.Token = T_KEYWORD;
				tok.Value = strstm.str();
				return tok;
			}
			TokenSet tok;
			tok.Token = T_IDENTIFIER;
			tok.Value = strstm.str();
			return tok;
		}
		else
		{
			TokenSet tok;
		
			if (c == L'"')
			{
				isString = !isString;
				continue;
			}
			if (c == L'*')
			{
				c = LookAhead(0);
				if (c == L'\0')
					continue;
				else if (c == L'/')
				{
					nextChar();
					isComment = false;
					continue;
				}
				else if (c == L'=')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"*=";
					return tok;
				}
				else
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"*";
					return tok;
				}
			}
			if (isComment)
				continue;
			if (c == L'/')
			{
				c = LookAhead(0);
				if (c == L'\0')
					continue;
				else if (c == L'*')
				{
					nextChar();
					isComment = true;
					continue;
				}
				else if (c == L'=')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"/=";
					return tok;
				}
				else
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"/";
					return tok;
				}
			}

			if (c == L'=')
			{
				c = LookAhead(0);
				if (c == L'\0')
					continue;
				if (c == L'=')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"==";
					return tok;
				}
				else
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"=";
					return tok;
				}
			}
			if (c == L'+')
			{
				c = LookAhead(0);
				if (c == L'\0')
					continue;

				if (c == L'=')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"+=";
					return tok;
				}
				else if (c == L'+')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"++";
					return tok;
				}
				else
				{
					tok.Token = T_OPERATOR;
					tok.Value = L"+";
					return tok;
				}
			}
			if (c == L'-')
			{
				c = LookAhead(0);
				if (c == L'=')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"-=";
					return tok;
				}
				else if (c == L'-')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"--";
					return tok;
				}
				else
				{
					tok.Token = T_OPERATOR;
					tok.Value = L"-";
					return tok;
				}

			}
			if (c == L'<')
			{
				c = LookAhead(0);
				if (c == L'\0')
					continue;

				if (c == L'=')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"<=";
					return tok;
				}
				else if (c == L'<')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"<<";
					return tok;
				}
				else
				{
					tok.Token = T_OPERATOR;
					tok.Value = L"<";
					return tok;
				}
			}

			if (c == L'>')
			{
				c = LookAhead(0);
				
				if (c == L'\0')
					continue;

				if (c == L'=')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L">=";
					return tok;
				}
				else if (c == L'>')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L">>";
					return tok;
				}
				else
				{
					tok.Token = T_OPERATOR;
					tok.Value = L">";
					return tok;
				}

			}

			if (c == L'!')
			{
				c = LookAhead(0);
				if (c == L'0')
					continue;
				
				if (c == L'=')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"!=";
					return tok;

				}
				else
				{
					tok.Token = T_OPERATOR;
					tok.Value = L"!";
					return tok;
				}
			}
			if(c == L'%')
			{
				c = LookAhead(0);
				if (c == L'\0')
					continue;

				if (c == L'=')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"%=";
					return tok;
				}
				else
				{
					tok.Token = T_OPERATOR;
					tok.Value = L"%";
					return tok;
				}
			}
			if (c == L'.')
			{
				tok.Token = T_OPERATOR;
				tok.Value = L".";
				return tok;
			}

			if (c == L',')
			{
				tok.Token = T_OPERATOR;
				tok.Value = L",";
				return tok;
			}

			if (c == L'(')
			{
				tok.Token = T_OPERATOR;
				tok.Value = L"(";
				return tok;
			}

			if (c == L')')
			{
				tok.Token = T_OPERATOR;
				tok.Value = L")";
				return tok;
			}

			if (c == L'[')
			{
				tok.Token = T_OPERATOR;
				tok.Value = L"[";
				return tok;
			}
			if (c == L']')
			{
				tok.Token = T_OPERATOR;
				tok.Value = L"]";
				return tok;
			}

			if (c == L'{')
			{
				tok.Token = T_OPERATOR;
				tok.Value =L"{";
				return tok;
			}
			if (c == L'}')
			{
				tok.Token = T_OPERATOR;
				tok.Value = L"}";
				return tok;
			}
			if (c == L'&')
			{
				c = LookAhead(0);
				if (c == L'\0')
					continue;
				if (c == L'&')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"&&";
					return tok;
				}
				else
				{
					tok.Token = T_OPERATOR;
					tok.Value = L"&";
					return tok;
				}
			}


			if (c == L'|')
			{
				c = LookAhead(0);

				if (c == L'\0')
					continue;	

				if (c == L'|')
				{
					nextChar();
					tok.Token = T_OPERATOR;
					tok.Value = L"||";
					return tok;
				}
				else
				{
					tok.Token = T_OPERATOR;
					tok.Value = L"|";
					return tok;
				}
			}

			if (c == L'~')
			{
				tok.Token = T_OPERATOR;
				tok.Value = L"~";
				return tok;
			}

			if (c == L'?')
			{
				tok.Token = T_OPERATOR;
				tok.Value = L"?";
				return tok;
			}

			if (c == L':')
			{
				tok.Token = T_OPERATOR;
				tok.Value = L":";
				return tok;
			}
		}
	}
	TokenSet set;
	set.Token = T_EOF;
	return set;
}



wchar_t Lexer::nextChar()
{

	if (TESTER.size() == Curser)
		return L'\0';

	wchar_t ch = TESTER.at(Curser++);

	 while (ch == L'\n')
	 {
		 LineNo++;
		ch = TESTER.at(Curser++);
		if (TESTER.size() <= Curser)
			return L'\0';
	 }
	return ch;
}


wchar_t Lexer::LookAhead(int point)
{
	if (Curser + point > TESTER.size())
		return L'\0';
	if (0 > Curser + point)
		return L'\0';

	return TESTER[Curser + point];
}

bool Lexer::isDigit(wchar_t c)
{
	return char_Regex(c, digit);
}
bool Lexer::isLetter(wchar_t c)
{
	return char_Regex(c, letter);
}

bool Lexer::char_Regex(wchar_t cx, wregex regex)
{
	wsmatch wideMatch;
	wstring target({ cx });
	if (regex_match(target.cbegin(), target.cend(), wideMatch, regex))
	{
		return true;
	}
	else
		return false;
}