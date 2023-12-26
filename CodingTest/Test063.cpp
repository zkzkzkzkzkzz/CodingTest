#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int Size = nums.size();

        if (Size == 1)
        {
            return;
        }

        vector<int> dummy;
        vector<int> compare;

        compare.push_back(nums[0]);

        int Idx = 1;

        while (Idx < Size)
        {
            if (compare.back() <= nums[Idx])
            {
                compare.push_back(nums[Idx]);
                ++Idx;
            }
            else
            {
                dummy.push_back(compare.back());
                compare.pop_back();
                
                if (!compare.empty() && compare.back() > nums[Idx])
                {
                    continue;
                }

                compare.push_back(nums[Idx]);
                
                while (!dummy.empty())
                {
                    compare.push_back(dummy.back());
                    dummy.pop_back();
                }

                ++Idx;
            }
        }

        nums = compare;
    }

    // 해답 풀이
    void sortColors2(vector<int>& nums)
    {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                ++low;
                ++mid;
            }
            else if (nums[mid] == 1)
            {
                ++mid;
            }
            else
            {
                swap(nums[mid], nums[high]);
                --high;
            }
        }
    }
};



int main()
{
    Solution sol;

    vector<int> vec = { 2, 0, 2, 1, 1, 0 };

    sol.sortColors(vec);

    return 0;
}