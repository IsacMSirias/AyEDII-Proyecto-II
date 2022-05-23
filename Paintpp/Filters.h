#ifndef Filters_h
#define Filters_h

#include <iostream>
#include <string>
#include "rgbMatrix.h"


class Filters {

public:

    void grayFilter(rgbMatrix matrix);
    void negativeFilter(rgbMatrix matrix);

};


#endif
