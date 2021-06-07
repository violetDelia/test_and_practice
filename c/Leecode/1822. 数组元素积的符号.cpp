#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0)
                return 0;
            if(nums[i] < 0)
                ++count;
        }
        if(count%2)
            return -1;
        return 1;
    }
};
int main()
{
    std::system("pause");
    return 0;
}