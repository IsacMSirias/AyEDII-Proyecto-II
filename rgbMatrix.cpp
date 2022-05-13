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

int rgbMatrix::getHeight(){

    return m_height;
}

int rgbMatrix::getWidth(){

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

void rgbMatrix::read(const char* file){

    std::ifstream f;
    f.open(file, std::ios::in | std::ios::binary);

    if(!f.is_open()){
        std::cout<<"File could not be open\n";
        return;
    }

    const int fileHeaderSize = 14;
    const int informationHeaderSize = 40;

    unsigned char fileHeader[fileHeaderSize];
    f.read(reinterpret_cast<char*>(fileHeader),fileHeaderSize);

    if(fileHeader[0] != 'B' || fileHeader[1] != 'M')
    {
        std::cout<< "The specified path is not a bitmap image"<< std::endl;
        f.close();
        return;
    }

    unsigned char informationHeader[informationHeaderSize];
    f.read(reinterpret_cast<char*>(informationHeader),informationHeaderSize);

    int fileSize = fileHeader[2] + (fileHeader[3] << 8) + (fileHeader[4] << 16) +(fileHeader[5] << 24);

    m_width = informationHeader[4] + (informationHeader[5] << 8) + (informationHeader[6] << 16) + (informationHeader[7] << 24);
    m_height = informationHeader[8] + (informationHeader[9] << 8) + (informationHeader[10] << 16) + (informationHeader[11] << 24);

    matrix[m_width][m_height];

    const int paddingAmount = ((4 - (m_width * 3) % 4) % 4);


    for (int y = 0; y < m_height; y++)
    {
        for (int x = 0 ; x < m_width ; x++)
        {
            unsigned char color[3]; 
            f.read(reinterpret_cast<char*>(color),3);
            matrix[x][y].r = static_cast<float>(color[2])/255.0f;
            matrix[x][y].g = static_cast<float>(color[1])/255.0f;
            matrix[x][y].b = static_cast<float>(color[0])/255.0f;

        }
        f.ignore(paddingAmount);
    }

    f.close();
    std::cout << "File read "<< std::endl;

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
