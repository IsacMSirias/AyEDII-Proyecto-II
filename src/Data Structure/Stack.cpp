#include "Stack.h"

Stack::Stack(){

    top = -1;

    for (int i = 0; i < 5; i++) {
        
        array[i] = 0;
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

    if(top == 4){
        return true;
    }
    else{
       return false; 
    }
}


void Stack::push(int value){

    if(isFull()){
        std::cout<< "stack overflow"<<std::endl;
    }
    else{
        top++; 
        array[top] = value;
    }

}

int Stack::pop(){

    if(isEmpty()){
        std::cout<< "stack overflow"<<std::endl;
        return 0;
    }
    else{
        int popValue = array[top];
        array[top] = 0;
        top--;
        return popValue; 
    }
}

int Stack::counterValues(){
    return (top +1);
}

int Stack::peek(int pos){
    if(isEmpty()){
        std::cout<< "stack overflow"<<std::endl;
        return 0;
    }
    else{
        return array[pos];
    }
}