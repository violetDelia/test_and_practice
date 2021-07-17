#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    vector<int> res;
    void makeres(ListNode *root)
    {
        if (!root)
            return;
        makeres(root->next);
        res.push_back(root->val);
        return;
    }
    vector<int> reversePrint(ListNode *head)
    {
        makeres(head);
        return res;
    }
};
int main()
{

    std::system("pause");
    return 0;
}