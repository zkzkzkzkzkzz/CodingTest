#include <vector>
#include <algorithm>

using namespace std;

// XOR 연산
// 두 비트가 같으면 0, 다르면 1을 반환
// 만약 00000111 (7) 과 00001010 (10) 을 XOR 연산하면
// 00000111
// 00001010
// --------
// 00001101 이 반환된다

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int Res = 0;

        // XOR 연산에서 같은 int 값을 연산하면 0이 되므로
        // nums의 모든 원소에 대해 XOR 연산을 진행하면 하나인 원소만 남는다
        for (size_t i = 0; i < nums.size(); ++i)
        {
            Res ^= nums[i];
        }

        return Res;
    }
};



int main()
{
    Solution sol;

    vector<int> vec = { 4,1,2,1,2 };

    sol.singleNumber(vec);

    return 0;

}