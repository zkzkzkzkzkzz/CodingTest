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

        // ��忡 �ƹ��͵� ���� ��
        if (head == nullptr)
        {
            return res->next;
        }

        // ��尡 �ϳ��� ��
        if (head->next == nullptr)
        {
            temp->val = head->val;
            temp->next = head->next;

            return res;
        }

        // ��尡 2�� �̻�
        while (head->next != nullptr)
        {
            temp->val = head->next->val;

            temp->next = head;

            // ����� ������ Ȧ���� ��
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

            // ����� ������ ¦���� ��
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