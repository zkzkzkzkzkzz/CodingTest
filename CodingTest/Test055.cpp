#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        // 내림차순
        priority_queue<int, vector<int>, less<int>> pq;

        for (auto i : nums)
        {
            pq.push(i);
        }

        for (int i = 0; i < k - 1; ++i)
        {
            pq.pop();
        }

        return pq.top();
    }
};


int main()
{
    Solution sol;

    vector<int> vec = { 3,2,1,5,6,4 };

    int a = sol.findKthLargest(vec, 2);

    return 0;
}