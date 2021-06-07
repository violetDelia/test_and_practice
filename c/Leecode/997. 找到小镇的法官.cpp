#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<int> count(N+1, 0);
        for (int j = 0;j<trust.size();++j)
        {
            count[trust[j][1]]++;
        }
        for (int k = 1;k<count.size();++k)
        {
            if (count[k] == N - 1)
            {
                int i = 0;
                for (; i < trust.size(); ++i)
                {
                    if (trust[i][0] == k)
                        break;
                }
                if (i == trust.size())
                    return k;
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> a = {{1,3},{2,3}};
    Solution b;
    b.findJudge(3,a);

    std::system("pause");
    return 0;
}