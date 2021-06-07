#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
     int sum(int m, int n, int num){
        int count = 0;
        for( int i = 1; i <= m; ++i){
            if(i > num)
                break;
            if ( num / i >= n)
                count += n;
            else 
                count += num/i;
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int low = 0;
        int high = k;
        int res = 1;
        while(low < high){
            int mid = low + (high - low) /2;
            if(sum(m,n,mid) < k){
                low = mid+1;
                res = low;
            }else{
                high = mid;
                res = high;
            }
        }
        return res;
    }
};
int main()
{
    Solution a;
    a.findKthNumber(2,3,6);
    std::system("pause");
    return 0;
}