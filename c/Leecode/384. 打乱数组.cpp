#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
private:
    vector<int> init;
    vector<int> initcopy;

public:
    Solution(vector<int> &nums)
    {
        this->init = nums;
        this->initcopy = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        init = initcopy;
        return init;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        //srand(time(0));
        for (int i = 0; i < init.size(); ++i)
        {
            swap(init[i], init[rand() % (init.size())]);
        }
        return init;
    }
};
int main()
{
    vector<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Solution *s = new Solution(c);
    s->reset();
    s->shuffle();
    std::system("pause");
    return 0;
}