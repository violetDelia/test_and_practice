#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int>  count;
        for(int n : arr){
            count[n]++;
        }
        sort(arr.begin(),arr.end(),[=](int a,int b){return abs(a)<abs(b);});
        for (int n : arr){
            if(count[n] >0)
            {
                count[n]--;
                if(count[2*n]==0)
                    return false;
                count[2*n]--;
            }
        }
        return true;
    }
};

int main()
{
    Solution a;
    vector<int> b = {-2,-4,-8,6,12,7,14};
    a.canReorderDoubled(b);
    std::system("pause");
    return 0;
}