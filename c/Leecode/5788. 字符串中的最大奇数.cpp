#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size()-1;
        for(;i>=0;i--){
            if((num[i]-'0')&1)
                break;
            else  
                num.pop_back();
        }
        return num;
    }
};
int main()
{
    Solution a;
    a.largestOddNumber("15462");
    std::system("pause");
    return 0;
}