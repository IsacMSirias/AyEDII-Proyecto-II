/**
 * @file rgbMatrix.cpp
 * @author Isac Marin Sirias, Daniel Cob Beirute, Abraham Venegaz 
 * @brief La  presente clase tiene como funcion manejar todo lo relacionado
 * con la generacion de una matriz de pixeles
 * @version 0.1
 * @date 2022-05-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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

/**
 * @brief Constructor que permite generar una matriz en base a un archivo externo
 * 
 * @param pixels_inMatrix todos los pixeles que estan dentro de la matrix
 * @param height el alto de la matrix
 * @param width el ancho de la matrix
 */
rgbMatrix::rgbMatrix(unsigned char* pixels_inMatrix, int height, int width){
    m_height = height;
    m_width = width;
    this->createMatrix();
    this->createMatrix_fromDiscImage(pixels_inMatrix);
    cout<<"Se escribio una nueva matriz a partir de los datos leidos"<<endl;


}

/**
 * @brief Constructor de una nueva matriz en base a sus dimensiones
 * 
 * @param width ancho de la matriz
 * @param height alto de la matriz
 */
rgbMatrix::rgbMatrix(int width, int height){
    m_height = height;
    m_width = width;
    this->createMatrix();

}

/**
 * @brief Metodo encargado de guardar memoria para la matriz de pixes utilizada
 * 
 */
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


/**
 * @brief Genera un arreglo unidimensional, con el fin fde que pueda ser utilizado a la hora
 * de exportar la imagen en un archivo bmp
 * 
 */
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

/**
 * @brief Metodo encargado de crear una matriz en base a la informacion proporcionada 
 * un array que fue creado en base a un archivo binario
 * 
 * @param pixels_inMatrix 
 */
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

/**
 * @brief Crea un canvas blanco en la matriz
 * 
 */
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

/**
 * @brief metodo que se encarga de que la matriz rote a 90 grados 
 * 
 */
void rgbMatrix::rotate90CW(){
    reflectXY();
	reflectX();
}

/**
 * @brief Metodo que se encarga de que la matriz rote a 180 grados.
 * 
 */
void rgbMatrix::rotate180(){
    rotate90CW();
	rotate90CW();
}
