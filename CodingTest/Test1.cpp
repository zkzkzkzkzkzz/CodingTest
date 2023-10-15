#include <iostream>
#include <cctype>

using namespace std;

class Solution
{
public:
	bool isPaildrome(string s)
	{
		string str1;

		for (auto i : s)
		{
			if (isalpha(i) || isdigit(i))
			{
				i = tolower(i);
				str1 += i;
			}
		}

		string::iterator iter = str1.end();
		string str2 = str1;
		reverse(str1.begin(), str1.end());

		if (str1 == str2)
		{
			return true;
		}

		return false;
	}
};


int main()
{
	
	Solution S;

	bool bS = S.isPaildrome("A man, a plan, a canal: Panama");
	bS = S.isPaildrome("race a car");
	bS = S.isPaildrome("");

	return 0;
}