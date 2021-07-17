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
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int canBePlant = 0;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0 &&
                (i - 1 < 0 || flowerbed[i - 1] == 0) &&
                (i + 1 >= flowerbed.size() || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                ++i;
                canBePlant++;
            }
        }
        return canBePlant >= n;
    }
};
int main()
{
    std::system("pause");
    return 0;
}