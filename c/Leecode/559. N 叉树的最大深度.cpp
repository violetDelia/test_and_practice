#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    int maxDepth(Node *root)
    {
        int max = 0;
        if (!root)
        {
            return max;
        }
        int temp;
        for (auto n : root->children)
        {
            temp = maxDepth(n);
            if (temp > max)
                max = temp;
        }
        return max + 1;
    }
};
int main()
{
    std::system("pause");
    return 0;
}