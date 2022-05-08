#include <iostream>
#include "Image.h"
#include "Image.cpp"



int main(){
    const int width = 640;
    const int height = 480;

    Image image(width,height);

    for(int y = 0; y < height ; y++)
    {
        for(int x = 0; x<width ; x++){

            image.setColor(Color(111,222,111),x , y);
        }
    }
    image.Export("imageprueba.bmp");

    int i = 233;

    for(int m = 0; m < 400; m++ ){
        image.setColor(Color(255,255,255), m, i);
    }


    image.Read("imageprueba.bmp");

    image.Export("copy.bmp");

    return 0;
    
}// ekisde, no se hizo el commid unu 