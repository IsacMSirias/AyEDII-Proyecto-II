#include "Filters.h"


void Filters::grayFilter(rgbMatrix matrix){

    for (int x = 0; x < matrix.get_Height(); x++){
        for (int y = 0; y < matrix.get_Width(); y++){

            rgbColor tempRGB = matrix.getColor(x,y);
            float grayScale = (tempRGB.r*0.3) + (tempRGB.g *0.59) + (tempRGB.b * 0.11);

            matrix.setColor(rgbColor(grayScale, grayScale, grayScale), x, y);
    
        }
        
    }
    
    std::cout<< "Gray Scale Filter apply"<< std::endl;
}

void Filters:: negativeFilter(rgbMatrix matrix){

    for (int x = 0; x < matrix.get_Height(); x++){

        for (int y = 0; y < matrix.get_Width(); y++){

            rgbColor tempRGB =  matrix.getColor(x,y);
            float Negative_R = 255 - tempRGB.r;
            float Negative_G = 255 - tempRGB.g;
            float Negative_B = 255 - tempRGB.b;
            matrix.setColor(rgbColor(Negative_R, Negative_G, Negative_B), x, y);
        }
        
    }
    
    std::cout<< "Negative Filter apply"<< std::endl;
}

void Filters::paintFill(const rgbColor &colorPicked, const rgbColor &selectedColor, int x, int y, rgbMatrix matrix){

    if(x < matrix.get_Width() && y < matrix.get_Height() && x >= 0 && y >= 0){
        rgbColor currentColor = matrix.getColor(y, x);
        if(currentColor.b == colorPicked.b && currentColor.g == colorPicked.g && currentColor.r == colorPicked.r){

            matrix.setColor(selectedColor, y, x);
            paintFill(colorPicked, selectedColor, x -1, y, matrix);
            paintFill(colorPicked, selectedColor, x +1, y, matrix);
            paintFill(colorPicked, selectedColor, x , y -1, matrix);
            paintFill(colorPicked, selectedColor, x , y+ 1, matrix);
        }
    }
}

