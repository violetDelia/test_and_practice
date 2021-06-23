#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int count[26] = {0,};
        for(string s: words){
            for(char c: s){
                count[c-'a']++;
            }
        }
        bool res = true;
        int n = words.size();
        for(int i : count){
            if(i != 0 && i%n !=0){
                res = false;
                break;}
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}