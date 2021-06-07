#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> count;
        for (int i : answers)
        {
            ++count[i];
        }
        int res = 0;
        for (auto [x, y] : count)
        {
            if (y)
                res += ((y+x) / (x + 1)) * (x + 1);
            
        }
        return res;
    }
};

int main()
{

    std::system("pause");
    return 0;
}