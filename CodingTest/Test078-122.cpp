#include <vector>
#include <algorithm>

using namespace std;

// 그리디 알고리즘
// 눈앞의 이익만을 좇는 알고리즘
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int Profit = 0;

        if (prices.size() == 1)
        {
            return Profit;
        }

        int CurPrice = 0;
        int NextPrice = 0;

        for (int i = 0; i < prices.size() - 1; ++i)
        {
            CurPrice = prices[i];
            NextPrice = prices[i + 1];

            if (CurPrice < NextPrice)
            {
                Profit += (NextPrice - CurPrice);
            }
        }

        return Profit;
    }
};


int main()
{
    Solution sol;

    vector<int> vec = { 7,1,5,3,6,4 };

    sol.maxProfit(vec);

    return 0;
}