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
    ListNode* oddEvenList(ListNode* head)
    {
        ListNode* Oddres = new ListNode;
        ListNode* Oddtemp = Oddres;

        ListNode* Evenres = new ListNode;
        ListNode* Eventemp = Evenres;

        // 노드에 아무것도 없을 때
        if (head == nullptr)
        {
            return Oddres->next;
        }

        // 노드가 하나일 때
        if (head->next == nullptr)
        {
            Oddtemp->val = head->val;
            Oddtemp->next = head->next;

            return Oddres;
        }

        while (head->next != nullptr)
        {
            Oddtemp->val = head->val;
            Eventemp->val = head->next->val;


            // 노드의 개수가 홀수일 때
            if (head->next->next != nullptr)
            {
                head = head->next->next;

                Oddtemp->next = new ListNode;
                Oddtemp = Oddtemp->next;

                if (head->next != nullptr)
                {
                    Eventemp->next = new ListNode;
                    Eventemp = Eventemp->next;
                }

                if (head->next == nullptr)
                {
                    Oddtemp->val = head->val;
                    Eventemp = nullptr;
                    Oddtemp->next = Evenres;
                }
            }
            // 노드의 개수가 짝수일 때
            else if (head->next->next == nullptr)
            {
                head = head->next;
                Eventemp = nullptr;
                Oddtemp->next = Evenres;
                
            }
        }

        return Oddres;
    }
};

int main()
{
    Solution sol;

    //ListNode* list = new ListNode(1);
    //ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7)))))));
    sol.oddEvenList(list);

    return 0;
}