#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int size = nums.size();

        if (size == 1)
        {
            return nums[0];
        }

        vector<int> MaxMoney(size, 0);
        MaxMoney[0] = nums[0];                 // 첫번째 집까지의 최대 훔친 돈
        MaxMoney[1] = max(nums[0], nums[1]);   // 두번째 집까지의 최대 훔친 돈(첫번째집 or 두번째집 중 더 비싼 곳을 털었다)

        for (int i = 2; i < size; ++i)
        {
            // i번째 집을 털었다고 가정했을 때와 i-1번째 집을 털었다고 가정했을 때 나올 수 있는 최댓값 비교
            MaxMoney[i] = max(MaxMoney[i - 1], MaxMoney[i - 2] + nums[i]);
        }

        return max(MaxMoney[size - 1], MaxMoney[size - 2]);
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {3,2,1,99 };

    sol.rob(nums);

    return 0;
}