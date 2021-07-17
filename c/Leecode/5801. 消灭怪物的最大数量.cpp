#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> maxtime;
        for(int i = 0; i < dist.size(); ++i)
        {
            double max = (double)dist[i]/speed[i];
            maxtime.push_back(max);
        }
        sort(maxtime.begin(),maxtime.end());
        int res = 0;
        for(int i = 0; i < maxtime.size(); ++i){
            if(i < maxtime[i])
                break;
            res++;
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}