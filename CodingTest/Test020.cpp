#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
        // 비어있는 스택 생성
        stack<char> st;

        // s의 모든 요소에 대해 char 변수인 c에 할당을 반복
        for (char c : s)
        {
            // c가 열린 괄호일 때 (, {, [
            if (c == '(' || c == '{' || c == '[')
            {
                // 스택에 해당 원소를 추가
                st.push(c);
            }
            // c가 닫힌 괄호일 때 ), }, ]
            else
            {
                // 스택이 비어있거나 가장 최상위 데이터를 비교했을 때 다른 종류의 괄호일 경우 false를 반환
                if (st.empty() ||
                    (c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '['))
                {
                    return false;
                }

                // 스택의 최상위 데이터 삭제
                st.pop();
            }
        }

        // 전체 입력 문자열을 순회한 후 스택이 비어있다면 true
        // 비어있지 않다면 false
        return st.empty();
	}
};

int main()
{
	Solution sol;

	string str = { '(','{','[',']', '}', ')' };

	sol.isValid(str);

	return 0;
}