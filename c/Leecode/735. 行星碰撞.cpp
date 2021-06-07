#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool willboom(int i, vector<int> asteroids)
    {
        if (i < 0 || asteroids.size() - 1 <= i)
            return false;
        if (asteroids[i] >= 0 && asteroids[i + 1] <= 0)
            return true;
        if (asteroids[i] == 0 && asteroids[i + 1] < 0)
            return true;
        return false;
    }

    void afterboom(int &i, vector<int> &asteroids)
    {
        if (i < 0 || asteroids.size() - 1 <= i)
            return;
        if (abs(asteroids[i]) > abs(asteroids[i + 1]))
        {
            asteroids.erase(asteroids.begin() + i + 1);
            --i;
        }
        else if (abs(asteroids[i]) < abs(asteroids[i + 1]))
        {
            asteroids.erase(asteroids.begin() + i);
            if (i)
                --i;
            --i;
        }
        else
        {
            asteroids.erase(asteroids.begin() + i + 1);
            asteroids.erase(asteroids.begin() + i);
            if (i)
                --i;
            --i;
        }
        return;
    }

    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        for (int i = 0; i < asteroids.size(); ++i)
        {
            if (willboom(i, asteroids))
                afterboom(i, asteroids);
        }
        return asteroids;
    }
};

int main()
{
    vector<int> asteroids = {-2,2,-1,-2};
    Solution a;
    a.asteroidCollision(asteroids);

    std::system("pause");
    return 0;
}