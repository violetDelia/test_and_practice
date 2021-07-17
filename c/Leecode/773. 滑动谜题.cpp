#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    set<vector<vector<int>>> been;
    queue<pair<vector<vector<int>> , int>> count;

    vector<vector<vector<int>>> next(vector<vector<int>> node){
        vector<vector<vector<int>>> res;
        int zi;
        int zj;
        for (int i = 0; i < node.size(); i++)
            for (int j = 0; j < node[0].size(); j++)
            {
                if (node[i][j] == 0)
                {
                    zi = i;
                    zj = j;
                }
            }
        if (zj > 0)
        {
            vector<vector<int>> newnode =  node;
            newnode[zi][zj-1] = node [zi][zj];
            newnode[zi][zj] = node [zi][zj-1];
            res.push_back(newnode);
        }
        if(zj < 2){
            vector<vector<int>> newnode =  node;
            newnode[zi][zj+1] = node [zi][zj];
            newnode[zi][zj] = node [zi][zj+1];
            res.push_back(newnode);
        }
         if(zi > 0){
            vector<vector<int>> newnode =  node;
            newnode[zi][zj] = node [zi-1][zj];
            newnode[zi-1][zj] = node [zi][zj];
            res.push_back(newnode);
        }
        if(zi < 1){
            vector<vector<int>> newnode =  node;
            newnode[zi][zj] = node [zi+1][zj];
            newnode[zi+1][zj] = node [zi][zj];
            res.push_back(newnode);
        }
        return res;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> init = {{1,2,3},{4,5,0}};
        if(board == init)
            return 0;
        count.push({init,0});
        while(!count.empty()){
           vector<vector<int>>  node = count.front().first;
            int n = count.front().second;
            count.pop();
            auto nextnode = next(node);
            for (auto node : nextnode)
            {
                if (node == board)
                    return n + 1;
                if (!been.count(node)){
                    been.emplace(node);
                count.push({node, n + 1});
                }
            }
        }
        return -1;
    }
};
int main()
{
    vector<vector<int>> c = {{4, 1, 2}, {5, 4, 0}};
    Solution a;
    a.slidingPuzzle(c);
    std::system("pause");
    return 0;
}