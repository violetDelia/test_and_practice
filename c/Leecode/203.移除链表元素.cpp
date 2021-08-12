/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (50.86%)
 * Likes:    659
 * Dislikes: 0
 * Total Accepted:    204K
 * Total Submissions: 400.9K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [], val = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [7,7,7,7], val = 7
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 列表中的节点数目在范围 [0, 10^4] 内
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head != nullptr && head->val == val)
        {
            head = head->next;
        }
        if (head == nullptr)
            return head;
        ListNode *last = head;
        ListNode *position = head->next;
        while (position != nullptr)
        {
            if (position->val == val)
            {
                last->next = position->next;
                position = last->next;
            }
            else
            {
                position = position->next;
                last = last->next;
            }
        }
        return head;
    }
};

// @lc code=end
