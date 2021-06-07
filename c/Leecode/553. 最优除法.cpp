#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size() == 1)
            return to_string(nums[0]);
        string res = to_string(nums[0]);
        res += '/';
        if(nums.size() != 2)
        res += '(';
        for(int i = 1; i < nums.size(); ++i){
            res += to_string(nums[i]);
            if(i == nums.size()-1 ){
                if(i != 1)
                    res += ')';
            }
            else 
                res += '/';
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}