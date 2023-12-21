#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(n);
        
        vector<int> ans;
        vector<int> indegree(n, 0);

        for (auto& e : edges) 
        {   
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) 
        {
            if (indegree[i] == 1)
            {
                q.push(i);
                indegree[i]--;
            }
        }

        while (!q.empty())
        {
            int s = q.size();
            ans.clear();

            for (int i = 0; i < s; i++) 
            {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);

                for (auto child : graph[curr])
                { 
                    indegree[child]--;

                    if (indegree[child] == 1)
                    {
                        q.push(child);
                    }
                }
            }
        }
        if (n == 1)
        {
            ans.push_back(0); 
        }
        
        return ans;
    }
};


int main()
{
    Solution Sol;

    vector<int> vec1 = { 3, 0 };
    vector<int> vec2 = { 3, 1 };
    vector<int> vec3 = { 3, 2 };
    vector<int> vec4 = { 3, 4 };
    vector<int> vec5 = { 4, 5 };

    vector<vector<int>> Vec;
    Vec.push_back(vec1);
    Vec.push_back(vec2);
    Vec.push_back(vec3);
    Vec.push_back(vec4);
    Vec.push_back(vec5);

    Sol.findMinHeightTrees(6, Vec);

    return 0;
}