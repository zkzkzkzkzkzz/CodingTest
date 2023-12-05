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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* res = new ListNode;
        ListNode* temp = res;

        // 노드에 아무것도 없을 때
        if (head == nullptr)
        {
            return res->next;
        }

        // 노드가 하나일 때
        if (head->next == nullptr)
        {
            temp->val = head->val;
            temp->next = head->next;

            return res;
        }

        // 노드가 2개 이상
        while (head->next != nullptr)
        {
            temp->val = head->next->val;

            temp->next = head;

            // 노드의 개수가 홀수일 때
            if (head->next->next != nullptr)
            {
                head = head->next->next;

                temp->next->next = new ListNode;
                temp = temp->next->next;

                if (head->next == nullptr)
                {
                    temp->val = head->val;
                }
            }

            // 노드의 개수가 짝수일 때
            else if (head->next->next == nullptr)
            {
                temp->next->next = nullptr;
                return res;
            }
        }
            
        return res;
    }
};

int main()
{
    Solution sol;

    //ListNode* list = new ListNode(1);
    ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    //ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7)))))));
    sol.swapPairs(list);

    return 0;
}