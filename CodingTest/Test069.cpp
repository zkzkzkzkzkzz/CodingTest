#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int row = 0;
        int col = matrix[row].size() - 1;

        while (row < matrix.size() && col >= 0)
        {
            int Value = matrix[row][col];

            if (Value == target)
            {
                return true;
            }

            if (Value < target)
            {
                ++row;
            }
            else
            {
                --col;
            }
        }

        return false;
    }
};


int main()
{
    Solution sol;

    vector<int> vec1 = { -5 };
    //vector<int> vec1 = { 1,  4,  7,  11, 15 };
    //vector<int> vec2 = { 2,  5,  8,  12, 19 };
    //vector<int> vec3 = { 3,  6,  9,  16, 22 };
    //vector<int> vec4 = { 10, 13, 14, 17, 24 };
    //vector<int> vec5 = { 18, 21, 23, 26, 30 };

    vector<vector<int>> Vec;

    Vec.push_back(vec1);
    //Vec.push_back(vec2);
    //Vec.push_back(vec3);
    //Vec.push_back(vec4);
    //Vec.push_back(vec5);

    sol.searchMatrix(Vec, -2);

    return 0;
}