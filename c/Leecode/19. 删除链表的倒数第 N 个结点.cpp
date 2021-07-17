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
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
        return;
    }
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *p = head;
        while (k)
        {
            p = p->next;
            --k;
        }
        while (p)
        {
            head = head->next;
            p = p->next;
        }
        return head;
    }
    void deleteRear(ListNode *&head)
    {
        ListNode *p = head->next;
        if (!p)
        {
            head = nullptr;
            return;
        }
        ListNode *h = head;
        while (p->next)
        {
            h = p;
            p = p->next;
        }
        h->next = nullptr;
        return;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p = getKthFromEnd(head, n);
        if (p->next)
        {
            deleteNode(p);
            return head;
        }
        deleteRear(head);
        return head;
    }
};
int main()
{

    std::system("pause");
    return 0;
}