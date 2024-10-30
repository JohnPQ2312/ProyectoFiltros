//Used libraries
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <windows.h>

//Functions in separated headers
#include "B&W_Filter.h"
#include "ResizeImg.h"
#include "InvertedXY.h"
#include "Rotate.h"
#include "NegativeFilter.h"

//Namespaces
using namespace cv;
using namespace std;

int main() {
    bool option = true;
    char key;

    // Load the image
    Mat img = imread("C:/Users/jp570/Downloads/kanye-west-1707302156.7580967.jpg");
    if (img.empty()) {
        cerr << "Error: No se pudo cargar la imagen." << endl;
        return -1; //Used for indicating an error
    }

	// Show the original image
    resize(img);
    namedWindow("Original", WINDOW_NORMAL);
    imshow("Original", img);
    moveWindow("Original", 0, 45);


    while (option == true) {
        Mat modifiedclone(img.rows, img. cols, img.type()); //Creates a copy of the image
        Mat invertedclone(img.cols, img.rows, img.type()); //Creates a copy of the image with the dimensions inverted
		key = waitKey(0); //Waits for a key to be pressed

        switch (key) {
            case 'O':
                case 'o':
                    destroyAllWindows();
                    resize(img);
                    namedWindow("Original", WINDOW_NORMAL);
                    imshow("Original", img);
                    moveWindow("Original", 0, 45);
                    break;
            case 'A':
                case 'a':
                    destroyAllWindows();
                    BnW_Filter(img, modifiedclone);
                    resize(modifiedclone);
                    namedWindow("Blanco y Negro", WINDOW_NORMAL);
                    imshow("Blanco y Negro", modifiedclone);
                    moveWindow("Blanco y Negro", 0, 45);
                    break;
            case 'B':
                case 'b':
                    destroyAllWindows();
                    InvertedX(img, modifiedclone);
                    resize(modifiedclone);
                    namedWindow("Inversión Horizontal", WINDOW_NORMAL);
                    imshow("Inversión Horizontal", modifiedclone);
                    moveWindow("Inversión Horizontal", 0, 45);
                    break;
            case 'C':
                case 'c':
                    destroyAllWindows();
                    InvertedY(img, modifiedclone);
                    resize(modifiedclone);
                    namedWindow("Inversión Vertical", WINDOW_NORMAL);
                    imshow("Inversión Vertical", modifiedclone);
                    moveWindow("Inversión Vertical", 0, 45);
                    break;
            case 'D':
                case 'd':
                    destroyAllWindows();
                    Rotate(img, invertedclone);
                    resize(invertedclone);
                    namedWindow("Rotación 90", WINDOW_NORMAL);
                    imshow("Rotación 90", invertedclone);
                    moveWindow("Rotación 90", 0, 45);
                    break;
            case 'E':
                case 'e':
                    destroyAllWindows();
                    Negative(img, modifiedclone);
                    resize(modifiedclone);
                    namedWindow("Negativo", WINDOW_NORMAL);
                    imshow("Negativo", modifiedclone);
                    moveWindow("Negativo", 0, 45);
                    break;
            case 27:
                destroyAllWindows();
				option = false;
				break;
        }
    }
}