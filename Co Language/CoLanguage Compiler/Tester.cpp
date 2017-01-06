#include <iostream>

#include <clocale>
#include <regex>
using namespace std;







int main()
{
	
		

	wchar_t i = 1;

	
	std::setlocale(LC_ALL, "");
	while (i > 0)
	{
		wcin >> i;

		wsmatch wideMatch;
		wstring target = wstring({i});
		 if (regex_match(target.cbegin(), target.cend(), wideMatch, letter))
		{
			cout << "Match" << endl;
		}
		 else
			cout << "Not Match" << endl;

	}

}