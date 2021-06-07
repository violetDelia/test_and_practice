#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i = 0;
        int p = 0;
        int end = prices.size() - 1;
        int max = 0;
        while (i <= end)
        {
            if (prices[i] > prices[p])
                max += prices[i] - prices[p];
            p = i;
            i++;
        }
        return max;
    }
};

int main()
{

    std::system("pause");
    return 0;
}