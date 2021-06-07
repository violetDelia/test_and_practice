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
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *p1 = head->next;
        ListNode *p2 = head->next->next;
        while (p2)
        {
            if (p1 == p2)
                return true;
            p1 = p1->next;
            p2 = p2->next;
            if (!p2)
                return false;
            p2 = p2->next;
        }
        return false;
    }
};
int main()
{

    std::system("pause");
    return 0;
}