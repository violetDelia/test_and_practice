#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = matrix.size() - 1;
        for (int x = 0; x < (l + 1) >> 1; ++x)
            for (int y = 0; y <= l >> 1; ++y)
            {
                int temp = matrix[x][y];
                matrix[x][y] = matrix[l - y][x];
                matrix[l - y][x] = matrix[l - x][l - y];
                matrix[l - x][l - y] = matrix[y][l - x];
                matrix[y][l - x] = temp;
            }
        return;
    }
};


int main()
{
    
    std::system("pause");
    return 0;
}