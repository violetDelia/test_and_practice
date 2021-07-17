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
    void swp (vector<char> &s, int left, int right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        return;
    }
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        while(right > left){
            swp(s,left,right);
            left++;
            right--;
        }
        return;
    }
};
int main()
{
    std::system("pause");
    return 0;
}