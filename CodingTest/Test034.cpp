#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;

        permuteRecursive(nums, 0, result);

        return result;
    }

private:
    void permuteRecursive(vector<int>& nums, int index, vector<vector<int>>& result)
    {
        // 인덱스가 마지막 원소를 가리키고 있을 때
        if (index == nums.size() - 1)
        {
            result.push_back(nums);

            return;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            // 현재 인덱스와 i번째 인덱스의 원소를 교환
            swap(nums[index], nums[i]);

            // 현재 인덱스를 다음으로 올려서 재귀함수를 돌린다
            permuteRecursive(nums, index + 1, result);
            
            // 재귀를 돌기 전에 교환했던 원소를 원래 상태로 되돌린다
            swap(nums[index], nums[i]);
        }
    }
};

int main()
{
    Solution sol;

    vector<int> vInt = { 1, 2, 3 };

    sol.permute(vInt);

    return 0;
}