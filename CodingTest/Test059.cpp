#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if (intervals.size() == 1)
        {
            return intervals;
        }

        vector<vector<int>> Res;
        vector<pair<int, int>> pVec;

        for (size_t i = 0; i < intervals.size(); ++i)
        {
            // intervals의 원소들을 pair로 pVec에 추가
            pVec.push_back({ intervals[i][0], intervals[i][1] });
        }

        // pVec.first 기준으로 정렬
        // intervals 원소의 왼쪽 숫자 기준으로 정렬된다
        sort(pVec.begin(), pVec.end());

        int Left = pVec[0].first;
        int Right = pVec[0].second;

        for (size_t i = 0; i < pVec.size() - 1; ++i)
        {            
            // 벡터의 오른쪽 원소가 다음 인덱스 왼쪽 원소보다 크거나 같다면 겹친다는 의미
            if (Right >= pVec[i + 1].first)
            {
                // 현재 인덱스의 오른쪽 원소와 다음 인덱스 오른쪽 원소 중 큰 값으로 갱신
                // 겹치는 두 영역을 합치는데 어떤 값이 제일 큰지 확인하는 과정
                Right = max(Right, pVec[i + 1].second);
            }
            else
            {
                vector<int> Temp(2);
                
                Temp[0] = Left;
                Temp[1] = Right;

                Res.push_back(Temp);

                Left = pVec[i + 1].first;
                Right = pVec[i + 1].second;
            }
        }

        // pVec의 마지막 원소는 비교할 다음 인덱스가 없기 때문에 따로 한 번 넣어준다
        Res.push_back({ Left, Right });

        return Res;
    }
};


int main()
{
    Solution sol;

    vector<int> vec1 = { 2, 3 };
    vector<int> vec2 = { 8, 10 };
    vector<int> vec3 = { 15, 18 };
    vector<int> vec4 = { 1, 4 };

    vector<vector<int>> VEC = {};

    VEC.push_back(vec1);
    VEC.push_back(vec2);
    VEC.push_back(vec3);
    VEC.push_back(vec4);

    sol.merge(VEC);

    return 0;
}