#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int first = 0;
        for (int i = 1; i <= encoded.size()+1; ++i){
            first ^= i;
        }
        for (int k = 1; k <encoded.size(); k += 2 ){
            first ^= encoded[k];
        }
        vector <int> res;
        res.push_back(first);
        for(int i = 0; i < encoded.size(); ++i){
            res.push_back(res[i] ^ encoded[i]);
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}