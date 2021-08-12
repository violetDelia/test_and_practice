/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 *
 * https://leetcode-cn.com/problems/design-hashset/description/
 *
 * algorithms
 * Easy (64.81%)
 * Likes:    169
 * Dislikes: 0
 * Total Accepted:    61.5K
 * Total Submissions: 94.9K
 * Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n' +
  '[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
 *
 * 不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
 * 
 * 实现 MyHashSet 类：
 * 
 * 
 * void add(key) 向哈希集合中插入值 key 。
 * bool contains(key) 返回哈希集合中是否存在这个值 key 。
 * void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["MyHashSet", "add", "add", "contains", "contains", "add", "contains",
 * "remove", "contains"]
 * [[], [1], [2], [1], [3], [2], [2], [2], [2]]
 * 输出：
 * [null, null, null, true, false, null, true, null, false]
 * 
 * 解释：
 * MyHashSet myHashSet = new MyHashSet();
 * myHashSet.add(1);      // set = [1]
 * myHashSet.add(2);      // set = [1, 2]
 * myHashSet.contains(1); // 返回 True
 * myHashSet.contains(3); // 返回 False ，（未找到）
 * myHashSet.add(2);      // set = [1, 2]
 * myHashSet.contains(2); // 返回 True
 * myHashSet.remove(2);   // set = [1]
 * myHashSet.contains(2); // 返回 False ，（已移除）
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 最多调用 10^4 次 add、remove 和 contains 。
 * 
 * 
 * 
 * 
 * 进阶：你可以不使用内建的哈希集合库解决此问题吗？
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class MyHashSet
{
private:
    int prime;
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    vector<ListNode *> myset;
    int hash(int key)
    {
        return key % prime;
    }
    ListNode *find(int p, int key)
    {
        ListNode *head = myset[p];
        while (head != nullptr)
        {
            if (head->val == key)
                return head;
            head = head->next;
        }
        return nullptr;
    }
    void myinsert(int p, int key)
    {
        ListNode *newnode = new ListNode(key);
        newnode->next = myset[p];
        myset[p] = newnode;
    }
    void mydelete(int p, int key)
    {
        ListNode *head = myset[p];
        if (head->val == key)
        {
            myset[p] = head->next;
            delete (head);
            return;
        }
        while (head->next != nullptr && head->next->val != key)
        {
            head = head->next;
        }
        ListNode *temp = head->next;
        head->next = head->next->next;
        delete (temp);
        return;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() : prime(10000), myset(prime, nullptr)
    {
    }

    void add(int key)
    {
        if (!contains(key))
        {
            myinsert(hash(key), key);
        }
        return;
    }

    void remove(int key)
    {
        if (!contains(key))
            return;
        mydelete(hash(key), key);
        return;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return find(hash(key), key) != nullptr;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
