#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        for(int i = 0; i < arr1.size(); ++i){
            int j = 0;
            for(; j < arr2.size(); ++j){
                if(abs(arr1[i]-arr2[j]) <= d)
                    break;
            }
            if(j == arr2.size())
                ++res;
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}