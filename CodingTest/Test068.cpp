#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (left <= right)
        {
            int Sum = numbers[left] + numbers[right];

            if (Sum == target)
            {
                return { left + 1, right + 1 };
            }
            else if (Sum > target)
            {
                --right;
            }
            else
            {
                ++left;
            }
        }

        return {};
    }
};



int main()
{
    Solution sol;

    vector<int> vec = { -1, 0 };

    sol.twoSum(vec, 9);

    return 0;

}