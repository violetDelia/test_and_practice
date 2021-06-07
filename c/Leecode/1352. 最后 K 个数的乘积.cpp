#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class ProductOfNumbers {
private: 
    #define Max 40010
    int nums[Max];
    int l;
public:
    ProductOfNumbers() {
        l = 0;
    }
    
    void add(int num) {
        nums[l++] = num;
    }
    
    int getProduct(int k) {
        int sum = 1;
        int n = l;
        for(int i = 0; i < k; ++i){
            sum*=nums[--n];
        }
        return sum;
    }
};

int main()
{
    
}