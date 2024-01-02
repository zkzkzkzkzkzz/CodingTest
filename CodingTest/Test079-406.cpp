#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }

    return a[0] > b[0];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        vector<vector<int>> Res;
        priority_queue<pair<int, int>> pq;

        for (auto i : people)
        {
            int height = i[0];
            int taller = i[1];

            // pq는 기본적으로 max heap으로 동작한다
            // max heap에서는 first기준으로 최댓값을 구하고, 만약 first가 같을경우
            // second가 더 큰 값을 최댓값으로 출력한다
            // 하지만 해당 문제는 키는 내림차순, 앞에 있는 사람 수에 대해서는 오름차순으로 정렬해야 한다
            // 따라서 taller에 -1을 곱해줌으로써 앞에 있는 사람수에 대해 오름차순으로 정렬할 수 있도록 한다
            pq.push({ height, -1 * taller});
        }
        
        while (!pq.empty())
        {
            int height = pq.top().first;
            int taller = pq.top().second * -1;

            Res.insert(Res.begin() + taller, { height, taller });

            pq.pop();
        }

        return Res;
    }

public:
    vector<vector<int>> reconstructQueue2(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> Res;

        for (auto vi : people)
        {
            Res.insert(Res.begin() + vi[1], vi);
        }

        return Res;
    }
};


int main()
{
    Solution sol;

    vector<int> vec1 = { 7, 0 };
    vector<int> vec2 = { 4, 4 };
    vector<int> vec3 = { 7, 1 };
    vector<int> vec4 = { 5, 0 };
    vector<int> vec5 = { 6, 1 };
    vector<int> vec6 = { 5, 2 };

    vector<vector<int>> vec = {};

    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vec.push_back(vec4);
    vec.push_back(vec5);
    vec.push_back(vec6);

    sol.reconstructQueue(vec);

    return 0;
}