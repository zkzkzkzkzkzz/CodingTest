#include <algorithm>


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            // slow는 한칸, fast는 두칸씩 이동
            // 반복문이 끝나면 fast는 마지막 노드를, slow는 중간 노드를 가리킨다
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = sortList(slow->next);
        slow->next = nullptr;
        ListNode* left = sortList(head);

        return merge(left, right);
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode;
        ListNode* Temp = dummy;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                Temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                Temp->next = l2;
                l2 = l2->next;
            }

            Temp = Temp->next;
        }

        if (l1 != nullptr)
        {
            Temp->next = l1;
        }
        else
        {
            Temp->next = l2;
        }

        return dummy->next;
    }
};


int main()
{
    Solution Sol;

    ListNode* list = new ListNode(-1, new ListNode(5, new ListNode(3, new ListNode(4, new ListNode(0)))));

    Sol.sortList(list);

    return 0;
}