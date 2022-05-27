#ifndef Stack_h
#define Stack_h

#include <iostream>
#include "rgbMatrix.h"

struct action {
    const char* actionName;
    int posX, posY, posX2, posY2;
    rgbColor color;
    int thickness;
};

class Stack {

private:

    int top;
    rgbMatrix* array[5];

public:

    Stack();
    bool isEmpty();
    bool isFull();
    void push(rgbMatrix value);
    rgbMatrix pop();
    int counterValues();
    rgbMatrix peek(int pos);
};




#endif
