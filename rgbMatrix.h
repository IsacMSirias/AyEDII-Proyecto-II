#ifndef ImageMatrix_h
#define ImageMatrix_h

#define BITS_PER_PIXEL 24

#include <cstdlib>
#include <iostream>
#include <fstream>


struct rgbColor
{
    float r, g, b;
    rgbColor();
    rgbColor(float r, float g, float b);

};

class rgbMatrix
{
private:
    int pixelSize;
    int paddingBytes;
    int m_width;
    int m_height;

    rgbColor **matrix;
    unsigned char* pixels_inMatrix;

public:
    rgbMatrix(int width, int height);
    void createMatrix();
    int getHeight();
    int getWidth();

    void clearMatrix();
    rgbColor getColor(int x, int y);

    void setColor(const rgbColor &rgbcolor, int x, int y);
    
    void reflectX();
    void reflectY();
    void reflectXY();
    void rotate90CW();
    void rotate180();

    
    void read (const char* path);
    
    
    void CreateRgbArray();
    unsigned char* get_rgbArray();
    int get_rgbArraySize();
    void whiteCanvas();
    
    

    
    

};


#endif