#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<string> reorderLogFiles(vector<string>& log)
	{
		
	}
};

bool compare(string& a, string& b)
{
	string str1 = string(a.begin() + a.find(' '), a.end());
	string str2 = string(b.begin() + b.find(' '), b.end());

	return (str1 == str2) ? a < b : str1 < str2;
}

int main()
{
	Solution S;

	vector<string> str = { "dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero" };

	string mystr1 = str[0];
	string mystr2 = str[1];

	bool b = compare(mystr1, mystr2);
	
	//S.reorderLogFiles(str);


	return 0;
}