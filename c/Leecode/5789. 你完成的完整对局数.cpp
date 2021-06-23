#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int numberOfRounds(string startTime, string finishTime)
    {
        int start = 0;
        start += startTime[0] - '0';
        start *= 10;
        start += startTime[1] - '0';
        int end = 0;
        end += finishTime[0] - '0';
        end *= 10;
        end += finishTime[1] - '0';
        int startm = 0;
        startm += startTime[3] - '0';
        startm *= 10;
        startm += startTime[4] - '0';
        int endm = 0;
        endm += finishTime[3] - '0';
        endm *= 10;
        endm += finishTime[4] - '0';
        int space = 0;
        if (start < end)
            space = end - start;
        else if(start == end  && startm < endm)
            space = end - start;
        else
            space = 24 - start + end;
        int s;
        if (startm == 0)
            s = 0;
        else if (startm <= 15)
            s = 1;
        else if (startm <= 30)
            s = 2;
        else if (startm <= 45)
            s = 3;
        else
            s = 4;
        int e = endm / 15;
        if (endm < 15)
            e = 0;
        else if (endm < 30)
            e = 1;
        else if (endm < 45)
            e = 2;
        else
            e = 3;
        return space * 4 - s + e;
        
    }
};
int main()
{
    Solution a;
    a.numberOfRounds("23:46", "00:01");
    std::system("pause");
    return 0;
}