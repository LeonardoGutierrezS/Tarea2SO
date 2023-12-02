#include <iostream>
#include <opencv2/opencv.hpp>
#include <omp.h>
#include <chrono>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " <imagen_a_color> <imagen_grises> <num_hilos>" << endl;
        return -1;
    }

    string inputImagePath = argv[1];
    string outputImagePath = argv[2];
    int numThreads = atoi(argv[3]);

    Mat image = imread(inputImagePath, IMREAD_COLOR);

    if (image.empty()) {
        cout << "No se pudo cargar la imagen: " << inputImagePath << endl;
        return -1;
    }

    Mat grayImage(image.rows, image.cols, CV_8UC1);

    auto start = chrono::high_resolution_clock::now();

    #pragma omp parallel for num_threads(numThreads)
    for(int r = 0; r < image.rows; r++) {
        for(int c = 0; c < image.cols; c++) {
            Vec3b& color = image.at<Vec3b>(r, c);
            grayImage.at<uchar>(r, c) = color[0]*0.11 + color[1]*0.59 + color[2]*0.3;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Tiempo de ejecución: " << duration.count()/1e6 << " segundos" << endl;

    imwrite(outputImagePath, grayImage);

    return 0;
}

