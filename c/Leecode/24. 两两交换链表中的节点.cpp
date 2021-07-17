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
    void swp(ListNode *&first, ListNode *&second)
    {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        return;
    }
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *headl = head;
        while (headl && headl->next)
        {
            swp(headl, headl->next);
            headl = headl->next->next;
        }
        return head;
    }
};
int main()
{

    std::system("pause");
    return 0;
}