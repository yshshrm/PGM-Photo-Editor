# Image Processing using C++

## Functions

#### Functions for single image

setImageInfo- sets the number of rows, columns and graylevels

getImageInfo- returns the number of rows, columns and gray levels

getPixelVal- returns the gray value of a specific pixel

setPixelVal- sets the gray value of a specific pixel

#### Functions for multiple image input

getSubImage- Pulls a sub image out of oldImage based on users values, and then stores it in oldImage

enlargeImage- enlarges Image and stores it in tempImage, resizes oldImage and stores the larger image in oldImage

shrinkImage- Shrinks image as storing it in tempImage, resizes oldImage, and stores it in oldImage

reflectImage- Reflects the Image based on users input

rotateImage- based on users input and rotates it around the center of the image.

#### Functions using Operator overloading

Image::operator+ -adds images together, half one image, half the other

Image::operator- - subtracts images from each other

## Running the program

```./myprog <parameters>```
