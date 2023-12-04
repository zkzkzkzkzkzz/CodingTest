#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	//void reverseString(vector<char>& s)
	//{
	//	reverse(s.begin(), s.end());
	//}

	void reverseString(vector<char>& s)
	{
		size_t left = 0;
		size_t right = s.size() - 1;

		while (left < right)
		{
			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			++left;
			--right;
		}
	}
};

int main()
{
	Solution S;


	vector<char> myStr1 = { 'h', 'e', 'l', 'l', 'o'};
	vector<char> myStr2 = { 'H', 'a', 'n', 'n', 'a', 'h' };
	S.reverseString(myStr2);

	return 0;
}