#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

// 일정 범위마다 sort해서 최댓값 벡터에 넣기 -> 시간 초과
// 투포인터로 슬라이딩 윈도우 움직이면서 매번 최댓값 찾기 -> 똑같이 시간초과

// 슬라이딩 윈도우는 첫번째 원소가 빠지고 그 다음 원소가 뒤에 붙는다 -> 자료구조 '큐'를 이용하면 될 거 같음
// 근데 큐는 정렬을 자동으로 해주지 않음. 거기서 최댓값을 또 찾아야 함
// 만약 큐에 넣으면서 최댓값을 같이 갱신해준다해도 q.pop()이 최댓값이었을 경우 다시 최댓값을 찾아야 함
// 자동으로 정렬해주는 건 우선순위 큐가 있음 -> 이거 이용하면 최댓값은 쉽게 구할 듯
// 근데 우선순위 큐는 다음 윈도우에서 첫번째 인덱스를 빼야할 때 어떻게 뺄 수 있을까????

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if (k == 1)
        {
            return nums;
        }

        vector<int> Res;

        int Max = 0;
        int MaxIdx = 0;

        // pair<Value, Index>
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < nums.size(); ++i)
        {
            int Value = nums[i];

            pq.push({Value, i});

            // 슬라이딩 윈도우에서 [i - k]번째 인덱스는 나가야 할 원소다
            // 하지만 pq에는 원소의 값과 인덱스 정보가 같이 들어있으므로
            // 매번 빼는 것이 아니라 최댓값 원소의 인덱스가 i-k보다 클때만
            // 즉, 이전에 저장했던 최댓값이 슬라이딩 윈도우 상 빠져나간 인덱스일때
            // pq에서 제거한다
            while (pq.top().second <= i - k)
            {
                pq.pop();
            }

            if (i >= k - 1)
            {
                Max = pq.top().first;

                Res.push_back(Max);
            }
        }

        return Res;
    }
};

int main()
{
    Solution sol;

    vector<int> vec = { 1,3,-1,-3,5,3,6,7 };

    sol.maxSlidingWindow(vec, 3);

    return 0;
}