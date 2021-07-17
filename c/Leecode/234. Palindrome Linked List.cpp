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
    bool isPalindromeArray(vector<int> nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (r > l)
        {
            if (nums[r] != nums[l])
                return false;
            l++;
            r--;
        }
        return true;
    }
    bool isPalindrome(ListNode *head)
    {
        vector<int> count;
        while (head)
        {
            count.push_back(head->val);
            head = head->next;
        }
        return isPalindromeArray(count);
    }
};
int main()
{

    std::system("pause");
    return 0;
}