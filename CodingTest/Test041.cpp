#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> graph(n);

        for (const auto& flight : flights)
        {
            int src = flight[0];
            int dst = flight[1];
            int price = flight[2];

            graph[src].emplace_back(dst, price);
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // price, src, stopover
        pq.push({0, src, 0});

        while (!pq.empty())
        {
            vector<int> vCur = pq.top();

            pq.pop();

            int CurPrice = vCur[0];
            int CurStop = vCur[1];
            int CurStopover = vCur[2];

            // 현재 정류장이 목적지라면 현재 저장된 가격을 반환
            if (CurStop == dst)
            {
                return CurPrice;
            }

            // 경유한 정류장이 k보다 크다면 무시
            if (CurStopover > k)
            {
                continue;
            }

            for (const auto& neighbor : graph[CurStop])
            {
                int NextStop = neighbor.first;
                int edgeWeight = neighbor.second;

                pq.push({CurPrice + edgeWeight, NextStop, CurStopover + 1});
            }
        }

        return -1;
    }
};


int main()
{
    Solution sol;

    vector<int> vec1 = { 0, 1, 100 };
    vector<int> vec2 = { 1, 2, 100 };
    vector<int> vec3 = { 0, 2, 500 };

    vector<vector<int>> Vec = {};
    Vec.push_back(vec1);
    Vec.push_back(vec2);
    Vec.push_back(vec3);

    sol.findCheapestPrice(3, Vec, 0, 2, 1);

    return 0;
}