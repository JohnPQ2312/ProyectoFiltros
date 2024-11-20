#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <windows.h>

using namespace cv;
using namespace std;

void resize(Mat& img) { //Función para redimensionar imagen a las dimensiones de la pantalla del dispositivo
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    resize(img, img, Size(screenWidth, screenHeight));
}


