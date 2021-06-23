#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
    int guess(int n){}
public:
    int guessNumber(int n) {
        int max = n;
        int min = 1;
        while(max >= min){
            int mid = min + (max-min)/2;
            if(guess(mid) == 0){
                return mid;
            }else if (guess(mid) == 1){
                min = mid +1;
            }else{
                max = mid -1;
            }
        }
        return -1;
    }
};
int main()
{
   
    std::system("pause");
    return 0;
}