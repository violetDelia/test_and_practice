#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        multimap<int, int> map;
        for (int i = 0; i < arr.size(); ++i)
        {
            map.insert(make_pair(arr[i], i));
        }
        int count = 0;
        int last;
        for (auto x : map)
        {
            if (x.second == 0)
            {
                last = x.first - 1;
                break;
            }
        }
        for (auto x : map)
        {
            if (last != x.first)
            {
                last = x.first;
                ++count;
            }
                arr[x.second] = count;
            ;
        }
        return arr;
    }
};

int main()
{

    vector<int> a = {100, 100, 100};
    Solution b;
    b.arrayRankTransform(a);
    std::system("pause");
    return 0;
}