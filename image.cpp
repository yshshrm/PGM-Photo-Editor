#include <stdlib.h>
#include <iostream>
#include "image.h"
#include <cmath>
using namespace std;

Image::Image()
{
    N = 0;
    M = 0;
    Q = 0;

    pixelVal = NULL;
}

Image::Image(int numRows, int numCols, int grayLevels)
{

    N = numRows;
    M = numCols;
    Q = grayLevels;

    pixelVal = new int *[N];
    for(int i = 0; i < N; i++)
    {
        pixelVal[i] = new int [M];
        for(int j = 0; j < M; j++)
            pixelVal[i][j] = 0;
    }
}

Image::~Image()
{
    N = 0;
    M = 0;
    Q = 0;

    for(int i = 0; i < N; i++)
        delete pixelVal [N];

    delete pixelVal;
}

Image::Image(const Image& oldImage)
{
    N = oldImage.N;
    M = oldImage.M;
    Q = oldImage.Q;

    pixelVal = new int* [N];
    for(int i = 0; i < N; i++)
    {
        pixelVal[i] = new int [M];
        for(int j = 0; j < M; j++)
            pixelVal[i][j] = oldImage.pixelVal[i][j];
    }
}

void Image::operator=(const Image& oldImage)
{
    N = oldImage.N;
    M = oldImage.M;
    Q = oldImage.Q;

    pixelVal = new int* [N];
    for(int i = 0; i < N; i++)
    {
        pixelVal[i] = new int [M];
        for(int j = 0; j < M; j++)
            pixelVal[i][j] = oldImage.pixelVal[i][j];
    }
}

void Image::setImageInfo(int numRows, int numCols, int maxVal) {
    N = numRows;
    M = numCols;
    Q = maxVal;
}

void Image::getImageInfo(int &numRows, int &numCols, int &maxVal) {
    numRows = N;
    numCols = M;
    maxVal = Q;
}

int Image::getPixelVal(int row, int col) {
    return pixelVal[row][col];
}


void Image::setPixelVal(int row, int col, int value) {
    pixelVal[row][col] = value;
}

bool Image::inBounds(int row, int col){
    if(row >= N || row < 0 || col >=M || col < 0)
        return false;
    //else
    return true;
}

void Image::getSubImage(int upperLeftRow, int upperLeftCol, int lowerRightRow, int lowerRightCol, Image& oldImage){
    int width, height;

    width = lowerRightCol - upperLeftCol;
    height = lowerRightRow - upperLeftRow;

    Image tempImage(height, width, Q);

    for(int i = upperLeftRow; i < lowerRightRow; i++) {
        for(int j = upperLeftCol; j < lowerRightCol; j++)
            tempImage.pixelVal[i - upperLeftRow][j - upperLeftCol] = oldImage.pixelVal[i][j];
    }

    oldImage = tempImage;
}

int Image::meanGray(){
    int totalGray = 0;

    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < M; j++)
            totalGray += pixelVal[i][j];
    }

    int cells = M * N;

    return (totalGray / cells);
}

void Image::enlargeImage(int value, Image& oldImage) {
     int rows, cols, gray;
     int pixel;
     int enlargeRow, enlargeCol;

     rows = oldImage.N * value;
     cols = oldImage.M * value;
     gray = oldImage.Q;

     Image tempImage(rows, cols, gray);

     for(int i = 0; i < oldImage.N; i++) {
             for(int j = 0; j < oldImage.M; j++) {
                     pixel = oldImage.pixelVal[i][j];
                     enlargeRow = i * value;
                     enlargeCol = j * value;
                     for(int c = enlargeRow; c < (enlargeRow + value); c++) {
                             for(int d = enlargeCol; d < (enlargeCol + value); d++) {
                                     tempImage.pixelVal[c][d] = pixel;
                             }
                     }
             }
     }

     oldImage = tempImage;
}

void Image::shrinkImage(int value, Image& oldImage) {
    int rows, cols, gray;

    rows = oldImage.N / value;
    cols = oldImage.M / value;
    gray = oldImage.Q;

    Image tempImage(rows, cols, gray);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            tempImage.pixelVal[i][j] = oldImage.pixelVal[i * value][j * value];
    }
    oldImage = tempImage;
}

void Image::reflectImage(bool flag, Image& oldImage) {
    int rows = oldImage.N;
    int cols = oldImage.M;
    Image tempImage(oldImage);
    if(flag == true) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++)
                tempImage.pixelVal[rows - (i + 1)][j] = oldImage.pixelVal[i][j];
        }
    }
    else {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++)
                tempImage.pixelVal[i][cols - (j + 1)] = oldImage.pixelVal[i][j];
        }
    }

    oldImage = tempImage;
}

void Image::negateImage(Image& oldImage) {
    int rows, cols, gray;
    rows = N;
    cols = M;
    gray = Q;

    Image tempImage(N,M,Q);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            tempImage.pixelVal[i][j] = -(pixelVal[i][j]) + 255;
    }

    oldImage = tempImage;
}

Image Image::operator+(const Image &oldImage) {
    Image tempImage(oldImage);

    int rows, cols;
    rows = oldImage.N;
    cols = oldImage.M;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            tempImage.pixelVal[i][j] = (pixelVal[i][j] + oldImage.pixelVal[i][j]) / 2;
    }

    return tempImage;
}

Image Image::operator-(const Image& oldImage) {
    Image tempImage(oldImage);

    int rows, cols;
    rows = oldImage.N;
    cols = oldImage.M;
    int tempGray = 0;

     for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {

            tempGray = abs(pixelVal[i][j] - oldImage.pixelVal[i][j]);
            tempImage.pixelVal[i][j] = tempGray;
        }

    }

    return tempImage;
}
