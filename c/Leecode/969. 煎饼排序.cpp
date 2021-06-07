#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findmaxposition(vector<int> a, int n)
    {
        if (n <= 0)
            return -1;
        int max = INT_MIN;
        int maxp = 0;
        for (int i = 0; i <= n; ++i)
        {
            if (a[i] >= max){
                max = a[i];
                maxp = i;
            }
                
        }
        return maxp;
    }
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> res;
        int tail = arr.size()-1;
        while (tail)
        {
            int i = findmaxposition(arr, tail);
            if (i == tail)
                tail--;
            else
            {
                res.emplace_back(i+1);
                reverse(arr.begin(),arr.begin()+i+1);
                res.emplace_back(tail+1);
                reverse(arr.begin(),arr.begin()+tail+1);
                tail--;
            }
        }
        return res;
    }
};

int main()
{
    vector <int>a = {1,2,4,5,6,1,2,5,9};
    Solution b;
    b.pancakeSort(a);
    std::system("pause");
    return 0;
}