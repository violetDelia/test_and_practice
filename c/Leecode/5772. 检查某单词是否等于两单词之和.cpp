#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int first = 0;
        int second = 0;
        int target = 0;
        for(char c : firstWord){
            first *= 10;
            first += c - 'a';
        }
        for(char c : secondWord){
            second *= 10;
            second += c - 'a';
        }
        for(char c :targetWord){
            target *= 10;
            target += c - 'a';
        }
        return target == first + second;
    }
};
int main()
{
    std::system("pause");
    return 0;
}