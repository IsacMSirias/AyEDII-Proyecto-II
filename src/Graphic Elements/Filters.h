#ifndef Filters_h
#define Filters_h

#include <iostream>
#include <string>
#include "../Data Structure/rgbMatrix.h"
#include "../Data Structure/rgbMatrix.h"


class Filters {

public:

    void grayFilter(rgbMatrix matrix);
    void negativeFilter(rgbMatrix matrix);
    void paintFill(const rgbColor &colorPicked, const rgbColor &selectedColor, int x, int y, rgbMatrix matrix);

};


#endif