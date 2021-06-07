#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        int max = releaseTimes[0];
        int resp = 0;
        for (int i = 1; i < releaseTimes.size(); ++i)
        {
            int time = releaseTimes[i] - releaseTimes[i - 1];
            if (time > max)
            {
                max = time;
                resp = i;
            }
            else if (time == max)
            {
                char now = tolower(keysPressed[i]);
                char p = tolower(keysPressed[resp]);
                if (now > p)
                    resp = i;
            }
        }
        return keysPressed[resp];
    }
};

int main()
{

    std::system("pause");
    return 0;
}