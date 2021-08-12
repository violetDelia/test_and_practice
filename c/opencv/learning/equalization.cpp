#include<opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc, char const *argv[])
{
    Mat init_image = imread("C:/Users/17335/Desktop/test/c/opencv/lab/IMG_20200619_201012.jpg",IMREAD_UNCHANGED);
    Mat gray_image;
    //转换色彩：原始图像，结果图像，转换模式，转换的通道数
    cvtColor(init_image,gray_image,COLOR_BGR2GRAY,1);
    Mat equalized_image;
    //均衡化图像：原始图像，结果图像
    equalizeHist(gray_image,equalized_image);
    namedWindow("gray",WINDOW_FREERATIO);
    imshow("gray",gray_image);
    namedWindow("equalized",WINDOW_FREERATIO);
    imshow("equalized",equalized_image);
    
    waitKey();
    return 0;
}
