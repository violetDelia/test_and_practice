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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;
        if (headA == headB)
            return headB;
        while (headA)
        {
            for (ListNode *p = headB; p; p = p->next)
            {
                if (p == headA)
                    return p;
            }
            headA = headA->next;
        }
        return nullptr;
    }
};
int main()
{

    std::system("pause");
    return 0;
}