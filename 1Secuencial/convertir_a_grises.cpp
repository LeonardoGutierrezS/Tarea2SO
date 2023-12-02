#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <imagen_a_color> <imagen_grises>" << endl;
        return -1;
    }

    // obtiene input y output del usuario
    string inputImagePath = argv[1];
    string outputImagePath = argv[2];

    Mat image = imread(inputImagePath, IMREAD_COLOR);
    // validacion
    if (image.empty()) {
        cout << "No se pudo cargar la imagen: " << inputImagePath << endl;
        return -1;
    }

    Mat grayImage(image.rows, image.cols, CV_8UC1);

    auto start = chrono::high_resolution_clock::now();

    for (int r = 0; r < image.rows; r++) {
        for (int c = 0; c < image.cols; c++) {
            Vec3b& color = image.at<Vec3b>(r, c);

            // Convertir a escala de grises (promedio ponderado)
            uchar grayValue = static_cast<uchar>(color[0] * 0.11 + color[1] * 0.59 + color[2] * 0.3);

            grayImage.at<uchar>(r, c) = grayValue;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Tiempo de ejecución: " << duration.count() / 1e6 << " segundos" << endl;

    imwrite(outputImagePath, grayImage);

    return 0;
}


