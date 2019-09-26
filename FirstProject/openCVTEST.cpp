/*
 * @Description: 
 * @Author: TheNightIsYoung
 * @E-Mail: guojie0213_iit@163.com
 * @Date: 2019-09-23 15:53:29
 * @LastEditors: TheNightIsYoung
 * @LastEditTime: 2019-09-26 11:52:10
 */
#include <iostream>

#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char const *argv[])
{
    /**
     * @Description: 
     * @Func: OpenCV Interface Test
     * @Param: 
     * @return: std::string imgPath =
     */

    std::cout << "Image Display" << std::endl;

    std::string imgPath = "/home/deeplearning/Software/RedEyeRemover/red_eyes.jpg";
    std::cout << imgPath << std::endl;

    Mat srcImage = imread(imgPath);
    
    imshow("srcImage", srcImage);
    cvWaitKey(2);

    return 0;
}
