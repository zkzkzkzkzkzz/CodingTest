#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int Left = 0;
        int Right = nums.size() - 1;

        while (Left <= Right)
        {
            int Mid = Left + (Right - Left) / 2;

            if (nums[Mid] == target)
            {
                return Mid;
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

        return -1;
    }
};

int main()
{
    Solution sol;

    vector<int> vec = { -1,0,3,5,9,12 };

    sol.search(vec, 9);

    return 0;
}