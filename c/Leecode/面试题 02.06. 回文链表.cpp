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

    ListNode *front;

public:
    bool issame(ListNode *root)
    {
        if (root == nullptr)
            return true;
        if (issame(root->next) == false)
            return false;
        if (root->val != front->val)
            return false;
        front = front->next;
        return true;
    }

    bool isPalindrome(ListNode *head)
    {
        front = head;
        return issame(head);
    }
};
int main()
{

    std::system("pause");
    return 0;
}