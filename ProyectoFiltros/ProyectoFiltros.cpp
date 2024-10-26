//Used libraries
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <windows.h>

//Functions in separated headers
#include "B&W_Filter.h"
#include "ResizeImg.h"

//Namespaces
using namespace cv;
using namespace std;

int main() {

	// Load the image
    Mat img = imread("C:/Users/John/Downloads/IMG_2650.JPEG");
    if (img.empty()) {
        cerr << "Error: No se pudo cargar la imagen." << endl;
		return -1; //Used for indicating an error
    }

	//BnW_Filter(img);

    // for (int y = 0; y < img.rows; y++) {
    //     for (int x = 0; x < img.cols / 2; x++) {
             //Vec3b left = img.at<Vec3b>(Point(x, y));
             //Vec3b right = img.at<Vec3b>(Point(img.cols - 1 - x, y));

             //img.at<Vec3b>(Point(x, y)) = right;
             //img.at<Vec3b>(Point(img.cols - 1 - x, y)) = left;
    //     }
    // }

     //for (int y = 0; y < img.rows / 2; y++) {
     //    for (int x = 0; x < img.cols; x++) {
     //        Vec3b up = img.at<Vec3b>(Point(x, y));
     //        Vec3b down = img.at<Vec3b>(Point(x, img.rows - 1 - y));

     //        img.at<Vec3b>(Point(x, y)) = down;
     //        img.at<Vec3b>(Point(x, img.rows - 1 - y)) = up;
     //    }
     //}

	//Mat rotated(img.cols, img.rows, img.type()); //Creates a copy of the image with the dimensions inverted
 //    for (int y = 0; y < img.rows; y++) {
 //        for (int x = 0; x < img.cols; x++) {
	//		 rotated.at<Vec3b>(x, img.rows - 1 - y) = img.at<Vec3b>(y, x);
 //        }
 //    }

    resize(img);
    namedWindow("Imagen Ajustada", WINDOW_NORMAL);
    imshow("Imagen Ajustada", img);
    moveWindow("Imagen Ajustada", 0, 45);
    waitKey(0);
    destroyAllWindows();

    return 0;
}