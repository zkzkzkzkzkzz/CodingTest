// queue는 선입선출 형식의 자료구조
// 우선순위 큐는 먼저 들어오는 데이터가 아니라, 우선순위가 높은 데이터가 먼저 나가는 형태의 자료구조이다
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 우선순위 큐는 일반적으로 '힙'을 이용하여 구현한다
// '힙(Heap)'은 완전이진트리 형태의 자료구조
// 여러 개의 값 중 최댓값 또는 최솟값을 찾아내는 연산이 빠르다

// enqueue() - queue에 새 요소를 삽입한다
// dequeue() - queue에서 최대 우선 순위 요소를 삭제하고 그 값을 반환한다
// peek() - queue에서 최대 우선순위 요소를 반환한다


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* Res = new ListNode;
        ListNode* Temp = Res;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
     
        for (auto head : lists)
        {
            if (head != NULL)
            {
                pq.push({ head->val, head });

            }
        }
       
        while (!pq.empty()) 
        {
            ListNode* minNode = pq.top().second;

            pq.pop();

            if (minNode->next != NULL)
            {
                pq.push({ minNode->next->val, minNode->next });
            }

            Temp->next = minNode;
            Temp = Temp->next;
        }
      
        return Res->next;
    }
};

int main()
{
    Solution sol;

    // 첫 번째 ListNode
    ListNode* node1 = new ListNode(1, new ListNode(4, new ListNode(5)));

    // 두 번째 ListNode
    ListNode* node2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    // 세 번째 ListNode
    ListNode* node3 = new ListNode(2, new ListNode(6));

    // ListNode 포인터를 담은 벡터 생성
    vector<ListNode*> vNode = { node1, node2, node3 };

    sol.mergeKLists(vNode);

    return 0;
}