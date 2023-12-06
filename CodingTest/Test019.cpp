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

        // ��忡 �ƹ��͵� ���� ��
        if (head == nullptr)
        {
            return Res->next;
        }


        // ��尡 �ϳ��� ��
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

        // ������ ���� ���� �ε���
        int Lidx = left - 1;
        // ������ ���� ������ �ε���
        int Ridx = right - 1;

        // reverse �Լ��� ���� [first, last)�� �������� �����
        // [first, last)�� �ݿ��� ������ ��Ÿ���µ�,
        // �̴� first�� ����, last�� ���Ե��� �ʴ´ٴ� ���� �ǹ��Ѵ�
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