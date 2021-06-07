#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    string defangIPaddr(string &address) {
        int p = 0;
        int l = address.size();
        for(int i = 0; i < l; ++i){
            if(address[p] == '.'){
                address.insert(address.begin()+p,'[');
                ++p;
                ++p;
                address.insert(address.begin()+p,']');
                ++p;
            }else{
                ++p;
            }
        }
        return address;
    }
};
int main()
{
    std::system("pause");
    return 0;
}