#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        int l = encoded.size();
        vector<int> res(l + 1);
        res[0] = first;
        for (int i = 0; i < l; ++i)
            res[i + 1] = encoded[i] ^ res[i];
        return res;
    }
};

int main()
{

    std::system("pause");
    return 0;
}