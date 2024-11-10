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
#include "ShowImage.h"

//Namespaces
using namespace cv;
using namespace std;

int main() {
    bool option = true;
    char key;
    string name = "Original";

    //Load the image
    Mat img = imread("C:/Users/John/Downloads/kanye-west-1707302156.7580967.jpg");
    if (img.empty()) {
        cerr << "Error: No se pudo cargar la imagen." << endl;
        return -1; //Used for indicating an error
    }

	//Show the original image
    ShowImage(img, name);

    while (option == true) {
        Mat modifiedclone(img.rows, img. cols, img.type()); //Copy for modifications
        Mat invertedclone(img.cols, img.rows, img.type()); //Copy with inverted dimensions
		key = waitKey(0);
		char pressedK = static_cast<char>(key); //Converts the key to a char
		char uppercaseK = toupper(pressedK); //Converts the char to uppercase

        switch (uppercaseK) {
            case 'O':
				name = "Original";
                destroyAllWindows();
                ShowImage(img, name);
                break;
            case 'A':
                destroyAllWindows();
                name = "Blanco y negro";
                BnW_Filter(img, modifiedclone);
                ShowImage(modifiedclone, name);
                break;
            case 'B':
                name = "Invertido horizontal";
                destroyAllWindows();
                InvertedX(img, modifiedclone);
                ShowImage(modifiedclone, name);
                break;
            case 'C':
                name = "Invertido vertical";
                destroyAllWindows();
                InvertedY(img, modifiedclone);
                ShowImage(modifiedclone, name);
                break;
            case 'D':
                name = "90 grados";
                destroyAllWindows();
                Rotate(img, invertedclone);
                ShowImage(invertedclone, name);
                break;
            case 'E':
                name = "Negativo";
                destroyAllWindows();
                Negative(img, modifiedclone);
                ShowImage(modifiedclone, name);
                break;
            case 27:
                destroyAllWindows();
                option = false;
                break;
        }
    }
}