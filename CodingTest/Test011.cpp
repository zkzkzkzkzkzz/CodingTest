#include <vector>

using namespace std;

// 접두사, 접미사 곱셈
// 접두사 및 접미사 곱셈은 각 배열 요소에 대해 현재 위치를 기준으로
// 왼쪽에 있는 모든 요소의 곱(접두사), 오른쪽에 있는 모든 요소의 곱(접미사)을 계산하는 것을 의미함

// 만약 주어진 배열이 [1, 2, 3, 4]일 때
// 접두사 곱셈은 [      1,      1*1,    1*1*2,  1*1*2*3]의 값을 가지고
// 접미사 곱셈은 [4*3*2*1,    4*3*1,      4*1,        1]의 값을 가진다

// 두 배열 모두 자기 자신을 제외한 요소들의 곱이기 때문에 두 배열을 곱하면
// 자기 자신을 제외한 배열의 곱셈임을 알 수 있다

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> vRes;
        vector<int> vPrefix;
        vector<int> vSuffix;

        vRes.resize(nums.size());
        vPrefix.resize(nums.size());
        vSuffix.resize(nums.size());

        // 가장 처음 인덱스와 가장 끝 인덱스는 각각 접두사, 접미사 곱셈에서 곱할 수 있는 값이 없다
        // 그러므로 1로 초기화한다
        int Left = 1;
        int Right = 1;

        // 접두사 곱셈
        for (int i = 0; i < nums.size(); ++i)
        {
            vPrefix[i] = Left;
            Left *= nums[i];
        }

        // 접미사 곱셈
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            vSuffix[i] = Right;
            Right *= nums[i];
        }

        // 두 벡터를 곱한 결과를 vRes에 대입
        for (int i = 0; i < nums.size(); ++i)
        {
            vRes[i] = vPrefix[i] * vSuffix[i];
        }

        return vRes;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = { 1,2,3,4 };

    sol.productExceptSelf(nums);

    return 0;
}