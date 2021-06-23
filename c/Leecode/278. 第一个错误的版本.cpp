#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
    bool isBadVersion(int n){
        return 0;
    }
public:
    int firstBadVersion(int n) {
        int res = 1;
        int min = 1;
        int max = n;
        while(min < max){
            int mid = min+(max-min)/2;
            if(isBadVersion(mid)){
                max = mid;
                res = max;}else{
                    min = mid+1;
                    res = min;
                }
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}