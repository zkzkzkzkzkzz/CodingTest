#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// LRU 알고리즘(Least Recently Use Algorithm
// 가장 오랫동안 참조되지 않은 페이지를 교체하는 기법
// Doubly Linked List를 사용하고 head에 가까운 노드일수록 가장 최근에 참조된 페이지
// tail에 가까운 노드일수록 가장 오랫동안 참조되지 않은 페이지이다
// 캐시 사이즈를 넘어서면 tail에 가장 가까운 페이지가 먼저 삭제된다
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    if (cacheSize == 0)
    {
        answer = cities.size() * 5;

        return answer;
    }

    for (int i = 0; i < cities.size(); ++i)
    {
        // 도시이름 모두 소문자로 변환
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        vector<string>::iterator iter = find(cache.begin(), cache.end(), cities[i]);

        // cache miss인 경우 (해당 캐시에는 도시에 대한 정보가 없었다)
        if (iter == cache.end())
        {
            // 가장 오랫동안 참조되지 않은 페이지 삭제
            if (cache.size() == cacheSize)
            {
                cache.erase(cache.begin());
            }

            answer += 5;
        }
        else
        {
            ++answer;
            cache.erase(iter);
        }

        cache.push_back(cities[i]);
    }

    return answer;
}



int main()
{
    vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };

    solution(3, cities);

    return 0;
}