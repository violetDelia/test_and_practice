#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int lenth = height.size() - 1;
        int i = 1;
        int maxposition = 0;
        int V = 0;
        int v = 0;
        while (i <= lenth)
        {
            if (height[i] < height[maxposition])
            {
                v += height[maxposition] - height[i];
            }
            else
            {
                V += v;
                v = 0;
                maxposition = i;
            }
            ++i;
        }
        v = 0;
        i = lenth - 1;
        int biginposition = lenth;
        while (i >= maxposition)
        {
            if (height[i] < height[biginposition])
                v += height[biginposition] - height[i];
            else
            {
                V += v;
                v = 0;
                biginposition = i;
            }
            i--;
        }

        return V;
    }
};

int main()
{
    vector<int> res = {4, 2, 3};
    Solution a;
    a.trap(res);
    std::system("pause");
    return 0;
}