#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        char last = '0';
        int sum = 0;
        for (char op : s)
        {
            switch (op)
            {
            case 'I':
                sum += 1;
                break;
            case 'V':
                if (last == 'I')
                    sum += 3;
                else
                    sum += 5;
                break;
            case 'X':
                if (last == 'I')
                    sum += 8;
                else
                    sum += 10;
                break;
            case 'L':
                if (last == 'X')
                    sum += 30;
                else
                    sum += 50;
                break;
            case 'C':
                if (last == 'X')
                    sum += 80;
                else
                    sum += 100;
                break;
            case 'D':
                if (last == 'C')
                    sum += 300;
                else
                    sum += 500;
                break;
            case 'M':
                if (last == 'C')
                    sum += 800;
                else
                    sum += 1000;
                break;
            default:
                break;
            }
            last = op;
        }
        return sum;
    }
};

int main()
{

    std::system("pause");
    return 0;
}