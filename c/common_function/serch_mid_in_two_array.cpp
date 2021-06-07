#include <iostream>
#include <vector>
using namespace std;
int findKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)//I j 寻找的起始位置，k 是中位数的位置
{
    if (i >= nums1.size())
        return nums2[j + k - 1];
    if (j >= nums2.size())
        return nums1[i + k - 1];
    if (k == 1 && nums1[i] >= nums2[j])
        return nums2[j];
    else
        return nums2[i];
    int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
    int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
    if (midVal1 < midVal2)
        return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
    else
        return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
}

