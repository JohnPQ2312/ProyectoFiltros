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
    Mat img = imread("C:/Users/John/Downloads/kanye-west-1707302156.7580967.jpg");
    if (img.empty()) {
        cerr << "Error: No se pudo cargar la imagen." << endl;
		return -1; //Used for indicating an error
    }

	Mat modifiedclone(img.rows, img.cols, img.type()); //Creates a copy of the image with the same dimensions
	Mat invertedclone(img.cols, img.rows, img.type()); //Creates a copy of the image with the dimensions inverted

    resize(modifiedclone);
    namedWindow("Imagen Ajustada", WINDOW_NORMAL);
    imshow("Imagen Ajustada", modifiedclone);
    moveWindow("Imagen Ajustada", 0, 45);
    waitKey(0);
    destroyAllWindows();

    return 0;
}