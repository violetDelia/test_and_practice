#include <iostream>
#include <stack>
#include <vector>
#include<string>
using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
        string res = "";
        while(num/7!=0){
            res=to_string(abs(num%7))+res;
            num/=7;
        }
        return to_string(num%7)+res;

    }
};
int main()
{
    std::system("pause");
    return 0;
}