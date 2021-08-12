#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include <math.h>
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
void EdgeDetection_Sobel(Mat &input_image, Mat &output_image, vector<vector<int>> &kernel)
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
            Gx /= weight;
            //y的梯度
            double Gy = 0;
            for (int i = 0; i < kernel.size(); ++i)
            {
                for (int j = 0; j < kernel.size(); ++j)
                {
                    Gy += input_image.at<uchar>(head.first + i, head.second + j) * kernel[j][i];
                }
            }
            Gy /= weight;
            if (r == 100)
                cout << (atan2(Gy, Gx) + acos(-1)) * UCHAR_MAX / 2 / acos(-1) << endl;
            output_image.at<uchar>(r, c) = (atan2(Gy, Gx) + acos(-1)) * UCHAR_MAX / 2 / acos(-1);
            head.second++;
        }
        head.first++;
        head.second = 0;
    }
}
int main()
{
    Mat image_lina_init = imread("C:/Users/17335/Desktop/test/c/opencv/lab/lab2.1.png", IMREAD_UNCHANGED);
    Mat image_lina;
    cvtColor(image_lina_init, image_lina, COLOR_BGR2GRAY, 1);
    imshow("lina", image_lina);
    GaussianBlur(image_lina, image_lina, Size(3, 3), 10, 0, BORDER_DEFAULT);
    Mat image_sobel = Mat::zeros(image_lina.size(), image_lina.type());
    /*vector<vector<int>> kernel_sobel_x = {{2, 01, 00},
                                          {1, 00, -1},
                                          {0, -1, -2}};*/
    vector<vector<int>> kernel_sobel_x = {{-1, -2, -3, 0, 3, 2, 1},
                                          {-2, -3, -4, 0, 4, 3, 2},
                                          {-3, -5, -7, 0, 7, 5, 3},
                                          {-5, -7, -10, 0, 10, 7, 5},
                                          {-3, -5, -7, 0, 7, 5, 3},
                                          {-2, -3, -4, 0, 4, 3, 2},
                                          {-1, -2, -3, 0, 3, 2, 1}};
    EdgeDetection_Sobel(image_lina, image_sobel, kernel_sobel_x);
    Mat image_sobel_binary;
    threshold(image_sobel, image_sobel_binary, 20, 255, THRESH_BINARY);
    imshow("image_sobel", image_sobel);
    imshow("image_sobel_binary", image_sobel_binary);

    /*Mat image_sobel_x;
    simpleConvelution(image_lina, image_sobel_x, kernel_sobel_x);
    Mat image_sobel_x_binary;
    threshold(image_sobel_x, image_sobel_x_binary, 20, 255, THRESH_BINARY);
    imshow("image_sobel_x", image_sobel_x);
    imshow("image_sobel_x_binary", image_sobel_x_binary);

    Mat image_sobel_y;
    vector<vector<int>> kernel_sobel_y = {{01, 02, 01},
                                          {00, 00, 00},
                                          {-1, -2, -1}};
    simpleConvelution(image_lina, image_sobel_y, kernel_sobel_y);
    Mat image_sobel_y_binary;
    threshold(image_sobel_y, image_sobel_y_binary, 20, 255, THRESH_BINARY);
    imshow("image_sobel_y", image_sobel_y);
    imshow("image_sobel_y_binary", image_sobel_y_binary);

    Mat image_sobel_or;
    EdgeDetection_Sobel_orientation(image_lina, image_sobel_or, kernel_sobel_x);
    imshow("image_sobel_or", image_sobel_or);

    Mat image_prewitt;
    vector<vector<int>> kernel_prewitt = {{1, 0, -1},
                                          {1, 0, -1},
                                          {1, 0, -1}};
    EdgeDetection_Sobel(image_lina, image_prewitt, kernel_prewitt);
    imshow("image_prewitt", image_prewitt);
    Mat image_prewitt_binary;
    threshold(image_prewitt, image_prewitt_binary, 20, 255, THRESH_BINARY);
    imshow("image_prewitt_binary", image_prewitt_binary);*/
    waitKey();
    return 0;
}