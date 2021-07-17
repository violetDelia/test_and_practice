#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class ParkingSystem
{
public:
    int big;
    int middle;
    int small;
    ParkingSystem(int big, int medium, int small)
    {
        this->big = big;
        this->middle = medium;
        this->small = small;
    }

    bool addCar(int carType)
    {
        switch (carType)
        {
        case 1:
            if (big == 0)
                return false;
            big--;
            break;
        case 2:
            if (middle == 0)
                return false;
            middle--;;
            break;
        case 3:
            if (small == 0)
                return false;
            small--;
        }
        return true;
    }
};
int main()
{
    std::system("pause");
    return 0;
}