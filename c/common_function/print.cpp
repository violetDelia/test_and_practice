
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
void printnums(vector<int> a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        cout.width(5);
        std::cout << a[i] << ' ';
        if ((i + 1) % 10 == 0)
            std::cout << '\n';
    }
    return;
}