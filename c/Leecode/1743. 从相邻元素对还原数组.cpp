#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
         unordered_map<int, vector<int>> adjacentTable;
        for (auto a: adjacentPairs) {
            adjacentTable[a[0]].push_back(a[1]);
            adjacentTable[a[1]].push_back(a[0]);
        }
        int startNum;
        for (auto iter = adjacentTable.begin(); iter != adjacentTable.end(); ++iter) {
            if (iter->second.size() == 1) {
                startNum = iter->first;
                break;
            }
        }
        vector<int> res;
        int left = startNum;
        int mid = adjacentTable[left][0];
        res.push_back(left);
        res.push_back(mid);
        int n = adjacentPairs.size();
        while (res.size() != n + 1) {
            auto candidata = adjacentTable[mid];
            for (auto r : candidata) {
                if (r != left) {
                    res.push_back(r);
                    left = mid;
                    mid = r;
                    break;
                }
            }
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}