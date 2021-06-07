#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isUnique(string astr) {
        sort(astr.begin(),astr.end());
        char last = astr[0]-1;
        for( char op : astr){
            if(op == last)
                return false;
            last = op;
        }
        return true;
    }
};
int main()
{
    std::system("pause");
    return 0;
}