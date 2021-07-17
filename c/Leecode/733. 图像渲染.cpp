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
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        queue<pair<int, int>> node;
        node.push({sr, sc});
        int beforcolor = image[sr][sc];
        image[sr][sc] = newColor;
        auto check = [=, &image, &node](int r, int c)
        {
            if (r >= 0 && r < image.size() && c >= 0 && c < image[0].size())
            {
                if (image[r][c] == beforcolor)
                {
                    image[r][c] = newColor;
                    node.push({r, c});
                }
            }
            return;
        };
        while (!node.empty())
        {
            int r = node.front().first;
            int c = node.front().second;
            node.pop();
            check(r, c - 1);
            check(r, c + 1);
            check(r + 1, c);
            check(r - 1, c);
        }
        return image;
    }
};
int main()
{
    std::system("pause");
    return 0;
}