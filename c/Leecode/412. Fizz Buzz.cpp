#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string makeString(int n){
        if(n%15 == 0)
            return "FizzBuzz";
        if(n%3 == 0)
            return "Fizz";
        if(n%5 == 0)
            return "Buzz";
        string s = "";
        while(n)
        {
            char c = '0'+n%10;
            s = c+s;
            n/=10;
        }
    }
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        int i = 0;
        while(++i<=n)
        {
            string s = makeString(i);
            res.push_back(s);
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}