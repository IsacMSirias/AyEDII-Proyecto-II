#include "Graphics.h"



 void Graphics::draw_WhitPencil(const rgbColor &rgbColor, int x, int y , int thickness, rgbMatrix matrix){
    
    int maxThickness = thickness -1;

    for (int i = x - maxThickness; i <= x + maxThickness; i++){

        for (int j = y-maxThickness; j <= y + maxThickness; j++){
            
            matrix.setColor(rgbColor, i, j);

        }   
    }
 }

    
void Graphics::draw_WhitPen(const rgbColor &rgbColor, int initial_y, int initial_x, int final_y, 
                                        int final_x, int thickness, rgbMatrix matrix){

    if (final_x - initial_x == 0){
        if (final_y < initial_y){

            int varTemp = initial_y;
            initial_y = final_y;
            final_y = varTemp;
        }
        for (int i = initial_y; i <= final_y; i++){
            draw_WhitPencil(rgbColor, i, initial_x, thickness, matrix);
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
                draw_WhitPencil(rgbColor, new_y, i, thickness, matrix);
            }else{
                if (m >= 0){
                    for (int j = old_y + 1; j <= new_y; j++){
                        draw_WhitPencil(rgbColor, j, i, thickness, matrix);
                    }
                }else{
                    for (int j = old_y - 1; j >= new_y; j--){
                        draw_WhitPencil(rgbColor, j, i, thickness, matrix);
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
    
    std::cout<< "Gray Scale Filter aply"<< std::endl;
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
    
    std::cout<< "Negative Filter aply"<< std::endl;
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
    
    std::cout<< "extra  Filter aply"<< std::endl;
}


void Graphics:: experimentalFilter2(rgbMatrix matrix){

    for (int x = 0; x < matrix.get_Height(); x++){

        for (int y = 0; y < matrix.get_Width(); y++){

            rgbColor tempRGB =  matrix.getColor(x,y);
            float new_R = 111* tempRGB.r;
            float new_G = 222*tempRGB.g;
            float new_B = 111*tempRGB.b;
            matrix.setColor(rgbColor(new_R, new_G, new_B), x, y);
        }
        
    }
    
    std::cout<< "extra  Filter aply"<< std::endl;
}\


void Graphics::paintFill(const rgbColor &colorPicked, const rgbColor &selectedColor, int x, int y, rgbMatrix matrix){

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

void Graphics::triangle(const rgbColor &rgbcolor, int initial_x, int initial_y, int final_x, 
                                                int final_y, int thickness, rgbMatrix matrix)
{
    int dx = (final_x - initial_x) / 2;
    draw_WhitPen(rgbcolor, initial_y, initial_x + dx, final_y, final_x, thickness, matrix);
    draw_WhitPen(rgbcolor, initial_y, initial_x + dx, final_y, initial_x, thickness, matrix);
    draw_WhitPen(rgbcolor, final_y, initial_x, final_y, final_x, thickness, matrix);
}


void Graphics::square(const rgbColor &rgbcolor, int initial_x, int initial_y, int final_x, 
                                            int final_y, int thickness,rgbMatrix matrix){
    int dx = (final_x - initial_x);
    int dy = (final_y - initial_y);
    int X_length = min(abs(dx), abs(dy));
    int Y_length = X_length;
        if (dx < 0){
            X_length = (X_length * -1);
             }
            if (dy < 0){
                Y_length = (Y_length * -1);
              }
                draw_WhitPen(rgbcolor, initial_y, initial_x, initial_y, initial_x + X_length, thickness, matrix);
                draw_WhitPen(rgbcolor, initial_y, initial_x, initial_x + Y_length, initial_x, thickness, matrix);
                draw_WhitPen(rgbcolor, initial_y + Y_length, initial_x, initial_y + Y_length, initial_x + X_length, thickness, matrix);
                draw_WhitPen(rgbcolor, initial_y, initial_x + X_length, initial_y + Y_length, initial_x + X_length, thickness, matrix);
}

void Graphics::elipse(const rgbColor &rgbcolor, int initial_x, int initial_y, 
                                int final_x, int final_y, rgbMatrix matrix){   

    int x = min(initial_x,final_x); int y = min(initial_y,final_y);
    int dx = abs(final_x- initial_x);int dy = abs(final_y-initial_y); 
    int covertice = x + dx/2; int vertice = y + dy/2;
    int Eje_Menor = dx*dx/4; int Eje_Mayor = dy*dy/4;

    for (float focus = (float)x; focus <= x + dx; focus+=0.001){
        
        float centerInitial_y = (float)sqrt((1-(float)((focus-covertice)*(focus-covertice))/Eje_Menor)*Eje_Mayor)+vertice;
        float centerFinal_y = -1*(float)sqrt((1-(float)((focus-covertice)*(focus-covertice))/Eje_Menor)*Eje_Mayor)+vertice;
            matrix.setColor(rgbcolor, centerInitial_y, focus);
            matrix.setColor(rgbcolor, centerFinal_y, focus);
    }
    
        
}

void Graphics::circle(const rgbColor &rgbcolor, int initial_x, int initial_y, int final_x, int final_y, rgbMatrix matrix) {
    
    int dx = (final_x-initial_x); int dy = (final_y-initial_y);
    int lenght = min(abs(dx),abs(dy));
    int horizontalDiameter= min(initial_x,final_x); int  verticalDiameter = min(initial_y,final_y);
    int new_x = horizontalDiameter + lenght;
    int new_y = verticalDiameter + lenght;
        elipse(rgbcolor,horizontalDiameter,verticalDiameter,new_x,new_y, matrix);
}