#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int res = 0;
        vector<queue<pair<int, int>>> count(26);
        for (int i = 0; i < words.size(); ++i)
        {
            count[words[i][0] - 'a'].push({i, 0});
        }
        for (char c : s)
        {
            queue<pair<int, int>> &q = count[c - 'a'];
            for (int k = q.size(); k > 0; k--)
            {
                auto [wordIndex, posIndex] = q.front();
                q.pop();
                posIndex++;
                if (words[wordIndex].size() == posIndex)
                {
                    res++;
                }
                else
                {
                    count[words[wordIndex][posIndex] - 'a'].push({wordIndex, posIndex});
                }
            }
        }
        return res;
    }
};
int main()
{
    string s = "abcde";
    vector<string> a = {"a", "bb", "acd", "ace"};
    Solution b;
    b.numMatchingSubseq(s, a);
    std::system("pause");
    return 0;
}