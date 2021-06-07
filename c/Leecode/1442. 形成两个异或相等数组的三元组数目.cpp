#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<vector<int>>  sum(arr.size(),vector<int>(arr.size(),0));
        vector<pair<int,int>> dp;
        int res=0;
        int n = 0;
        for( int i = 0; i < arr.size(); i++){
            sum [i][i] = arr[i];
            for(int k = i+1; k < arr.size(); ++k){
                sum[i][k]= sum[i][k-1]^arr[k];
                if( sum[i][k] == 0)
                    dp.push_back({i,k});
            }
        }
        for(auto position : dp){
            int left = position.first;
            int right = position.second;
            int mid = left+1;
            for(;mid <= right; ++mid){
                if(sum[right][mid-1]==sum[mid][left])
                   ++res;
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