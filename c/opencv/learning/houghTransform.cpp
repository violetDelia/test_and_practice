#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
/**
 * @brief 霍夫变换检测圆
 * 
 * @param input_image 检测的图像
 * @param statr_R 圆半径最小值
 * @param end_R 圆半径最大值
 * @param threshold_base 筛选基数
 * @param R_step 半径变化基数
 * @return vector<array<float, 4>> 储存圆的数组｛半径，x坐标，y坐标，计算出的点数｝
 */
vector<array<float, 4>> Hough_check_circle(Mat &input_image, float statr_R, float end_R, float threshold_base = 2.5, float R_step = 1)
{
    vector<array<float, 4>> out;
    int r_grade = (end_R - statr_R) / R_step;
    if (r_grade < 1)
        return out;
    int r = input_image.rows;
    int c = input_image.cols;
    //保存cos，sin值
    array<float, 360> vcos;
    array<float, 360> vsin;
    for (int tangle = 0; tangle < 360; ++tangle)
    {
        float t = tangle * CV_PI / 180;
        vcos[tangle] = cos(t);
        vsin[tangle] = sin(t);
    }
    vector<vector<vector<int>>> Hough_Space(r, vector<vector<int>>(c, vector<int>(end_R - statr_R)));
    float R = end_R;
    for (int r_g = 0; r_g < r_grade; ++r_g)
    {
        //计算此半径值的霍夫空间
        for (int a = 0; a < r; ++a)
        {
            for (int b = 0; b < c; ++b)
            {
                if (input_image.at<uchar>(a, b) != 0)
                {
                    for (int tangle = 0; tangle < 360; tangle++)
                    {
                        int x = cvRound(a - R * vcos[tangle]);
                        int y = cvRound(b - R * vsin[tangle]);
                        if (x < r && x > 0 && y < c && y > 0)
                            Hough_Space[x][y][r_g]++;
                    }
                }
            }
        }
        //筛选符合条件的圆
        int maxthreshold = R * threshold_base;
        for (int a = 0; a < r; ++a)
        {
            for (int b = 155; b < c; ++b)
            {
                if (Hough_Space[a][b][r_g] > maxthreshold)
                {
                    array<float, 4> newcircle;
                    newcircle[0] = float(R);
                    newcircle[1] = float(a);
                    newcircle[2] = float(b);
                    newcircle[3] = float(Hough_Space[a][b][r_g]);
                    out.push_back(newcircle);
                }
            }
        }
        R -= R_step;
    }
    return out;
}
/**
 * @brief 霍夫检测线
 * 
 * @param input_image 输入图像
 * @param threshold 阈值
 * @return vector<array<int, 3>> 储存线的数组｛极半径，角度，计数｝
 */
vector<array<int, 3>> Hough_check_lines(Mat &input_image, int threshold)
{
    vector<array<int, 3>> out;
    int r = input_image.rows;
    int c = input_image.cols;
    //储存cos，sin值
    array<float, 180> vcos;
    array<float, 180> vsin;
    for (int tangle = 0; tangle < 180; ++tangle)
    {
        float t = tangle * CV_PI / 180;
        vcos[tangle] = cos(t);
        vsin[tangle] = sin(t);
    }
    int R = cvRound(sqrt(c * c + r * r));
    vector<vector<int>> Hough_space(R, vector<int>(180, 0));
    //计算
    for (int x = 0; x < r; ++x)
    {
        for (int y = 0; y < c; ++y)
        {
            if (input_image.at<uchar>(x, y) != 0)
            {
                for (int tangle = 0; tangle < 180; ++tangle)
                {
                    int r = cvRound(x * vcos[tangle] + y * vsin[tangle]);
                    if (r > 0 && r < R)
                    {
                        Hough_space[r][tangle]++;
                    }
                }
            }
        }
    }
    //筛选
    for (int r = 0; r < R; ++r)
    {
        for (int t = 0; t < 180; ++t)
        {
            if (Hough_space[r][t] > threshold)
            {
                array<int, 3> newlne = {r, t, Hough_space[r][t]};
                out.push_back(newlne);
            }
        }
    }
    return out;
}
/**
 * @brief 霍夫变换检测椭圆
 * 
 * @param input_image 输入图像
 * @param threshold_base   筛选基数
 * @return vector<array<int, 6>>  储存椭圆的数组｛x，y，a，b，角度，计数｝
 */
vector<array<int, 6>> Hough_check_ellipe(Mat &input_image, float threshold_base = 1.25)
{
    vector<array<int, 6>> out;
    int r = input_image.rows;
    int c = input_image.cols;
    int max = sqrt(r * r + c * c);
    //储存cos，sin值
    vector<array<float, 180>> vcos(max);
    vector<array<float, 180>> vsin(max);
    for (int tangle = 0; tangle < 180; ++tangle)
    {
        float t = tangle * CV_PI / 180;
        float costem = cos(t);
        float sintem = sin(t);
        for (int i = 0; i < max; ++i)
        {
            vcos[i][tangle] = i * costem;
            vsin[i][tangle] = i * sintem;
        }
    }
    //计算
    vector<vector<vector<vector<vector<int>>>>> Hough_Space(r, vector<vector<vector<vector<int>>>>(c, vector<vector<vector<int>>>(max, vector<vector<int>>(max, vector<int>(180, 0)))));
    for (int x = 0; x < c; ++x)
    {
        for (int y = 0; y < r; ++y)
        {
            if (input_image.at<uchar>(x, y) != 0)
            {
                for (int a = 0; a < max; ++a)
                {
                    for (int b = 0; b < max; ++b)
                    {
                        for (int tangle = 0; tangle < 180; ++tangle)
                        {
                            int x0 = cvRound(x - vcos[a][tangle]);
                            int y0 = cvRound(y - vcos[b][tangle]);
                            if (x0 >= 0 && x0 < r && y0 >= 0 && y0 < c)
                                Hough_Space[x0][y0][a][b][tangle]++;
                        }
                    }
                }
            }
        }
    }
    //筛选
    for (int x = 0; x < r; ++x)
    {
        for (int y = 0; y < c; ++y)
        {
            for (int a = 0; a < max; ++a)
            {
                for (int b = 0; b < max; ++b)
                {
                    int th = (a + b) * threshold_base;
                    for (int t = 0; t < 180; ++t)
                    {
                        if (Hough_Space[x][y][a][b][t] > th)
                        {
                            array<int, 6> newe = {x, y, a, b, t, Hough_Space[x][y][a][b][t]};
                            out.push_back(newe);
                        }
                    }
                }
            }
        }
    }
    return out;
}
