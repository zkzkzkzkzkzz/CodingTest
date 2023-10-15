// 금지된 단어는 제외해야 하고 대소문자를 구분하지 않음
// tolower함수를 이용해서 모두 소문자로 변경
// 각 단어가 몇번 나왔는지 저장해야함

#include <iostream>
#include <vector>
#include <cctype>
#include <unordered_map>

using namespace std;

//class Solution
//{
//public:
//	string mostCommonWord(string paragraph, vector<string>& banned)
//	{
//		string mystr = "";
//
//		// 모든 i에 대하여 paragraph에 들어있는 문자열을 소문자로 바꿔서 mystr에 대입
//		for (auto i : paragraph )
//		{
//			mystr += tolower(i);
//		}
//
//		// 스페이스가 있는 곳까지 잘라서 벡터 첫 칸에 넣고
//		// 그 다음 스페이스가 있는 곳까지 잘라서 다음 칸에 넣고 -> 반복
//		// 각 단어들이 들어있는 벡터가 생기는데 이를 banned와 비교해서 똑같다면 그 단어를 지움
//		// 그런데 똑같은 단어가 들어왔을 경우 이를 알려줄 Count가 필요함
//
//		vector<string> vmystr = {};
//		
//		string mystr2(mystr.begin(), mystr.begin() + mystr.find(" "));
//
//		vmystr = { mystr2 };
//
//
//		return nullptr;
//	}
//};

class Solution
{
public:
	string mostCommonWord(string paragraph, vector<string>& banned)
	{
		string Str = "";
		int Count = 0;
		unordered_map<string, int> mStr;

		while (Count < paragraph.length())
		{
			string mystr1 = "";

			while (Count < paragraph.length() && isalpha(paragraph[Count]));
		}
	}
};


int main()
{
	Solution s;

	string str = "Bob hit a ball, the hit BALL flew far after it was hit.";

	vector<string> vstr = { "ball" };

	s.mostCommonWord(str, vstr);

	return 0;
}