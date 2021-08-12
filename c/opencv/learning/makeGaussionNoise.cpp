#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
Mat makeGaussionNoise(Mat &image, int mean_value,int standard_deviation)
{
    //生成与原图像相当的0值图像
    Mat noise = Mat::zeros(image.size(),image.type());
    //生成随机数
    RNG rng;
    //用随机数填满0值图
    rng.fill(noise,RNG::NORMAL,mean_value,standard_deviation);
    return noise;
}