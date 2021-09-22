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
    int min(int x, int y)
    {
        return x < y ? x : y;
    }
    /*int max (int x, int y){
        return x > y ? x : y;
    }
    int cap (vector<int> height, int left, int right){
        return (right-left) * min(height[left],height[right]);
    }
    void newposition(vector<int> height, int &left, int &right){
        if(height[left] > height [right])
            right--;
        else
            left++;
        return;
    }*/
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        while (right > left)
        {
            int c = (right - left) * min(height[left], height[right]);
            if (c > res)
                res = c;
            if (height[left] > height[right])
                right--;
            else
                left++;
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}