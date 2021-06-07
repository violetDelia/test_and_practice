#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    if (!head || !head->next)
        return head;
    struct ListNode *position = head;
    struct ListNode *last = NULL;
    struct ListNode *N = position->next;
    while (N)
    {
        position->next = last;
        last = position;
        position = N;
        N = N->next;
    }
    position->next = last;
    return position;
}