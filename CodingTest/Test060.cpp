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
    ListNode* insertionSortList(ListNode* head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode* Res = new ListNode;
        ListNode* Temp = Res;

        // 비교용 리스트
        ListNode* Compare = head;

        while (Compare)
        {
            ListNode* NextNode = Compare->next;
            insertIntoList(Temp, Compare);
            Compare = NextNode;
        }

        return Res->next;
    }

private:
    void insertIntoList(ListNode* res, ListNode* _insert)
    {
        ListNode* temp = res;

        while (temp->next && temp->next->val < _insert->val)
        {
            temp = temp->next;
        }

        _insert->next = temp->next;
        temp->next = _insert;
    }
};


int main()
{
    Solution Sol;

    ListNode* list = new ListNode(5, new ListNode(-1, new ListNode(3, new ListNode(4, new ListNode(0)))));

    Sol.insertionSortList(list);

    return 0;
}