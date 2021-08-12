#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
/**
 * @brief 中值过滤
 * 
 * @param input_image 输入图像
 * @param output_image 输出图像
 * @param size 卷积尺寸
 */
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