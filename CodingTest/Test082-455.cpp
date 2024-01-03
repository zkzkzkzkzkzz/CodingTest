#include <vector>
#include <queue>
#include <algorithm>


using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int Count = 0;

        priority_queue<int, vector<int>, greater<int>> pqGreed;
        priority_queue<int, vector<int>, greater<int>> pqCookies;
      
        for (int i : g)
        {
            pqGreed.push(i);
        }

        for (int i : s)
        {
            pqCookies.push(i);
        }

        while ((!pqGreed.empty()) && (!pqCookies.empty()))
        {
            if (pqGreed.top() <= pqCookies.top())
            {
                pqGreed.pop();
                pqCookies.pop();
                ++Count;
            }
            else
            {
                // 가장 욕심이 덜한 아이에게도 주지못하는 크기이므로
                // 우선순위 큐에서 삭제하여 고려하지 않음
                pqCookies.pop();
            }
        }

        return Count;
    }

    int findContentChildren2(vector<int>& g, vector<int>& s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;
        int count = 0;

        while (child < g.size() && cookie < s.size())
        {
            if (s[cookie] >= g[child])
            {
                ++count;
                ++child;
            }

            ++cookie;
        }

        return count;
    }
};


int main()
{
    Solution sol;

    vector<int> g = { 2,3,4 };
    vector<int> s = { 1,2 };

    sol.findContentChildren(g, s);

    return 0;
}