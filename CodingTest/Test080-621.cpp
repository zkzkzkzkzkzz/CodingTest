#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        priority_queue<pair<int, char>> pq;
        map<char, int> m;
        int Day = 0;

        if (n == 0)
        {
            Day = tasks.size();

            return Day;
        }

        for (char c : tasks)
        {
            ++m[c];
        }

        map<char, int>::iterator iter = m.begin();

        for (; iter != m.end(); ++iter)
        {
            char task = (*iter).first;
            int count = (*iter).second;

            pq.push({ count, task });
        }

        // 'A'  -   -  'A'   -   -  'A'         idle 4 == (pqcount - 1) * n
        // 'A' 'B'  -  'A'  'B'  -  'A' 'B'     idle 2
        // 'A' 'B' 'C' 'A'  'B'  -  'A' 'B'     idle 1
        
        int pqcount = pq.top().first;           // 현재 pq에 들어있는 task 중 가장 많은 task의 빈도수
        int Firstpqcount = pqcount - 1;         // 초기 pq의 가장 많은 task의 수 - 1
        int idlecount = (pqcount - 1) * n;      // idle 개수((가장 많은 task의 수 - 1) * n 개 만큼 처음에 생성된다)
        Day += pqcount;
        pq.pop();

        while (!pq.empty())
        {
            pqcount = pq.top().first;

            Day += pqcount;

            // 모든 task는 처음에 생성된 idle에 들어간다(task의 수가 같아서 뒤에 붙는 것은 idle에 영향이 없으므로 제외)
            // 때문에 idlecount의 감소량은 (가장 많은 task의 수 - 1) 또는 pqcount 중 작은 값을 따라간다
            idlecount -= min(pqcount, Firstpqcount);

            pq.pop();
        }

        // idle이 음수일 경우 idle없이 스케줄을 짤 수 있다는 것을 의미
        if (idlecount <= 0)
        {
            idlecount = 0;
        }

        // 모든 task를 순회하고 남은 idlecount를 더하면 스케줄의 길이가 나온다
        Day += idlecount;

        return Day;
    }
};

int main()
{
    Solution sol;

    vector<char> tasks = { 'A', 'B', 'A', 'B', 'B', 'A', 'C'};

    sol.leastInterval(tasks, 2);

    return 0;
}