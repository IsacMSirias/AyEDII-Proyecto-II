#ifndef GRAPHICS_h
#define GRAPHICS_h

#include <iostream>
#include <string>
#include <cmath>
#include "../Data Structure/rgbMatrix.h"
#include "../Data Structure/rgbMatrix.h"


class Graphics {

public:

    void draw_WhitPencil(const rgbColor &rgbColor, int x, int y , int thickness, rgbMatrix matrix);
    void draw_WhitPen(const rgbColor &rgbColor, int initial_y, int initial_x, int final_y, int final_x, int thickness, rgbMatrix matrix);
    void paintFill(const rgbColor &colorPicked, const rgbColor &selectedColor, int x, int y, rgbMatrix matrix);
    void grayFilter(rgbMatrix matrix);
    void negativeFilter(rgbMatrix matrix);
    
};


#endif