#include "Graphics.h"



void Graphics::draw_WithPencil(const rgbColor &rgbColor, int x, int y , int thickness, rgbMatrix matrix){
    
    int maxThickness = thickness -1;

    for (int i = x - maxThickness; i <= x + maxThickness; i++){

        for (int j = y-maxThickness; j <= y + maxThickness; j++){
            
            matrix.setColor(rgbColor, i, j);

        }   
    }
 }

    
void Graphics::draw_WithPen(const rgbColor &rgbColor, int initial_y, int initial_x, int final_y,
                                        int final_x, int thickness, rgbMatrix matrix){

    if (final_x - initial_x == 0){
        if (final_y < initial_y){

            int varTemp = initial_y;
            initial_y = final_y;
            final_y = varTemp;
        }
        for (int i = initial_y; i <= final_y; i++){
            draw_WithPencil(rgbColor, i, initial_x, thickness, matrix);
        }
    }else{
        float m = (float)(final_y - initial_y) / (float)(final_x - initial_x);
        float b = initial_y - (m * initial_x);
        if (final_x < initial_x){
            
            int varTemp = initial_x;
            initial_x = final_x;
            final_x = varTemp;
        }
        int old_y = round(m * initial_x + b);
        for (int i = initial_x; i <= final_x; i++){
            int new_y = round(m * i + b);
            if (new_y == old_y){
                draw_WithPencil(rgbColor, new_y, i, thickness, matrix);
            }else{
                if (m >= 0){
                    for (int j = old_y + 1; j <= new_y; j++){
                        draw_WithPencil(rgbColor, j, i, thickness, matrix);
                    }
                }else{
                    for (int j = old_y - 1; j >= new_y; j--){
                        draw_WithPencil(rgbColor, j, i, thickness, matrix);
                    }
                }
            }
            old_y = new_y;
        }
    }
}

void Graphics::grayFilter(rgbMatrix matrix){

    for (int x = 0; x < matrix.get_Height(); x++){
        for (int y = 0; y < matrix.get_Width(); y++){

            rgbColor tempRGB = matrix.getColor(x,y);
            float grayScale = (tempRGB.r*0.3) + (tempRGB.g *0.59) + (tempRGB.b * 0.11);

            matrix.setColor(rgbColor(grayScale, grayScale, grayScale), x, y);
    
        }
        
    }
    
    std::cout<< "Gray Scale Filter apply"<< std::endl;
}

void Graphics:: negativeFilter(rgbMatrix matrix){

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

void Graphics:: experimentalFilter1(rgbMatrix matrix){

    for (int x = 0; x < matrix.get_Height(); x++){

        for (int y = 0; y < matrix.get_Width(); y++){

            rgbColor tempRGB =  matrix.getColor(x,y);
            float new_R = 111 - tempRGB.r;
            float new_G = 222 + tempRGB.g;
            float new_B = 111 - tempRGB.b;
            matrix.setColor(rgbColor(new_R, new_G, new_B), x, y);
        }

    }

    std::cout<< "extra  Filter apply"<< std::endl;
}


void Graphics:: experimentalFilter2(rgbMatrix matrix)
{
    for (int x = 0; x < matrix.get_Height(); x++){

        for (int y = 0; y < matrix.get_Width(); y++){

            rgbColor tempRGB =  matrix.getColor(x,y);
            float new_R = 111* tempRGB.r;
            float new_G = 222*tempRGB.g;
            float new_B = 111*tempRGB.b;
            matrix.setColor(rgbColor(new_R, new_G, new_B), x, y);
        }

    }

    std::cout<< "extra  Filter apply"<< std::endl;
}

void Graphics::paintFill(const rgbColor &colorPicked, const rgbColor &selectedColor, int x, int y, rgbMatrix matrix)
{
    if (selectedColor.b == colorPicked.b && selectedColor.g == colorPicked.g && selectedColor.r == colorPicked.r)
    {
        std::cout << "Can't fill the same color." << std::endl;
    }
    else if(x < matrix.get_Width() && y < matrix.get_Height() && x >= 0 && y >= 0){
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

void Graphics::triangle(const rgbColor &rgbcolor, int initial_x, int initial_y, int final_x, 
                                                int final_y, int thickness, rgbMatrix matrix)
{
    int dx = (final_x - initial_x) / 2;
    draw_WithPen(rgbcolor, initial_y, initial_x + dx, final_y, final_x, thickness, matrix);
    draw_WithPen(rgbcolor, initial_y, initial_x + dx, final_y, initial_x, thickness, matrix);
    draw_WithPen(rgbcolor, final_y, initial_x, final_y, final_x, thickness, matrix);
}


void Graphics::square(const rgbColor &rgbcolor, int initial_x, int initial_y, int final_x, 
                                            int final_y, int thickness, rgbMatrix matrix)
{
    draw_WithPen(rgbcolor, initial_y, initial_x, initial_y, final_x, thickness, matrix);
    draw_WithPen(rgbcolor, initial_y, initial_x, final_y, initial_x, thickness, matrix);
    draw_WithPen(rgbcolor, initial_y, final_x, final_y, final_x, thickness, matrix);
    draw_WithPen(rgbcolor, final_y, initial_x, final_y, final_x, thickness, matrix);
}

void Graphics::circle(const rgbColor &rgbcolor, int initial_x, int initial_y,
                                int final_x, int final_y, int thickness, rgbMatrix matrix)
{
    int radius = std::sqrt(std::pow(initial_x-final_x, 2)+std::pow(initial_y-final_y, 2));

    for (int i = 0; i < matrix.get_Width(); ++i) {
        for (int j = 0; j < matrix.get_Height(); ++j) {
            if((int) std::pow((i-initial_x), 2)+std::pow((j-initial_y), 2) <= (int) std::pow(radius, 2) && (int) std::pow((i-initial_x), 2)+std::pow((j-initial_y), 2) >= (int) std::pow(radius-1, 2)) {
                draw_WithPencil(rgbcolor, i, j, thickness, matrix);
            }
        }
    }
}
