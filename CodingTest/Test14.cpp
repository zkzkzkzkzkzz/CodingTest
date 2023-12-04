#include <vector>
#include <algorithm>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        vector<int> vList;

        // 반환하기 위한 res 생성
        ListNode* res = new ListNode;

        // temp를 생성하여 res로 초기화를 해주지 않으면 코테에서 런타임 오류가 생김
        // 같은 주소값을 가지므로 temp->val에 값을 넣고 res를 반환해도 같은 값이 나온다
        ListNode* temp = res;
      
        // 두 리스트에 아무것도 없으면 nullptr을 반환
        // res를 생성할 때 기본값인 0이 들어가있으므로 그 다음 노드를 반환해야 nullptr이 반환된다
        if (list1 == nullptr && list2 == nullptr)
        {
            return res->next;
        }

        while (list1 != nullptr)
        {
            vList.push_back(list1->val);
            list1 = list1->next;
        }

        while (list2 != nullptr)
        {
            vList.push_back(list2->val);
            list2 = list2->next;
        }

        // 벡터 오름차순으로 정렬
        sort(vList.begin(), vList.end());

        for (size_t i = 0; i < vList.size(); ++i)
        {
            temp->val = vList[i];
          
            // 다음 노드가 필요할 경우 새로운 노드 생성
            if (i < vList.size() - 1)
            {
                temp->next = new ListNode;
                temp = temp->next;
            }
        }

        return res;
    }
};


int main()
{
    ListNode* list1 = {};
    ListNode* list2 = {};

    Solution sol;

    sol.mergeTwoLists(list1, list2);

    return 0;
}