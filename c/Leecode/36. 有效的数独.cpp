#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int row[9][10] = {0};
        int col[9][10] = {0};
        int count[9][10] = {0};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {

                if (board[i][j] == '.')
                    continue;
                int n = board[i][j] - '0';
                if (row[i][n])
                    return false;
                if (col[j][n])
                    return false;
                if (count[j / 3 + (i / 3) * 3][n])
                    return false;

                row[i][n] = 1;
                col[j][n] = 1;
                count[j / 3 + (i / 3) * 3][n] = 1;
            }
        }
        return true;
    }
};
int main()
{
    vector<vector<char>> a = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                              {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                              {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                              {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                              {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                              {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution b;
    b.isValidSudoku(a);
    std::system("pause");
    return 0;
}