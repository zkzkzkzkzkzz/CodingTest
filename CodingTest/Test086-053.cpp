#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        return DevideAndConquer(nums, 0, nums.size() - 1);
    }

private:
    int DevideAndConquer(vector<int>& _nums, int left, int right)
    {
        if (left > right)
        {
            return -100000;
        }

        int mid = left + (right - left) / 2;
        int sumleft = 0;
        int sumright = 0;

        // mid 인덱스 기준 각 왼쪽, 오른쪽 배열에서 나올 수 있는 최댓값
        int maxLeft = DevideAndConquer(_nums, left, mid - 1);
        int maxRight = DevideAndConquer(_nums, mid + 1, right);

        // mid 인덱스를 시작으로 점점 좌우로 확장해나갔을 때 나올 수 있는 최댓값
        // mid가 4일 때, maxRight는 4가 나오나 이 4는 mid인덱스를 고려하지 않은 값이다
        // mid 인덱스를 고려할 경우 maxRight의 4는 8번인덱스이기 때문에 5,6,7번 인덱스도 계산을 해줘야 한다
        // -> 근데 이러면 최댓값이 달라짐 / 위 maxRight는 mid가 4일 때 고려해서 나온 값이 아니니 때문에
        for (int i = left, temp = 0; i < mid; ++i)
        {           
            temp += _nums[mid + left - i - 1];

            sumleft = max(temp, sumleft);
        }

        for (int i = mid + 1, temp = 0; i <= right; ++i)
        {
            temp += _nums[i];

            sumright = max(temp, sumright);
        }

        return max(max(maxLeft, maxRight), sumleft + sumright + _nums[mid]);
    }

    // kadane's algorithm
public:
    int maxSubArray2(vector<int>& nums)
    {
        int MaxSum = -100000;   // 지금까지 발견된 배열의 최대 합
        int CurSum = 0;         // 현재 순회 중인 서브 배열의 합계

        for (int i = 0; i < nums.size(); ++i)
        {
            CurSum += nums[i];

            if (CurSum > MaxSum)
            {
                MaxSum = CurSum;
            }

            if (CurSum < 0)
            {
                CurSum = 0;
            }
        }

        return MaxSum;
    }
};


int main()
{
    Solution sol;

    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };

    sol.maxSubArray(nums);

    return 0;
}