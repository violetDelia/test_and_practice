#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m,
               vector<int> &nums2, int n)
    {
        int l = m + n;
        int onep = m, twop = n;
        while (l)
        {
            if (onep && twop)
            {
                if (nums1[onep - 1] >= nums2[twop - 1])
                {
                    nums1[l - 1] = nums1[onep - 1];
                    --onep;
                }
                else
                {
                    nums1[l - 1] = nums2[twop - 1];
                    --twop;
                }
            }
            else if (twop)
            {
                for (; twop > 0; --twop)
                {
                    nums1[twop - 1] = nums2[twop - 1];
                    return;
                }
            }
            else
            {
                return;
            }
            --l;
        }
        return;
    }
};

int main()
{

    std::system("pause");
    return 0;
}