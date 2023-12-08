#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int Profit = 0;

        if (prices.size() == 1)
        {
            return Profit;
        }

        int Purchase = prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] - Purchase > 0)
            {
                int tempProfit = prices[i] - Purchase;

                if (Profit < tempProfit)
                {
                    Profit = tempProfit;
                }
            }
            else
            {
                Purchase = prices[i];
            }
        }

        return Profit;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = { 7,6,4,3,1 };

    sol.maxProfit(nums);

    return 0;
}