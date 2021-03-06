#ifndef BmpImage_h
#define BmpImage_h

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <string>

#define FILE_HEADER_SIZE 14
#define INFO_HEADER_SIZE 40
#define BITS_PER_PIXEL 24

class BmpImage{

private:
    unsigned char *bmpPixelArray;
    int height;
    int width;
    int paddingBytes;
    std::string name;


public:
    BmpImage(std::string imgName, int height, int width, unsigned char *pixelArray, int pixelArraySize);
    BmpImage(std::string imgPath);

    void read();

    void generateBitmapImage(std::string imgName, int pixelArraySize);

    unsigned char* createBitmapFileHeader();
    unsigned char* createBitmapInfoHeader();

    void fillFourBytes(unsigned char *array, int value, int init_byte);
    
    int get_Height();
    int get_Width();
    unsigned char* getDataArray();

};
#endif