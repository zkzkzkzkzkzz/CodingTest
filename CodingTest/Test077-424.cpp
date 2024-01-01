#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        unordered_map<char, int> charCount;

        int MaxLen = 0;
        int MaxCount = 0;
        int left = 0;
        int right = 0;
        
        while (right < s.size())
        {
            ++charCount[s[right]];

            // 현재 윈도우 중 가장 많이 등장한 문자의 개수
            MaxCount = max(MaxCount, charCount[s[right]]);

            // 현재 윈도우에서 가장 많이 등장한 문자를 뺐을 때
            // 즉, 바꿔야 할 문자가 k보다 많다면
            if (right - left + 1 - MaxCount > k)
            {
                // 위에서 빈도수를 구하기 때문에 정확한 계산을 위해 s[left]의 값을 감소시킨다
                --charCount[s[left]];
                ++left;
            }

            MaxLen = max(MaxLen, right - left + 1);
            ++right;
        }

        return MaxLen;
    }
};


int main()
{
    Solution sol;

    string s = "AAAAABBBCDEFFF";
    
    sol.characterReplacement(s, 2);

    return 0;
}