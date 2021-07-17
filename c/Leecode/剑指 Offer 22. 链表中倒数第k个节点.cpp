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
};
int main()
{

    std::system("pause");
    return 0;
}