#include <algorithm>
#include <iostream>
#include <map>
#include <opencv2/opencv.hpp>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
using namespace cv;
/**
 * @brief 连通分量
 * 
 * @param input 
 * @return int 
 */
int count(Mat input)
{
    int out = 0;
    for (int x = 0; x < input.rows; ++x)
    {
        for (int y = 0; y < input.cols; ++y)
        {
            if (input.at<uchar>(x, y) == 0)
                continue;
            ++out;
            stack<pair<int, int>> cell;
            cell.push({x, y});
            input.at<uchar>(x, y) = 0;
            while (!cell.empty())
            {
                pair<int, int> cellnode = cell.top();
                cell.pop();
                if (cellnode.first + 1 >= 0 && input.at<uchar>(cellnode.first + 1, cellnode.second) != 0)
                {
                    cell.push({cellnode.first + 1, cellnode.second});
                    input.at<uchar>(cellnode.first + 1, cellnode.second) = 0;
                }
                if (cellnode.first - 1 < input.rows && input.at<uchar>(cellnode.first - 1, cellnode.second) != 0)
                {
                    cell.push({cellnode.first - 1, cellnode.second});
                    input.at<uchar>(cellnode.first - 1, cellnode.second) = 0;
                }
                if (cellnode.second + 1 >= 0 && input.at<uchar>(cellnode.first, cellnode.second + 1) != 0)
                {
                    cell.push({cellnode.first, cellnode.second + 1});
                    input.at<uchar>(cellnode.first, cellnode.second + 1) = 0;
                }
                if (cellnode.second - 1 < input.cols && input.at<uchar>(cellnode.first, cellnode.second - 1) != 0)
                {
                    cell.push({cellnode.first, cellnode.second - 1});
                    input.at<uchar>(cellnode.first, cellnode.second - 1) = 0;
                }
            }
        }
    }
    return out;
}