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

        // 10�̻��� �� �ø���
        int RoundUp = 0;
        
        // RoundUp�� 0�� �ƴҶ��� ������ ���������� 9999999, 9999�� ���
        // �������� �ڸ����� �÷���� �ϴµ� l1, l2�� nullptr�̱� ������ while�� ������ �ʾ�
        // �ڸ����� �÷����� ���Ѵ�. �̸� ���� RoundUp�� 0�� �ƴҶ��� ���ǿ� �߰��Ѵ�
        while (l1 != nullptr || l2 != nullptr || RoundUp != 0)
        {
            // 10�̻��̸� ���� �ڸ������� 1�� ��������ϹǷ� �̸� RoundUp�� ���ϰ�
            // �״��� 10 �̻����� �ٽ� üũ�Ѵ�
            int Sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + RoundUp;

            // 10 �̻��̸� 1, �̸��̸� 0
            // �� �ڸ��������� ���ϱ� ������ 2 �̻��� ���� ���� ����
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