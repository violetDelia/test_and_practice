#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    string maxValue(string n, int x) {
        string res = "";
        char c = char(x) + '0'-0;
        if( n[0] == '-'){
            res += n[0];
            int i = 1;
            for(; i < n.size();){
                if(n[i]>c){
                    res += c;
                    break;
                }else{
                    res += n[i];
                    i++;
                }
            }
            if (i == n.size()){
                res +=c;
            }else{
                for(;i<n.size();++i){
                    res += n[i];
                }
            }
        }else{
            int i = 0;
            for(; i < n.size();){
                if(n[i]<c){
                    res += c;
                    break;
                }else{
                    res += n[i];
                    i++;
                }
            }
            if (i == n.size()){
                res +=c;
            }else{
                for(;i<n.size();++i){
                    res += n[i];
                }
            }
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}