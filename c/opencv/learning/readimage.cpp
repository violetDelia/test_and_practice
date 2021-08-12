#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    //定义窗口：窗口名，窗口模式
    namedWindow("test", WINDOW_FREERATIO);
    //读取图像：文件路径，读取模式
    Mat img = imread("C:/Users/17335/Desktop/test/c/opencv/lab/IMG_20200619_201012.jpg", IMREAD_GRAYSCALE);
    //查看图像：窗口名，展示的图片对象
    imshow("test", img);
    waitKey(0);
    return 0;
}