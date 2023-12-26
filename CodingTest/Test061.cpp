#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;



bool compare(string a, string b)
{
    return a + b > b + a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        string Res;
        vector<string> sVec;

        if (nums.size() == 1)
        {
            sVec.push_back(to_string(nums[0]));

            Res = sVec[0];

            return Res;
        }

        for (size_t i = 0; i < nums.size(); ++i)
        {
            sVec.push_back(to_string(nums[i]));
        }

        sort(sVec.begin(), sVec.end(), compare);


        for (size_t i = 0; i < sVec.size(); ++i)
        {
            Res += sVec[i];
        }

        if (Res[0] == '0')
        {
            return "0";
        }

        return Res;
    }

};


int main()
{
    Solution Sol;

    //vector<int> vec = { 1 };

    vector<int> vec = { 3, 30, 34, 5, 9 };

    Sol.largestNumber(vec);

    return 0;
}