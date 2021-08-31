#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/**
 * @brief 检查参数
 * 
 * @param input_image  输入图像
 * @param output_image  输出图像
 * @param kernel 卷积核
 * @return true 
 * @return false 
 */
bool simpleConvelution_check(Mat &input_image, Mat &output_image)
{
    if (input_image.size() != output_image.size())
        return false;
    if (input_image.type() != output_image.type())
        return false;
    return true;
}

bool simpleConvelution_check(vector<vector<int>> &kernel)
{
    if (kernel.size() == 0)
    {
        cout << "无效的kernel" << endl;
        return false;
    }
    int l = kernel[0].size();
    for (auto &r : kernel)
    {
        if (r.size() != l)
        {
            cout << "无效的kernel" << endl;
            return false;
        }
    }
    return true;
}
/**
 * @brief sobel边缘检测
 * 
 * @param input_image 输入
 * @param output_image 输出
 * @param kernel 算子
 */
void edgeDetection_Sobel(Mat &input_image, Mat &output_image, vector<vector<int>> &kernel)
{
    //检查
    if (!simpleConvelution_check(kernel))
        return;
    if (!simpleConvelution_check(input_image, output_image))
        output_image = Mat::zeros(input_image.size(), input_image.type());
    int pad = kernel.size() >> 1;
    int weight = 0;
    for (auto &r : kernel)
    {
        for (auto &n : r)
            weight += abs(n);
    }
    pair<int, int> head = {0, 0};
    for (int r = pad; r < input_image.rows - pad; ++r)
    {
        for (int c = pad; c < input_image.cols - pad; ++c)
        {
            //x的梯度
            int Gx = 0;
            for (int i = 0; i < kernel.size(); ++i)
            {
                for (int j = 0; j < kernel.size(); ++j)
                {
                    Gx += input_image.at<uchar>(head.first + i, head.second + j) * kernel[i][j];
                }
            }
            Gx /= weight;
            //y的梯度
            int Gy = 0;
            for (int i = 0; i < kernel.size(); ++i)
            {
                for (int j = 0; j < kernel.size(); ++j)
                {
                    Gy += input_image.at<uchar>(head.first + i, head.second + j) * kernel[j][i];
                }
            }
            Gy /= weight;
            output_image.at<uchar>(r, c) = sqrt(Gx * Gx + Gy * Gy);
            head.second++;
        }
        head.first++;
        head.second = 0;
    }
}
/**
 * @brief 方向图
 * 
 * @param input_image 
 * @param output_image 
 * @param kernel 
 */
void EdgeDetection_Sobel_orientation(Mat &input_image, Mat &output_image, vector<vector<int>> &kernel)
{
    //检查
    if (!simpleConvelution_check(kernel))
        return;
    if (!simpleConvelution_check(input_image, output_image))
        output_image = Mat::zeros(input_image.size(), input_image.type());
    int pad = kernel.size() >> 1;
    int weight = 0;
    for (auto &r : kernel)
    {
        for (auto &n : r)
            weight += abs(n);
    }
    pair<int, int> head = {0, 0};
    for (int r = pad; r < input_image.rows - pad; ++r)
    {
        for (int c = pad; c < input_image.cols - pad; ++c)
        {
            //x的梯度
            double Gx = 0;
            for (int i = 0; i < kernel.size(); ++i)
            {
                for (int j = 0; j < kernel.size(); ++j)
                {
                    Gx += input_image.at<uchar>(head.first + i, head.second + j) * kernel[i][j];
                }
            }
            //y的梯度
            double Gy = 0;
            for (int i = 0; i < kernel.size(); ++i)
            {
                for (int j = 0; j < kernel.size(); ++j)
                {
                    Gy += input_image.at<uchar>(head.first + i, head.second + j) * kernel[j][i];
                }
            }
            output_image.at<uchar>(r, c) = (atan2(Gy, Gx) + acos(-1)) * UCHAR_MAX / 2 / acos(-1);
            head.second++;
        }
        head.first++;
        head.second = 0;
    }
}