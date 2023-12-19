#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        int n = nums.size();
        
        if (n <= 1)
        {
            return nums;
        }

        int left = 0;
        int right = 0;
        int Frequent = 0;

        vector<int> vRes;
        map<int, int> intMap;

        while (right < n)
        {
            int curInt = nums[right];
        
            if (nums[left] == nums[right])
            {
                ++Frequent;

                ++right;

                if (nums[left] != nums[right])
                {
                    intMap.insert(nums[left],Frequent );

                    Frequent = 0;

                    left = right;
                }
            }
        }


        return vRes;
    }
};


int main()
{
    Solution sol;

    vector<int> nums = { 1,1,1,2,2,3 };

    sol.topKFrequent(nums, 2);

    return 0;
}