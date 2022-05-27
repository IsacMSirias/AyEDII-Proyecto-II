#include "Stack.h"

Stack::Stack(){

    top = -1;

    for (int i = 0; i < 5; i++) {

        array[i]->createMatrix();
    }

}

bool Stack::isEmpty(){

    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool Stack::isFull(){

    if(top == 5){
        return true;
    }
    else{
       return false;
    }
}


void Stack::push(rgbMatrix value){

    if(isFull()){
        std::cout<< "Stack overflow"<<std::endl;
    }
    else{
        top++;
        *array[top] = value;
    }

}

rgbMatrix Stack::pop(){

    if(isEmpty()){
        std::cout<< "Stack is empty"<<std::endl;
        //return ;
    }
    else{
        rgbMatrix popValue = *array[top];
        //array[top] = 0;
        top--;
        return popValue;
    }
}

int Stack::counterValues(){
    return (top +1);
}

rgbMatrix Stack::peek(int pos){
    if(isEmpty()){
        std::cout<< "Stack is empty"<<std::endl;
        //return 0;
    }
    else{
        return *array[pos];
    }
}
