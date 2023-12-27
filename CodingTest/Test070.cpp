#include <vector>
#include <algorithm>

using namespace std;

// 비트 연산자
// & : 두 비트가 모두 1이면 1을 반환 (비트 AND 연산)
// | : 두 비트 중 하나라도 1이면 1을 반환 (비트 OR 연산)
// ^ : 두 비트가 다르면 1을 반환 (비트 XOR 연산)
// ~ : 비트가 1이면 0으로, 0이면 1로 반전 (비트 NOT 연산)
// << : 지정한 수만큼 비트들을 전부 왼쪽으로 이동 (left shift 연산)
// >> : 부호를 유지하면서 지정한 수만큼 비트를 전부 오른쪽으로 이동시킴 (right shift 연산)

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