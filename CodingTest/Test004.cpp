// ������ �ܾ�� �����ؾ� �ϰ� ��ҹ��ڸ� �������� ����
// tolower�Լ��� �̿��ؼ� ��� �ҹ��ڷ� ����
// �� �ܾ ��� ���Դ��� �����ؾ���

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
//		// ��� i�� ���Ͽ� paragraph�� ����ִ� ���ڿ��� �ҹ��ڷ� �ٲ㼭 mystr�� ����
//		for (auto i : paragraph )
//		{
//			mystr += tolower(i);
//		}
//
//		// �����̽��� �ִ� ������ �߶� ���� ù ĭ�� �ְ�
//		// �� ���� �����̽��� �ִ� ������ �߶� ���� ĭ�� �ְ� -> �ݺ�
//		// �� �ܾ���� ����ִ� ���Ͱ� ����µ� �̸� banned�� ���ؼ� �Ȱ��ٸ� �� �ܾ ����
//		// �׷��� �Ȱ��� �ܾ ������ ��� �̸� �˷��� Count�� �ʿ���
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