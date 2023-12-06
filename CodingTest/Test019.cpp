#include <vector>

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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode* Res = new ListNode;
        ListNode* temp = Res;

        vector<int> vList;

        // 노드에 아무것도 없을 때
        if (head == nullptr)
        {
            return Res->next;
        }


        // 노드가 하나일 때
        if (head->next == nullptr)
        {
            temp->val = head->val;
            temp->next = head->next;

            return Res;
        }

        while (head != nullptr)
        {
            vList.push_back(head->val);
            head = head->next;
        }

        // 역순을 취할 시작 인덱스
        int Lidx = left - 1;
        // 역순을 취할 마지막 인덱스
        int Ridx = right - 1;

        // reverse 함수는 범위 [first, last)를 역순으로 만든다
        // [first, last)는 반열린 구간을 나타내는데,
        // 이는 first는 포함, last는 포함되지 않는다는 것을 의미한다
        reverse(vList.begin() + Lidx, vList.begin() + Ridx + 1);

        for (size_t i = 0; i < vList.size(); ++i)
        {
            temp->val = vList[i];

            if (i < vList.size() - 1)
            {
                temp->next = new ListNode;
                temp = temp->next;
            }
        }

        return Res;
    }
};



int main()
{
    Solution sol;

    //ListNode* list = new ListNode(1);
    ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    //ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    //ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7)))))));
    sol.reverseBetween(list , 1, 4);

    return 0;
}