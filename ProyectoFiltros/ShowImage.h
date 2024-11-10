#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void ShowImage(Mat img, string name) {
	resize(img);
    namedWindow(name, WINDOW_NORMAL);
    imshow(name, img);
    moveWindow(name, 0, 45);
}