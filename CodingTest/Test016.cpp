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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* res = new ListNode;
        ListNode* temp = res;

        // 10이상일 때 올림용
        int RoundUp = 0;
        
        // RoundUp이 0이 아닐때도 들어오게 하지않으면 9999999, 9999의 경우
        // 마지막에 자릿수를 올려줘야 하는데 l1, l2가 nullptr이기 때문에 while에 들어오지 않아
        // 자릿수를 올려주지 못한다. 이를 위해 RoundUp이 0이 아닐때도 조건에 추가한다
        while (l1 != nullptr || l2 != nullptr || RoundUp != 0)
        {
            // 10이상이면 다음 자릿수에서 1을 더해줘야하므로 미리 RoundUp을 더하고
            // 그다음 10 이상인지 다시 체크한다
            int Sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + RoundUp;

            // 10 이상이면 1, 미만이면 0
            // 각 자릿수끼리만 더하기 때문에 2 이상이 나올 일은 없다
            RoundUp = Sum / 10;

            temp->val = Sum % 10;

            l1 = (l1 ? l1->next : nullptr);
            l2 = (l2 ? l2->next : nullptr);

            if (l1 != nullptr || l2 != nullptr || RoundUp != 0)
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

    ListNode* list1 = new ListNode(2, new ListNode(0, new ListNode(6, new ListNode(1))));
    ListNode* list2 = new ListNode(6, new ListNode(9, new ListNode(1)));


    sol.addTwoNumbers(list1, list2);

    return 0;
}