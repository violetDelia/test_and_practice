#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int find(vector<int> nums1, int nums1_left, int nums1_right,
             vector<int> nums2, int nums2_left, int nums2_right, int k)
    {
        if (nums1_left > nums1_right)
            return nums2[nums2_left + k - 1];
        if (nums2_left > nums2_right)
            return nums1[nums1_left + k - 1];
        if (k == 1)
            return nums1[nums1_left] < nums2[nums2_left]
                       ? nums1[nums1_left]
                       : nums2[nums2_left];
        int space1 = (nums1_right - nums1_left - 1) / 2;
        int space2 = (nums2_right - nums2_left - 1) / 2;
        int space3 = k / 2 - 1;
        int space;
        space = space1 < space2 ? space1 : space2;
        space = space < space3 ? space : space3;
        int mid1 = nums1_left + space;
        int mid2 = nums2_left + space;
        if (nums1[mid1] <= nums2[mid2])
            return find(nums1, mid1 + 1, nums1_right, nums2,
                        nums2_left, nums2_right, k - (mid1 - nums1_left) - 1);
        else
            return find(nums1, nums1_left, nums1_right,
                        nums2, mid2 + 1, nums2_right, k - (mid2 - nums2_left) - 1);
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int l = nums1.size() + nums2.size();
        double n1 = find(nums1, 0, nums1.size() - 1,
                      nums2, 0, nums2.size() - 1, (l + 1) / 2);
        double n2 = find(nums1, 0, nums1.size() - 1,
                      nums2, 0, nums2.size() - 1, l / 2 + 1);
        return (n1 + n2) / 2;
    }
};
int main()
{
    vector<int> n1 = {1,2};
    vector<int> n2 = {3,4};
    Solution a;
    a.findMedianSortedArrays(n1, n2);
    std::system("pause");
    return 0;
}