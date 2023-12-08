#include <vector>

using namespace std;

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