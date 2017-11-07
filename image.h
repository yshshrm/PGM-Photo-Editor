#ifndef IMAGE_H
#define IMAGE_H

class Image
{
      public:
             Image();
             Image(int numRows, int numCols, int grayLevels);
             ~Image();
             Image(const Image& oldImage);
             void operator=(const Image&);
             void setImageInfo(int numRows, int numCols, int maxVal);
             void getImageInfo(int &numRows, int &numCols, int &maxVal);
             int getPixelVal(int row, int col);
             void setPixelVal(int row, int col, int value);
             bool inBounds(int row, int col);
             void getSubImage(int upperLeftRow, int upperLeftCol,
                int lowerRightRow, int lowerRightCol, Image& oldImage);
             int meanGray();
             void enlargeImage(int value, Image& oldImage);
             void shrinkImage(int value, Image& oldImage);
             void reflectImage(bool flag, Image& oldImage);
             Image operator+(const Image &oldImage);
             Image operator-(const Image& oldImage);
             void negateImage(Image& oldImage);
      private:
              int N; 
              int M; 
              int Q; 
              int **pixelVal;
};

#endif
