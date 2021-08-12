#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
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
        for (int j = 0; j < image.cols; ++j)
            count[image.at<uchar>(i, j)]++;
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
    vector<map<int, double>> count(3);
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

/**
 * @brief 添加高斯噪点图
 * 
 * @param image 目标图像
 * @param mean_value 高斯分布的均值
 * @param standard_deviation 高斯分布的标准差
 */
Mat makeGaussionNoise(Mat &image, int mean_value, int standard_deviation)
{
    Mat noise = Mat::zeros(image.size(), image.type());
    RNG rng;
    rng.fill(noise, RNG::NORMAL, mean_value, standard_deviation);
    return noise;
}

/**
 * @brief 检查参数
 * 
 * @param input_image  输入图像
 * @param output_image  输出图像
 * @param kernel 卷积核
 * @return true 
 * @return false 
 */
bool simpleConvelution_check(Mat &input_image, Mat &output_image, vector<vector<int>> &kernel)
{
    if (input_image.size() != output_image.size())
    {
        cout << "图片大小不一致" << endl;
        return false;
    }
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
 */
void simpleConvelution(Mat &input_image, Mat &output_image, vector<vector<int>> &kernel)
{
    if (!simpleConvelution_check(input_image, output_image, kernel))
        return;
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
            weight += n;
    }
    if (weight == 0)
        weight = 1;
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
            output_image.at<uchar>(r, c) = sum / weight;
            head.second++;
        }
        head.first++;
        head.second = 0;
    }
    return;
}

/**
 * @brief 统计两幅图的像素差
 * 
 * @param first_image 被减数
 * @param second_image 减数
 * @param pad 忽略边缘点数
 */
void compareImage(Mat &first_image, Mat &second_image, int pad)
{
    if (first_image.size() != second_image.size())
    {
        cout << "图片尺寸不符" << endl
             << endl;
        return;
    }
    map<int, int> count;
    for (int i = pad; i < first_image.rows - pad; ++i)
    {
        for (int j = 5; j < first_image.cols - 5; ++j)
        {
            count[first_image.at<uchar>(i, j) - second_image.at<uchar>(i, j)]++;
        }
    }
    for (auto &m : count)
    {
        cout << "像素差： " << m.first << "    像素数目：" << m.second << endl;
    }
}

void weighted_mean_filtering(Mat &input_image, Mat &output_image, int size)
{
    vector<vector<int>> kernel(size, vector<int>(size, 1));
    simpleConvelution(input_image, output_image, kernel);
    return;
}

void filtering_median(Mat &input_image, Mat &output_image, int size)
{
    if (input_image.size() != output_image.size())
    {
        cout << "图片大小不一致" << endl;
        return;
    }
    if (size & 1 == 0)
    {
        cout << "size应为奇数" << endl;
        return;
    }
    int pad = size >> 1;
    int mid = (size * size) >> 1;
    pair<int, int> head = {0, 0};
    for (int r = pad; r < input_image.rows - pad; ++r)
    {
        for (int c = pad; c < input_image.cols - pad; ++c)
        {
            vector<uchar> count;
            for (int i = 0; i < size; ++i)
            {
                for (int j = 0; j < size; ++j)
                {
                    count.push_back(input_image.at<uchar>(head.first + i, head.second + j));
                }
            }
            sort(count.begin(), count.end());
            output_image.at<uchar>(r, c) = count[mid];
            head.second++;
        }
        head.first++;
        head.second = 0;
    }
}

void cacalateGrayImageHistogram_pr(Mat &image, int len)
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

