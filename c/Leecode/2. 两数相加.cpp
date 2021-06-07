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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode();
        ListNode *sum = res;
        int count = 0;
        while (l1 || l2 || count)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int n = n1 + n2 + count;
            res->next = new ListNode(n % 10);
            count = n / 10;
            res = res->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return sum->next;
    }
};

int main()
{

    std::system("pause");
    return 0;
}