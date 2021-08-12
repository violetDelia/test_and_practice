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
class TripleInOne
{
    int *numarray;
    int *position[3];
    int *bottom[3];
    int *top[3];

public:
    ~TripleInOne(){
        delete []numarray;
    }
    TripleInOne(int stackSize)
    {
        numarray = new int[3 * stackSize];
        for (int i = 0; i < 3; ++i)
        {
            position[i] = numarray + i * stackSize;
            bottom[i] = numarray + i * stackSize;
            top[i] = bottom[i] + stackSize;
        }
    }

    void push(int stackNum, int value)
    {
        if (position[stackNum] == top[stackNum])
            return;
        *position[stackNum] = value;
        position[stackNum]++;
    }

    int pop(int stackNum)
    {
        if (isEmpty(stackNum))
            return -1;
        position[stackNum]--;
        return *position[stackNum];
    }

    int peek(int stackNum)
    {
        if (isEmpty(stackNum))
            return -1;
        return *(position[stackNum]-1);
    }

    bool isEmpty(int stackNum)
    {
        return position[stackNum] == bottom[stackNum];
    }
};

int main()
{
    TripleInOne A = TripleInOne(18);
    A.push(0, 44);
    A.push(1,40);
    A.pop(0);
    A.push(1,54);
    A.push(0,42);
    A.pop(0);
    A.pop(0);
    A.peek(0);
    std::system("pause");
    return 0;
}