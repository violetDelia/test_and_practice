#include <iostream>
#include <opencv2/opencv.hpp>
#include <stack>
using namespace std;
using namespace cv;
void dilate(Mat &input_image, Mat &output_image, vector<vector<bool>> array)
{
    if (array.size() == 0 || array[0].size() == 0)
        return;
    output_image = input_image.clone();
    int kr = array.size();
    int kc = array[0].size();
    int padc = (kc - 1) >> 1;
    int padr = (kr - 1) >> 1;
    for (int r = 0; r < input_image.rows; ++r)
    {
        for (int c = 0; c < input_image.cols; ++c)
        {
            if (input_image.at<uchar>(r, c) == 0)
                continue;
            int hx = r - padr;
            int hy = c - padc;
            for (int i = 0; i < kr; ++i)
            {
                for (int j = 0; j < kc; ++j)
                {
                    if (!array[i][j])
                        continue;
                    int x = hx + i;
                    int y = hy + j;
                    if (x < 0 || x >= input_image.rows || y < 0 || y >= input_image.cols)
                        continue;
                    if (input_image.at<uchar>(x, y) != 0)
                        continue;
                    output_image.at<uchar>(x, y) = 255;
                }
            }
        }
    }
}

void erode(Mat &input_image, Mat &output_image, vector<vector<bool>> &array)
{
    if (array.size() == 0 || array[0].size() == 0)
        return;
    output_image = input_image.clone();
    int kr = array.size();
    int kc = array[0].size();
    int padc = (kc - 1) >> 1;
    int padr = (kr - 1) >> 1;
    for (int r = 0; r < input_image.rows; ++r)
    {
    nextr:
        for (int c = 0; c < input_image.cols; ++c)
        {
        nextc:
            if (input_image.at<uchar>(r, c) == 0)
                continue;
            int hx = r - padr;
            int hy = c - padc;
            for (int i = 0; i < kr; ++i)
            {
                for (int j = 0; j < kc; ++j)
                {
                    if (!array[i][j])
                        continue;
                    int x = hx + i;
                    int y = hy + j;
                    if (x < 0 || x >= input_image.rows || y < 0 || y >= input_image.cols)
                        continue;
                    if (input_image.at<uchar>(x, y) != 0)
                        continue;
                    output_image.at<uchar>(r, c) = 0;
                    ++c;
                    if (c < input_image.cols)
                        goto nextc;
                    ++r;
                    if (r < input_image.rows)
                        goto nextr;
                    return;
                }
            }
        }
    }
}
void erode(Mat &input_image, Mat &output_image, int len)
{
    int R = len * len;
    vector<vector<bool>> circle(len * 2 + 1, vector<bool>(len * 2 + 1, 0));
    for (int i = 0; i < circle.size(); ++i)
    {
        for (int j = 0; j < circle[i].size(); ++j)
        {
            int x = abs(i - len);
            int y = abs(j - len);
            if (x * x + y * y <= R)
                circle[i][j] = 1;
        }
    }
    erode(input_image, output_image, circle);
}
void dilate(Mat &input_image, Mat &output_image, int len)
{
    int R = len * len;
    vector<vector<bool>> circle(len * 2 + 1, vector<bool>(len * 2 + 1, 0));
    for (int i = 0; i < circle.size(); ++i)
    {
        for (int j = 0; j < circle[i].size(); ++j)
        {
            int x = abs(i - len);
            int y = abs(j - len);
            if (x * x + y * y <= R)
                circle[i][j] = 1;
        }
    }
    dilate(input_image, output_image, circle);
}
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
main()
{
    Mat image_circle = imread("C:/Users/17335/Desktop/test/c/opencv/lab/lab4.1.jpg", IMREAD_UNCHANGED);
    Mat image_1 = imread("C:/Users/17335/Desktop/test/c/opencv/lab/lab4.2.bmp", IMREAD_UNCHANGED);
    Mat image_2 = imread("C:/Users/17335/Desktop/test/c/opencv/lab/lab4.3.bmp", IMREAD_UNCHANGED);
    cvtColor(image_circle, image_circle, COLOR_BGR2GRAY, 1);
    threshold(image_circle, image_circle, 50, 255, THRESH_BINARY);
    Mat lab5;
    erode(image_circle, lab5, 15);
    imshow("lab5", lab5);
    cout << count(lab5) << endl;
    Mat lab6;
    dilate(image_1, lab6, 1);
    imshow("lab6", lab6 - image_1);
    vector<vector<bool>> erode_array = {{1, 1, 1},
                                        {1, 1, 1},
                                        {1, 1, 1}};
    vector<vector<bool>> dilate_array = {{1, 1, 1, 1, 1, 1, 1},
                                         {1, 1, 1, 1, 1, 1, 1},
                                         {1, 1, 1, 1, 1, 1, 1},
                                         {1, 1, 1, 1, 1, 1, 1},
                                         {1, 1, 1, 1, 1, 1, 1},
                                         {1, 1, 1, 1, 1, 1, 1},
                                         {1, 1, 1, 1, 1, 1, 1}};
    vector<vector<bool>> final_array = {{1, 1, 1, 1, 1},
                                        {1, 1, 1, 1, 1},
                                        {1, 1, 1, 1, 1},
                                        {1, 1, 1, 1, 1},
                                        {1, 1, 1, 1, 1}};
    Mat lab7_temp1;
    erode(image_2, lab7_temp1, erode_array);
    imshow("lab7_temp1", lab7_temp1);
    Mat lab7_temp2;
    dilate(lab7_temp1, lab7_temp2, dilate_array);
    imshow("lab7_temp2", lab7_temp2);
    Mat lab7;
    erode(lab7_temp2, lab7, final_array);
    imshow("lab7", lab7);
    waitKey();
    return 0;
}