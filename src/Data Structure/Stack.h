#ifndef Stack_h
#define Stack_h

#include "rgbMatrix.h"

// struct action {
//     const char* actionName;
//     int posX, posY, posX2, posY2;
//     rgbColor color;
//     int thickness;
// };

class Stack {

private:

    int size;
    int top;
    rgbMatrix** array;

public:

    Stack(int size);
    bool isEmpty();
    bool isFull();
    void push(rgbMatrix value);
    rgbMatrix pop();
    int counterValues();
    rgbMatrix peek(int pos);
};

#endif