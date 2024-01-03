#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 분할정복
// 다중 분기 재귀를 기반으로 하는 알고리즘
// 1. 직접 해결할 수 있을 정도로 간단한 문제가 될 때까지 문제를 재귀적으로 쪼개나간다(분할)
// 2. 가장 작은 단위의 하위 문제를 해결하여 정복한다(정복)
// 3. 하위 문제의 결과들을 조합하여 원래 문제의 결과로 만들어낸다(조합)
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) 
    {
        vector<int> Res;
        
        int size = expression.size();

        for (int i = 0; i < size; ++i)
        {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*')
            {
                // 문자열 expression의 0번 인덱스부터 i만큼 추출
                vector<int> vLeft = diffWaysToCompute(expression.substr(0, i));
                // 문자열 expression의 i + 1번 인덱스부터 끝까지 추출
                vector<int> vRight = diffWaysToCompute(expression.substr(i + 1));

                for (int i1 : vLeft)
                {
                    for (int i2 : vRight)
                    {
                        if (c == '+')
                        {
                            Res.push_back(i1 + i2);
                        }
                        else if (c == '-')
                        {
                            Res.push_back(i1 - i2);
                        }
                        else
                        {
                            Res.push_back(i1 * i2);
                        }
                    }
                }
            }
        }

        // expression에 연산 기호가 없었다면 (숫자로만 이루어져 있었다면)
        if (Res.empty())
        {
            Res.push_back(atoi(expression.c_str()));
        }

        return Res;
    }
};


int main()
{
    Solution sol;

    string expression = "2-1-1";

    sol.diffWaysToCompute(expression);

    return 0;
}