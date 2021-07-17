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
        ListNode(int x) : val(x), next(NULL) {}
    };

public:
    void deletenext(ListNode *p)
    {
        if (p->next->next)
        {
            p->next = p->next->next;
            return;
        }
        p->next = NULL;
        return;
    }
    ListNode *deleteNode(ListNode *&head, int val)
    {
        ListNode *p = head;
        if (p->val == val)
        {
            head = head->next;
            return head;
        }
        while (p->next)
        {
            if (p->next->val == val)
            {
                deletenext(p);
                return head;
            }
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