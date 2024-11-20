#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void Negative(Mat img, Mat modified) { //Función para poner en negativo la imágen
	for (int y = 0; y < img.rows; y++) {
		for (int x = 0; x < img.cols; x++) {
			Vec3b color = img.at<Vec3b>(Point(x, y));
			color[0] = 255 - color[0];
			color[1] = 255 - color[1];
			color[2] = 255 - color[2];
			modified.at<Vec3b>(Point(x, y)) = color; 
		}
	}
}
