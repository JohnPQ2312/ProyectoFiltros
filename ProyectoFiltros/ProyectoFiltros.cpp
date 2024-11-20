//Bibliotecas usadas
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <windows.h>

//Funciones en distintos .h
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

    //Ruta y carga de imagen
    Mat img = imread("C:/Users/John/Downloads/kanye-west-1707302156.7580967.jpg");
    if (img.empty()) {
        cerr << "Error: No se pudo cargar la imagen." << endl;
        return -1;
    }

	//Muestra la imagen original en pantalla
    ShowImage(img, name);

    while (option == true) {
        Mat modifiedclone(img.rows, img. cols, img.type()); //Clon para modificaciones
        Mat invertedclone(img.cols, img.rows, img.type()); //Clon de dimensiones invertidas
		key = waitKey(0);
		char pressedK = static_cast<char>(key); //Convierte la tecla en char
		char uppercaseK = toupper(pressedK); //Convierte el char en mayúscula

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
