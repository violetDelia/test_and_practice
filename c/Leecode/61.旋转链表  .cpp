#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (head || k == 0 || head->next == NULL)
    {
        int lenth = 1;
        struct ListNode *position = head;
        while (position->next)
        {
            lenth++;
            position = position->next;
        }
        int p = lenth - k % lenth;
        if (p == lenth)
        {
            return head;
        }
        position->next = head;
        position = position->next;
        while (p--)
        {
            position = position->next;
        }
        struct ListNode *target = position->next;
        position->next = NULL;
        return target;
    }
    return head;
}
int main()
{
}
