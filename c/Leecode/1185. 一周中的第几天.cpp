#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string dayOfTheWeek(int day, int month, int year)
    {
        vector<string> Week = {"Monday", "Tuesday", "Wednesday",
                               "Thursday", "Friday", "Saturday", "Sunday"};
        int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31,
                               31, 30, 31, 30, 31};
        int count = 365 * (year - 1971) + day - 1;
        for (int i = 1; i < month; ++i)
            count += daysOfMonth[i];
        for (int i = 1971; i <= year; i++)
        {
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
            {
                if (i < year || (i == year && month > 2))
                    count++;
            }
        }
        return Week[((4+count)%7)];
    }
};

int main()
{

    std::system("pause");
    return 0;
}
