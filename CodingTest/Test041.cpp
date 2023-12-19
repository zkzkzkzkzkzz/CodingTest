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

        vector<int> Price(n, numeric_limits<int>::max());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // price, src
        pq.push({0, src});
        
        int Stopover = 0;

        while (!pq.empty() && Stopover <= k)
        {
            int CurStop = pq.top().second;
            int CurPrice = pq.top().first;

            pq.pop();

            for (const auto& neighbor : graph[CurStop])
            {
                int NextStop = neighbor.first;
                int edgeWeight = neighbor.second;

                int newPrice = CurPrice + edgeWeight;
                if (newPrice < Price[NextStop])
                {
                    Price[NextStop] = newPrice;
                    pq.push({ newPrice, NextStop });
                }
            }

            ++Stopover;
        }

        return Price[dst] == numeric_limits<int>::max() ? -1 : Price[dst];
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