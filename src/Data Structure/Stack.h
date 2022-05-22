#ifndef Stack_h
#define Stack_h

#include <iostream>
#include <string>


class Stack {

private:
    
    int top;
    int array[5];

public:

    Stack();
    bool isEmpty();
    bool isFull();
    void push(int value);
    int pop();    
    int counterValues();
    int peek(int pos);
};




#endif