#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int minOperationsMaxProfit(vector<int> &customers,
                               int boardingCost, int runningCost)
    {
        int wait = 0;
        int sum = 0;
        int max = 0;
        int count = 0;
        int res = -1;
        while (count < customers.size() || wait > 0)
        {
            if (count < customers.size())
                wait += customers[count];
            int willon = wait;
            if (wait > 4)
                willon = 4;
            sum += willon;
            wait -= willon;
            int pro = sum * boardingCost - (count + 1) * runningCost;
            if (pro > max)
            {
                max = pro;
                res = count + 1;
            }
            ++count;
        }
        return res;
    }
};
int main()
{
    vector <int> a = {10,10,1,0,0};
    Solution b;
    b.minOperationsMaxProfit(a,4,4);
    std::system("pause");
    return 0;
}