int main(int argc, char const *argv[])
{
    Mat image_init = imread("C:/Users/17335/Desktop/test/c/opencv/lab/lab1.jpg", IMREAD_UNCHANGED);

    Mat image_gray;
    cvtColor(image_init, image_gray, COLOR_BGR2GRAY, 1);
    namedWindow("lab1.1_gray", WINDOW_AUTOSIZE);
    imshow("lab1.1_gray", image_gray);

    Mat image_gray_equalized;
    equalizeHist(image_gray, image_gray_equalized);
    namedWindow("lab1.1_equalized", WINDOW_AUTOSIZE);
    imshow("lab1.1_equalized", image_gray_equalized);

    cacalateGrayImageHistogram_pr(image_gray, 16);
    cout << endl;
    cacalateGrayImageHistogram_pr(image_gray_equalized, 16);
    cout << endl;

    double entropy_gray_before = entropyOfGrayImage(image_gray);
    cout << "均衡化前灰度图的熵：" << entropy_gray_before << endl
         << endl;

    double entropy_gray_after = entropyOfGrayImage(image_gray_equalized);
    cout << "均衡化后灰度图的熵：" << entropy_gray_after << endl
         << endl;

    namedWindow("lab1.3_init", WINDOW_AUTOSIZE);
    imshow("lab1.1_init", image_init);
    vector<double> entropy_init_before = entropyOfBGRImage(image_init);
    cout << "均衡化前彩色图的熵：" << endl
         << "B: " << entropy_init_before[0] << endl
         << "G: " << entropy_init_before[1] << endl
         << "R: " << entropy_init_before[2] << endl
         << endl;

    vector<Mat> image_init_equalized;
    split(image_init, image_init_equalized);
    for (auto &mat : image_init_equalized)
        equalizeHist(mat, mat);
    namedWindow("lab1.3_equalized_B", WINDOW_AUTOSIZE);
    imshow("lab1.3_equalized_B", image_init_equalized[0]);
    namedWindow("lab1.3_equalized_G", WINDOW_AUTOSIZE);
    imshow("lab1.3_equalized_G", image_init_equalized[1]);
    namedWindow("lab1.3_equalized_R", WINDOW_AUTOSIZE);
    imshow("lab1.3_equalized_R", image_init_equalized[2]);
    cout << "均衡化后彩色图的熵：" << endl
         << "B: " << entropyOfGrayImage(image_init_equalized[0]) << endl
         << "G: " << entropyOfGrayImage(image_init_equalized[1]) << endl
         << "R: " << entropyOfGrayImage(image_init_equalized[2]) << endl
         << endl;

    Mat image_gray_noised = image_gray + makeGaussionNoise(image_gray, 20, 20);
    imshow("lab1.4_noised", image_gray_noised);

    Mat image_gray_gaussion_three = Mat::zeros(image_gray_noised.size(), image_gray_noised.type());
    vector<vector<int>> gaussion_operator_three = {{1, 2, 1},
                                                   {2, 4, 2},
                                                   {1, 2, 1}};
    simpleConvelution(image_gray_noised, image_gray_gaussion_three, gaussion_operator_three);
    imshow("lab1.4_gaussion_3*3", image_gray_gaussion_three);

    Mat image_gray_gaussion_five = Mat::zeros(image_gray_noised.size(), image_gray_noised.type());
    vector<vector<int>> gaussion_operator_five = {{01, 04, 07, 04, 01},
                                                  {04, 16, 26, 16, 04},
                                                  {07, 26, 41, 26, 07},
                                                  {04, 16, 26, 16, 04},
                                                  {01, 04, 07, 04, 01}};
    simpleConvelution(image_gray_noised, image_gray_gaussion_five, gaussion_operator_five);
    imshow("lab1.4_gaussion_5*5", image_gray_gaussion_five);

    Mat image_gray_gaussion_seven;
    GaussianBlur(image_gray_noised, image_gray_gaussion_seven, Size(7, 7), 0, 0);
    imshow("lab1.4_gaussion_7*7", image_gray_gaussion_seven);

    Mat image_gray_mean_three = Mat::zeros(image_gray_noised.size(), image_gray_noised.type());

    weighted_mean_filtering(image_gray_noised, image_gray_mean_three, 3);
    imshow("lab1.4_mean_3*3", image_gray_mean_three);

    Mat image_gray_mean_five = Mat::zeros(image_gray_noised.size(), image_gray_noised.type());
    weighted_mean_filtering(image_gray_noised, image_gray_mean_five, 5);
    imshow("lab1.4_mean_5*5", image_gray_mean_five);

    Mat image_gray_mean_seven = Mat::zeros(image_gray_noised.size(), image_gray_noised.type());
    weighted_mean_filtering(image_gray_noised, image_gray_mean_seven, 7);
    imshow("lab1.4_mean_7*7", image_gray_mean_seven);

    Mat image_gray_median_three = Mat::zeros(image_gray_noised.size(), image_gray_noised.type());
    filtering_median(image_gray_noised, image_gray_median_three, 3);
    imshow("lab1.4_median_3*3", image_gray_median_three);

    Mat image_gray_median_five = Mat::zeros(image_gray_noised.size(), image_gray_noised.type());
    filtering_median(image_gray_noised, image_gray_median_five, 5);
    imshow("lab1.4_median_5*5", image_gray_median_five);

    Mat image_gray_median_seven = Mat::zeros(image_gray_noised.size(), image_gray_noised.type());
    filtering_median(image_gray_noised, image_gray_median_seven, 7);
    imshow("lab1.4_median_7*7", image_gray_median_seven);

    waitKey();
    return 0;
}
