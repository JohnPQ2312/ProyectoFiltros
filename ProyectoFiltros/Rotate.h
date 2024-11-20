#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void Rotate(Mat img, Mat rotated) { //Función para rotar la imagen en 90 grados
	for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
   		    rotated.at<Vec3b>(x, img.rows - 1 - y) = img.at<Vec3b>(y, x);
        }
    }
}
