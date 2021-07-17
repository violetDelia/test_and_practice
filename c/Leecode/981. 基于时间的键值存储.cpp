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
class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> mymp;
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mymp[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        auto &pairs = mymp[key];
        pair<int,string> t = {timestamp+1, ""};
        auto p = lower_bound(pairs.begin(),pairs.end(),t);
        if(p != pairs.begin())
            return (p-1)->second;
        return "";
    }
};
int main()
{
    TimeMap a;
    a.set("foo","bar",4);
    a.set("foo","bar2",4);
    a.get("foo",5);
    std::system("pause");
    return 0;
}