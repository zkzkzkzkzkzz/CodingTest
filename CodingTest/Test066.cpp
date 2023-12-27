#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int Left = 0;
        int Right = nums.size() - 1;

        while (Left <= Right)
        {
            int Mid = Left + (Right - Left) / 2;
            
            if (nums[Mid] == target)
            {
                return Mid;
            }
            
            // Mid 인덱스 기준 왼쪽은 오름차순이다
            if (nums[Left] <= nums[Mid])
            {
                // Left와 Mid 사이에 target이 존재한다
                if (nums[Left] <= target && nums[Mid] > target)
                {
                    Right = Mid - 1;
                }
                else
                {
                    Left = Mid + 1;
                }
            }
            // Mid 인덱스 기준 오른쪽은 오름차순이다
            else
            {
                // Mid와 Right 사이에 target이 존재한다
                if (nums[Mid] < target && nums[Right] >= target)
                {
                    Left = Mid + 1;
                }
                else
                {
                    Right = Mid - 1;
                }
            }
        }

        return -1;
    }
};


int main()
{
    Solution sol;

    vector<int> vec = { 4,5,6,7,0,1,2 };

    sol.search(vec, 7);

    return 0;
}