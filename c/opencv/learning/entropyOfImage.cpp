#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
/**
 * @brief 计算单通道图像的熵值
 * 
 * @param image 原始图像
 * @param target_i 计算的像素点值 -1计算整幅图的
 * @return double 
 */
double entropyOfGrayImage(Mat &image, int target_i = -1)
{
    //统计像素点
    map<int, double> count;
    for (int i = 0; i < image.rows; ++i)
    {
        for (int j = 0; j < image.cols; ++j)
            count[image.at<uchar>(i, j)]++;
    }
    int totalPixels = image.cols * image.rows;
    //返回单像素熵值
    if (target_i != -1)
    {
        count[target_i] = count[target_i] / totalPixels;
        return -count[target_i] * (log(count[target_i] / log(2.0)));
    }
    //计算像素点概率
    for (auto &e : count)
    {
        e.second = e.second / totalPixels;
    }
    //计算各像素点的熵
    for (auto &e : count)
    {
        e.second = -e.second * (log(e.second) / log(2.0));
    }
    //返回结果
    double result = 0;
    for (auto &e : count)
    {
        result += e.second;
    }
    return result;
}

/**
 * @brief 计算三通道图像的熵值
 * 
 * @param image 原始图像
 * @param target_i 计算的像素点值 -1计算整幅图的
 * @return vector<double> 
 */
vector<double> entropyOfBGRImage(Mat &image, int target_i = -1)
{
    //统计像素点
    vector<map<int, double>> count;
    for (int i = 0; i < image.rows; ++i)
    {
        for (int j = 0; j < image.cols; ++j)
        {
            for (int c = 0; c < 3; ++c)
            {
                count[c][image.at<Vec3b>(i, j)[c]]++;
            }
        }
    }
    int totalPixels = image.cols * image.rows;
    //返回单像素熵值
    if (target_i != -1)
    {
        vector<double> result;
        for (int i = 0; i < 3; ++i)
        {
            count[i][target_i] = count[i][target_i] / totalPixels;
            double targetEntropy = -count[i][target_i] * (log(count[i][target_i] / log(2.0)));
            result.push_back(targetEntropy);
        }
        return result;
    }
    //计算像素点概率
    for (auto &m : count)
    {
        for (auto &e : m)
        {
            e.second = e.second / totalPixels;
        }
    }
    //计算各像素点的熵
    for (auto &m : count)
    {
        for (auto &e : m)
        {
            e.second = -e.second * (log(e.second) / log(2.0));
        }
    }
    //返回结果
    vector<double> result;
    for (auto &m : count)
    {
        double cannelresult = 0;
        for (auto &e : m)
        {
            cannelresult += e.second;
        }
        result.push_back(cannelresult);
    }
    return result;
}

void probabilityDistribution(Mat &image, int len)
{
    //统计像素点
    map<int, double> count;
    for (int i = 0; i < image.rows; ++i)
    {
        for (int j = 0; j < image.cols; ++j)
            count[image.at<uchar>(i, j)]++;
    }
    int p = 0;
    int up = len;
    while (p <= UCHAR_MAX)
    {
        int sum = 0;
        for (int i = p; i < up; i++)
        {
            sum += count[i];
        }
        cout << p << "~" << up - 1 << "区间的像素点总数为： " << sum << endl;
        p += len;
        up += len;
        if (up > UCHAR_MAX)
            up = UCHAR_MAX + 1;
    }
}
