#include "rgbMatrix.h"

using namespace std;

rgbColor::rgbColor()
    : r(255), g(255), b(255)
{
}

rgbColor::rgbColor(float r, float g, float b)
    : r(r), g(g), b(b)
{
}


rgbMatrix::rgbMatrix(unsigned char* pixels_inMatrix, int height, int width){

    m_height = height;
    m_width = width;
    this->createMatrix();
    this->createMatrix_fromDiscImage(pixels_inMatrix);
    cout<<"Se escribio una nueva matriz a partir de los datos leidos"<<endl;


}
rgbMatrix::rgbMatrix(int width, int height){

    m_height = height;
    m_width = width;
    this->createMatrix();

}


void rgbMatrix::createMatrix(){

    this->matrix = new rgbColor *[m_height];
    for (int i = 0; i < m_height; i++)
    {
        this->matrix[i] = new rgbColor[m_width];
    }
}

int rgbMatrix::get_Height(){

    return m_height;
}

int rgbMatrix::get_Width(){

    return m_width;
}

void rgbMatrix::CreateRgbArray(){

    
    pixelSize = m_height * m_width * (BITS_PER_PIXEL / 8);
    paddingBytes = (4 - (m_width * BITS_PER_PIXEL / 8) % 4) % 4;
    std::cout << "Padding bytes: " << paddingBytes << std::endl;
    pixels_inMatrix = (unsigned char *)malloc(pixelSize + paddingBytes * m_height);
    int c = 0;
    for (int i = m_height - 1; i >= 0; i--)
    {

        for (int j = 0; j < m_width; j++)
        {

            pixels_inMatrix[c] = matrix[i][j].b;
            pixels_inMatrix[c + 1] = matrix[i][j].g;
            pixels_inMatrix[c + 2] = matrix[i][j].r;
        
            c = c + 3;
        }
        c += paddingBytes;
    }
}

void rgbMatrix::createMatrix_fromDiscImage(unsigned char* pixels_inMatrix) {
    int m = 0;
    for (int x = m_height - 1; x >= 0; x--) {
        for (int y = 0; y < m_width; y++)
        {
            float r = pixels_inMatrix[m];
            float g = pixels_inMatrix[m + 1];
            float b = pixels_inMatrix[m + 2];
            setColor(rgbColor(r,g,b), x, y);
            m = m + 3;
        }
    }
}


int rgbMatrix::get_rgbArraySize()
{
    int size = pixelSize + paddingBytes * m_height;
    return size;
}


unsigned char *rgbMatrix::get_rgbArray()
{
    return pixels_inMatrix;
}

void rgbMatrix::whiteCanvas()

{
    for (int x = 0; x < m_height; x++)
    {
        for (int y = 0; y < m_width; y++)
        {
            setColor(rgbColor(), x, y);
        }
    }
}


rgbColor rgbMatrix::getColor(int x, int y){
    
    return matrix[x][y];

}
void rgbMatrix::setColor(const rgbColor &color, int x, int y){

    matrix[x][y].r = color.r;
    matrix[x][y].g = color.g;
    matrix[x][y].b = color.b;
   
}

void rgbMatrix::clearMatrix()
{
    for (int i = 0; i < m_height; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}


void rgbMatrix::reflectX(){

    for (int i = 0; i < m_height / 2; i++) {
			// make copy of row
			rgbColor* tmp = matrix[i];
			matrix[i] = matrix[m_height - 1 - i];
			matrix[m_height - 1 - i] = tmp;
		}
	}


void rgbMatrix::reflectY(){

    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width / 2; j++) {
            // swap pixels
            rgbColor tmp = matrix[i][j];
            matrix[i][j] = matrix[i][m_width - 1 - j];
            matrix[i][m_width - 1 - j] = tmp;
        }
    }

}

void rgbMatrix::reflectXY(){
    
    int oldWidth = m_width;

    m_width = m_height;
    m_height = oldWidth;


    rgbColor** newMatrix = new rgbColor * [m_height];
    for (int i = 0; i < m_height; i++) {
        newMatrix[i] = new rgbColor[m_width];
    }


    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width; j++) {
            newMatrix[i][j] = matrix[j][i];
        }
    }


    matrix = newMatrix;
}


void rgbMatrix::rotate90CW(){
    reflectXY();
	reflectX();
}


void rgbMatrix::rotate180(){
    rotate90CW();
	rotate90CW();
}
