#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#include "B&W_Filter.h"

using namespace cv;
using namespace std;

int main() {
    Mat img = imread("C:/Users/John/Downloads/IMG_2650.JPEG");
    if (img.empty()) {
        cerr << "Error: No se pudo cargar la imagen." << endl;
        return -1;
    }

	BnW_Filter(img);

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


    namedWindow("Modified Image", WINDOW_AUTOSIZE);
    imshow("Modified Image", img);
    cv::moveWindow("Modified Image", 0, 45);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}