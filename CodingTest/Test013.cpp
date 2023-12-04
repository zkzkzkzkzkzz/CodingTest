#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        vector<int> vList;

        // 머리가 없을 경우 추가할 노드가 없다
        while (head != nullptr)
        {
            vList.push_back(head->val);
            head = head->next;
        }

        int Left = 0;
        int Right = vList.size() - 1;

        while (Left < Right)
        {
            if (vList[Left] != vList[Right])
            {
                return false;
            }
            
            ++Left;
            --Right;
        }

        return true;
    }
};


int main()
{
    ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(1)))));

    Solution sol;

    sol.isPalindrome(list);

    return 0;
}