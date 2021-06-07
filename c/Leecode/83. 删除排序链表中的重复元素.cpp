#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *last = head;
        ListNode *p = head->next;
        while (p)
        {
            if (p->val == last->val)
                last->next = p->next;
            else
                last = p;
            p = p->next;
        }
        return head;
    }
};
int main()
{

    std::system("pause");
    return 0;
}