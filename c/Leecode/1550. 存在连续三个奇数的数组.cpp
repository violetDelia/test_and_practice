#include <iostream>
#include <vector>
using namespace std;
bool threeConsecutiveOdds(vector<int> &arr)
{

    int count = 0;
    for (int i = 0; i < arr.size()-(2-count); ++i)
    {
        if (arr[i] % 2)
        {
            ++count;
            if (count == 3)
                return true;
        }
        else
            count = 0;
    }
    return false;
}

int main()
{

    std::system("pause");
    return 0;
}