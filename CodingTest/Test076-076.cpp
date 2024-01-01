#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) 
    {
        // unordered_map은 특정 순서를 유지하지 않고 키-값 쌍을 저장하며, 해시 함수를 사용하여 더 빠른 검색 시간을 제공한다
        // 반면, map은 키를 정렬된 순서로 유지하고 있어 범위 기반의 검색에 유리하다
        
        // 해당 문제는 각 문자의 등장 횟수를 관리하는데
        // 이때 각 문자를 키로 하고 해당 문자의 등장 횟수를 값으로 하는 자료구조가 필요하다
        // unordered_map을 사용하면 해시 함수를 통해 상수 시간에 각 키에 대한 값에 접근할 수 있기때문에
        // 문자의 등장 횟수를 효율적으로 관리할 수 있다
        
        // 각 문자의 등장 횟수를 저장하는 해시맵
        // t 문자열을 순회하면서 각 문자의 등장 횟수를 저장한다
        unordered_map<char, int> charCount;

        for (char c: t)
        {
            ++charCount[c];
        }

        // 윈도우의 왼쪽, 오른쪽 포인터
        int left = 0;
        int right = 0;

        // 필요한 문자의 개수
        int requiredChars = charCount.size();

        // 현재 윈도우 내에 포함된 t의 문자의 개수
        int curChars = 0;

        // 최소 윈도우의 길이와 시작 인덱스
        int minLen = 1000000;
        int minStart = 0;

        while (right < s.size())
        {
            // 현재 처리 중인 문자(s[rigiht])가 t에 있다면
            if (charCount.find(s[right]) != charCount.end())
            {
                // 해당 문자의 등장 횟수를 하나 줄인다
                --charCount[s[right]];

                // 만약 해당 문자의 등장 횟수가 0이 된다면
                // curChars의 값을 하나 증가시킨다 -> 현재 윈도우에 필요한 문자가 모두 포함되었는지 확인
                if (charCount[s[right]] == 0)
                {
                    ++curChars;
                }
            }

            // 필요한 문자가 모두 포함된 경우
            while (curChars == requiredChars)
            {
                // 현재 윈도우에서 왼쪽 포인터가 가리키는 문자가 charCount에 있는 문자일 경우
                // 해당 문자의 등장 횟수를 증가시키고, 만약 그 값이 0보다 크다면 curChars를 감소시킨다
                if (charCount.find(s[left]) != charCount.end())
                {
                    ++charCount[s[left]];

                    if (charCount[s[left]] > 0)
                    {
                        --curChars;
                    }
                }

                // 현재 슬라이딩 윈도우의 크기가 minLen보다 작다면 윈도우 크기 갱신
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    minStart = left;
                }

                ++left;
            }

            ++right;
        }

        // t에 해당하는 최소 윈도우가 없는 경우
        if (minLen == 1000000)
        {
            return "";
        }

        return s.substr(minStart, minLen);
    }
};


int main()
{
    Solution sol;

    string s1 = "ADOABECCACBBODEBAANC";
    string s2 = "AAB";

    sol.minWindow(s1, s2);

    return 0;
}