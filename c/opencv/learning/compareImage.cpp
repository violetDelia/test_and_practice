#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
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