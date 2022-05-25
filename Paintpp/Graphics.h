#ifndef GRAPHICS_h
#define GRAPHICS_h

#include <iostream>
#include <cmath>
#include "rgbMatrix.h"
#include "rgbMatrix.h"


class Graphics {

public:

    void draw_WithPencil(const rgbColor &rgbColor, int x, int y , int thickness, rgbMatrix matrix);
    void draw_WithPen(const rgbColor &rgbColor, int initial_y, int initial_x, int final_y, int final_x, int thickness, rgbMatrix matrix);
    void paintFill(const rgbColor &colorPicked, const rgbColor &selectedColor, int x, int y, rgbMatrix matrix);
    void grayFilter(rgbMatrix matrix);
    void negativeFilter(rgbMatrix matrix);
    void experimentalFilter1(rgbMatrix matrix);
    void experimentalFilter2(rgbMatrix matrix);
    void triangle (const rgbColor &rgbColor, int initial_x,  int initial_y, int final_x, int final_y,int thickness, rgbMatrix rgbMatrix);
    void square(const rgbColor &rgbcolor, int initial_x, int initial_y, int final_x, int final_y, int thickness, rgbMatrix matrix);
    void circle (const rgbColor &rgbColor, int initial_x, int initial_y, int final_x, int final_y, int thickness, rgbMatrix matrix);
};


#endif
