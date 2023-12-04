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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        vector<int> vList;

        // ��ȯ�ϱ� ���� res ����
        ListNode* res = new ListNode;

        // temp�� �����Ͽ� res�� �ʱ�ȭ�� ������ ������ ���׿��� ��Ÿ�� ������ ����
        // ���� �ּҰ��� �����Ƿ� temp->val�� ���� �ְ� res�� ��ȯ�ص� ���� ���� ���´�
        ListNode* temp = res;
      
        // �� ����Ʈ�� �ƹ��͵� ������ nullptr�� ��ȯ
        // res�� ������ �� �⺻���� 0�� �������Ƿ� �� ���� ��带 ��ȯ�ؾ� nullptr�� ��ȯ�ȴ�
        if (list1 == nullptr && list2 == nullptr)
        {
            return res->next;
        }

        while (list1 != nullptr)
        {
            vList.push_back(list1->val);
            list1 = list1->next;
        }

        while (list2 != nullptr)
        {
            vList.push_back(list2->val);
            list2 = list2->next;
        }

        // ���� ������������ ����
        sort(vList.begin(), vList.end());

        for (size_t i = 0; i < vList.size(); ++i)
        {
            temp->val = vList[i];
          
            // ���� ��尡 �ʿ��� ��� ���ο� ��� ����
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
    ListNode* list1 = {};
    ListNode* list2 = {};

    Solution sol;

    sol.mergeTwoLists(list1, list2);

    return 0;
}