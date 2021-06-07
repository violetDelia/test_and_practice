#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode *res;
        if (l1->val <= l2->val)
        {
            res = l1;
            l1 = l1->next;
        }
        else
        {
            res = l2;
            l2 = l2->next;
        }
        ListNode* rev = res;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                res->next = l1;
                l1 = l1->next;
            }
            else
            {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        if (l1)
            res->next = l1;
        else
            res->next = l2;
        return rev;
    }
};

int main()
{

    std::system("pause");
    return 0;
}