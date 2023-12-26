#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>> Res;

        vector < pair<int, vector<int>>> temp;

        for (auto i : points)
        {
            int a = i[0];
            int b = i[1];

            int dist = a * a + b * b;

            temp.push_back({ dist, {a,b} });
        }

        sort(temp.begin(), temp.end());

        for (size_t i = 0; i < k; ++i)
        {
            Res.push_back(temp[i].second);
        }

        return Res;
    }
};


int main()
{
    Solution sol;

    vector<int> vec1 = { -5, 4 };
    vector<int> vec2 = { -6, -5 };
    vector<int> vec3 = { 4, 6 };

    vector<vector<int>> Vec;

    Vec.push_back(vec1);
    Vec.push_back(vec2);
    Vec.push_back(vec3);

    sol.kClosest(Vec, 2);

    return 0;
}