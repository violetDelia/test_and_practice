#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

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
 * @brief 一维2D卷积操作
 * 
 * @param input_image 输入图像
 * @param output_image 输出输出 
 * @param kernel 卷积核
 * @param thresholdValue >= 阈值
 */
void simpleConvelution(Mat &input_image, Mat &output_image, vector<vector<int>> &kernel, int thresholdValue = 0)
{
    if (!simpleConvelution_check(kernel))
        return;
    if (!simpleConvelution_check(input_image, output_image))
        output_image = Mat::zeros(input_image.size(), input_image.type());
    //计算边缘
    int kr = kernel.size();
    int kc = kernel[0].size();
    int padc = (kc - 1) >> 1;
    int padr = (kr - 1) >> 1;
    //检查权重
    int weight = 0;
    for (auto &r : kernel)
    {
        for (auto &n : r)
            weight += abs(n);
    }
    //卷积操作
    pair<int, int> head = {0, 0};
    for (int r = padr; r < input_image.rows - padr; ++r)
    {
        for (int c = padc; c < input_image.cols - padc; ++c)
        {
            int sum = weight >> 1;
            for (int i = 0; i < kernel.size(); ++i)
            {
                for (int j = 0; j < kernel[i].size(); ++j)
                {
                    sum += input_image.at<uchar>(head.first + i, head.second + j) * kernel[i][j];
                }
            }
            output_image.at<uchar>(r, c) = (sum / weight) >= thresholdValue ? sum / weight : 0;
            head.second++;
        }
        head.first++;
        head.second = 0;
    }
}

/**
 * @brief 均值滤波
 * 
 * @param input_image 输入图像  
 * @param output_image 输出图像
 * @param size 卷积核尺寸
 */
void filtering_weighted_mean(Mat &input_image, Mat &output_image, int size)
{
    vector<vector<int>> kernel(size, vector<int>(size, 0));
    simpleConvelution(input_image, output_image, kernel);
    return;
}
