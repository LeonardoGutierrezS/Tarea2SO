#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <chrono>

using namespace cv;
using namespace std;

void convertToGrayScale(Mat& image, Mat& grayImage, int startRow, int endRow) {
    for(int r = startRow; r < endRow; r++) {
        for(int c = 0; c < image.cols; c++) {
            Vec3b& color = image.at<Vec3b>(r, c);
            grayImage.at<uchar>(r, c) = color[0]*0.11 + color[1]*0.59 + color[2]*0.3;
        }
    }
}

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
    vector<thread> threads;

    auto start = chrono::high_resolution_clock::now();

    for(int i = 0; i < numThreads; i++) {
        int startRow = i * image.rows / numThreads;
        int endRow = (i+1) * image.rows / numThreads;
        threads.push_back(thread(convertToGrayScale, ref(image), ref(grayImage), startRow, endRow));
    }

    for(auto& th : threads) {
        th.join();
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Tiempo de ejecución: " << duration.count()/1e6 << " segundos" << endl;

    imwrite(outputImagePath, grayImage);

    return 0;
}
