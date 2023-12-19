#include <vector>
#include <queue>
#include <limits>

using namespace std;

// 다익스트라 알고리즘
// 그래프에서 출발점으로부터 모든 다른 정점까지의 최단 경로를 찾는 알고리즘
// 이 알고리즘은 음의 가중치를 가지지 않는 그래프에서 사용되며, 각 간선(노드를 연결하는 선)의 가중치는 양수 또는 0이어야 한다

// 1. 출발 노드 선택 - 출발 노드를 선택하고 해당 노드까지의 최단 거리를 0으로, 다른 노드들은 무한대로 초기화한다

// 2. 인접한 노드들의 최단 거리 갱신 - 출발 노드와 직접 연결된 노드들에 대한 최단 거리를 갱신
//                                이때, 출발 노드를 통해서 가는 거리와 현재까지의 최단 거리를 비교하여 더 짧은 거리를 해당 노드의 최단 거리로 갱신한다

// 3. 아직 방문하지 않은 노드 중 최단 거리 노드 선택 - 출발 노드와 직접 연결된 노드들의 최단 거리가 모두 업데이트되었다면
//                                              아직 방문하지 않은 노드 중에서 최단 거리를 가진 노드를 선택한다

// 4. 선택된 노드를 경유지로 사용하여 다른 노드들의 최단 거리 갱신 - 선택된 노드를 경유해서 다른 노드들까지의 거리를 갱신한다
//                                                          현재까지의 최단 거리와 경유해서 가는 거리를 비교하여 더 짧은 거리를 해당 노드의 최단 거리로 갱신한다

// 5. 모든 노드를 방문할 때까지 반복 - 위의 과정을 모든 노드를 방문할 때까지 반복한다

// 알고리즘이 종료되면 출발 노드로부터 각 노드까지의 최단 거리가 계산되고, 이를 통해 최단 경로를 찾을 수 있다
// 다익스트라 알고리즘은 그리디 알고리즘의 일종으로, 항상 현재까지의 최단 거리를 가진 노드를 선택하여 진행한다
// 그리디 알고리즘 - 각 단계에서 현재 상황에서 가장 좋아 보이는 선택을 하는 최적화 문제를 해결하기 위한 알고리즘

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        // 그래프를 인접 리스트로 표현
        // graph[i]는 노드 'i'와 연결된 간선들의 목록을 나타내는 벡터이고,
        // pair<int, int>는 간선의 도착 노드와 해당 간선의 가중치를 나타낸다
        // 예를 들어, graph[1]이 {(2, 5), (3, 10)}이라면,
        // 노드 1에서 노드 2로 가는 간선의 가중치는 5이고, 노드 1에서 노드 3으로 가는 간선의 가중치는 10이다
        // graph(n+1)을 한 이유 -> 노드 번호가 1번부터 n번까지인 경우를 고려
        // 인덱스는 0부터 시작하기 때문에 노드 번호 1번을 표시하기 위해 n+1로 설정함
        vector<vector<pair<int, int>>> graph(n + 1);

        // times의 원소를 수정하지 않는다
        for (const auto& time : times)
        {
            int u = time[0];    // 시작 노드
            int v = time[1];    // 도착 노드
            int w = time[2];    // 간선의 가중치

            // push_back과 달리 원소를 추가할 때 복사 생성자를 호출하지 않고 해당 원소를 직접 생성한다
            // graph[u].push_back(v, w)를 쓰면 컴파일 에러가 생긴다
            // graph[u]에는 pair<int, int> 객체를 넣어줘야 하는데
            // 그냥 push_back(v, w)를 쓸경우 컴파일러는 pair인 줄 모르고 그냥 int 값 두개가 들어온 걸로 판단하여 에러가 뜬다
            // graph[u].push_back(make_pair(v, w)); 라고 적어야 pair 객체를 push_back 하는 것으로 판단한다
            // emplace_back은 알아서 알맞은 생성자를 찾아서 호출하기 때문에 pair 객체를 생성했기에 컴파일 에러가 뜨지 않은 것
            // graph[u]에는 u와 연결된 노드와 해당 간선의 가중치가 입력된다
            graph[u].emplace_back(v, w);
        }

        // 최단 거리를 저장하는 배열
        // 크기는 n+1(노드가 n개니까)
        // 초기값은 numeric_limits<int>::max()로 설정
        // 초기에는 모든 노드까지의 거리를 무한대로 설정하여 나중에 최단 거리가 갱신될 때까지 유지함을 의미
        vector<int> dist(n + 1, numeric_limits<int>::max());

        // 우선순위 큐를 사용하여 다익스트라 알고리즘 구현
        // greater<pair<int, int>>는 우선순위 큐에서 작은 값부터 추출하도록 하는 비교 함수
        // 우선순위 큐에 저장되는 데이터 형식 / 우선순위 큐가 사용할 컨테이너 / 우선순위 큐가 각 요소를 어떻게 정렬할지
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // 다익스트라 알고리즘에서 시작 노드의 거리를 0으로 초기화
        pq.push({ 0, k });
        dist[k] = 0;

        while (!pq.empty())
        {
            int curNode = pq.top().second;
            int curDist = pq.top().first;
            pq.pop();

            // curDist가 dist[curNode]보다 크다면
            // 이미 더 짧은 경로가 존재한다는 뜻이므로
            // 해당 노드를 무시하고 다음 노드로 진행한다
            if (curDist > dist[curNode]) 
            {
                continue;
            }

            for (const auto& neighbor : graph[curNode]) 
            {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;

                int newDist = curDist + edgeWeight;
                if (newDist < dist[nextNode])
                {
                    // 현재까지의 최단 거리를 업데이트하면서 다음 노드로 계속 진행 -> 다익스트라 알고리즘
                    dist[nextNode] = newDist;
                    // curNode와 연결된 이웃 노드를 pq에 추가한다
                    pq.push({ newDist, nextNode });
                }
            }
        }

        // 최단 거리 중 가장 큰 값 반환
        // 1번 노드부터 마지막 노드까지의 저장된 거리 중 가장 큰 값
        // max_element(start, end) -> [start, end) 범위 중 가장 큰 값의 iterator를 반환
        // *max_element(start, end) -> [start, end) 범위 중 가장 큰 값의 value를 반환
        // min_element / *min_element는 가장 작은 값의 iterator / value를 반환
        int maxDist = *max_element(dist.begin() + 1, dist.end());

        // 삼항 연산자
        // maxDist가 최댓값과 같다면 저장된 최단거리가 아예 없다는 의미
        return (maxDist == numeric_limits<int>::max()) ? -1 : maxDist;
    }
};


int main()
{
    Solution sol;

    vector<int> vec1 = { 2, 1, 1 };
    vector<int> vec2 = { 2, 3, 1 };
    vector<int> vec3 = { 3, 4, 1 };

    vector<vector<int>> Vec = {};
    Vec.push_back(vec1);
    Vec.push_back(vec2);
    Vec.push_back(vec3);

    sol.networkDelayTime(Vec, 4, 2);

    return 0;
}