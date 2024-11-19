#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void InvertedX(Mat img, Mat horizontal) {
    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {

            int invertedX = img.cols - 1 - x;

            horizontal.at<Vec3b>(Point(invertedX, y)) = img.at<Vec3b>(Point(x, y));
        }
    }
}

void InvertedY(Mat img, Mat vertical) {
    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {

            int invertedY = img.rows - 1 - y;

            vertical.at<Vec3b>(Point(x, invertedY)) = img.at<Vec3b>(Point(x, y));
        }
    }
}
