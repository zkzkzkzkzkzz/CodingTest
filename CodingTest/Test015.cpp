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
    ListNode* reverseList(ListNode* head)
    {
        vector<int> vList;

        ListNode* res = new ListNode;
        ListNode* temp = res;

        if (head == nullptr)
        {
            return res->next;
        }

        while (head != nullptr)
        {
            vList.push_back(head->val);
            head = head->next;
        }

        reverse(vList.begin(), vList.end());

        for (size_t i = 0; i < vList.size(); ++i)
        {
            temp->val = vList[i];

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
    Solution sol;

    ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(1)))));

    sol.reverseList(list);

    return 0;
}