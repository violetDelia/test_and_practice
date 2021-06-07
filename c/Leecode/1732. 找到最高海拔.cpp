#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max = 0;
        int count = 0;
        for(int n: gain){
            count +=n;
            max = max > count ? max : count;
        }
        return max;
    }
};
int main()
{
    std::system("pause");
    return 0;
}