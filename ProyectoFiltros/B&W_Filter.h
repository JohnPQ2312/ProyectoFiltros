#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void BnW_Filter(Mat img, Mat modified) {
    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
         Vec3b color = img.at<Vec3b>(Point(x, y));
         double graypixel = color[0] * 0.299 + color[1] * 0.587 + color[2] * 0.114;
         color[0] = graypixel;
         color[1] = graypixel;
         color[2] = graypixel;
         modified.at<Vec3b>(Point(x, y)) = color;
        }
    }
}