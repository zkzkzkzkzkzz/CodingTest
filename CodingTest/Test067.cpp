#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> Res;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (size_t i = 0; i < nums1.size(); ++i)
        {
            bool Valid = search(nums2, nums1[i]);

            vector<int>::iterator iter = find(Res.begin(), Res.end(), nums1[i]);

            if (Valid && iter == Res.end())
            {
                Res.push_back(nums1[i]);
            }
        }

        return Res;
    }

private:
    bool search(vector<int>& nums, int target) {

        int Left = 0;
        int Right = nums.size() - 1;

        while (Left <= Right)
        {
            int Mid = Left + (Right - Left) / 2;

            if (nums[Mid] == target)
            {
                return true;
            }
            else if (nums[Mid] < target)
            {
                Left = Mid + 1;
            }
            else
            {
                Right = Mid - 1;
            }
        }

        return false;
    }
};


int main()
{
    Solution sol;

    vector<int> vec1 = { 4, 9, 5 };
    vector<int> vec2 = { 9,4,9,8,4 };

    sol.intersection(vec1, vec2);

    return 0;
}