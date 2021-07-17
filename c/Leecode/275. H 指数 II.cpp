#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for(int i = citations.size()-1; i >= 0; i--)
        {
            if(n - i  < citations[i])
                continue;
            if(n - i  == citations[i])
                return n - i ;   
            if( n - i > citations[i])
                return n-i-1;    
        }
        return citations.size();
    }
};
int main()
{
    std::system("pause");
    return 0;
}