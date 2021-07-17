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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int one = 0;
        int two = 0;
        while(one < nums1.size() && two < nums2.size()){
            if(nums1[one] == nums2 [two])
            {
                res.push_back(nums1[one]);
                one++;
                two++;
            }else if(nums2[two] > nums1[one])
            {
                one++;
            }else{
                two++;
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