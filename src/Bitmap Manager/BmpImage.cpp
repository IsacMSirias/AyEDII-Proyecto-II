#include "BmpImage.h"

using namespace std;

BmpImage::BmpImage(std::string imgName, int width, int height, unsigned char *pixelArray, int pixelArraySize)
{
    this->height = height;
    this->width = width;
    bmpPixelArray = pixelArray;

    generateBitmapImage(imgName, pixelArraySize);
}

BmpImage::BmpImage(std::string imgPath)
{
    this->name = imgPath;
    read();
}
void BmpImage::read()
{
    std::ifstream f;
    f.open(this->name, std::ios::in | std::ios::binary);

    if (!f.is_open())
    {
        std::cout << "File could not be open\n";
        return;
    }
    unsigned char fileHeader[FILE_HEADER_SIZE];
    f.read(reinterpret_cast<char *>(fileHeader), FILE_HEADER_SIZE);

    if (fileHeader[0] != 'B' || fileHeader[1] != 'M')
    {
        std::cout << "The specified path is not a bitmap image" << std::endl;
        f.close();
        return;
    }

    unsigned char informationHeader[INFO_HEADER_SIZE];
    f.read(reinterpret_cast<char *>(informationHeader), INFO_HEADER_SIZE);

    int fileSize = fileHeader[2] + (fileHeader[3] << 8) + (fileHeader[4] << 16) + (fileHeader[5] << 24);

    width = informationHeader[4] + (informationHeader[5] << 8) + (informationHeader[6] << 16) + (informationHeader[7] << 24);
    height = informationHeader[8] + (informationHeader[9] << 8) + (informationHeader[10] << 16) + (informationHeader[11] << 24);

    int pixelArraySize = width * height * (BITS_PER_PIXEL / 8);
    paddingBytes = (4 - (width * BITS_PER_PIXEL / 8) % 4) % 4;
    bmpPixelArray = (unsigned char *)malloc(pixelArraySize);

    int c = 0;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            unsigned char color[3];
            f.read(reinterpret_cast<char *>(color), 3);
            bmpPixelArray[c] = static_cast<float>(color[2]) ;
            bmpPixelArray[c + 1] = static_cast<float>(color[1]) ;
            bmpPixelArray[c + 2] = static_cast<float>(color[0]) ;
            c = c + 3;
        }
        f.ignore(paddingBytes);
    }

    

    f.close();
    std::cout << "File imported read " << std::endl;
}
void BmpImage::generateBitmapImage(std::string imgName, int pixelArraySize)
{
    std::string fileName = imgName + ".bmp";

    FILE *imageFile = fopen(fileName.c_str(), "wb");

    unsigned char *fileHeader = createBitmapFileHeader();
    unsigned char *infoHeader = createBitmapInfoHeader();

    fwrite(fileHeader, 1, FILE_HEADER_SIZE, imageFile);
    fwrite(infoHeader, 1, INFO_HEADER_SIZE, imageFile);
    fwrite(bmpPixelArray, 1, pixelArraySize, imageFile);

    cout << "Bitmap Image created succesfully!" << endl;
}

unsigned char *BmpImage::createBitmapFileHeader()
{
    int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (width * height * (BITS_PER_PIXEL / 8));

    static unsigned char fileHeader[] = {
        'B', 'M',   
        0, 0, 0, 0,  
        0, 0, 0, 0,  
        54, 0, 0, 0, 
    };

    fillFourBytes(fileHeader, fileSize, 2);

    return fileHeader;
}

unsigned char *BmpImage::createBitmapInfoHeader()
{
    int imageSize = height * width * (BITS_PER_PIXEL / 8);

    static unsigned char infoHeader[] = {
        40, 0, 0, 0,  0, 0, 0, 0,0, 0, 0, 0,   
        1, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        19, 11, 0, 0,19, 11, 0, 0,0, 0, 0, 0,  
        0, 0, 0, 0,   
    };

    fillFourBytes(infoHeader, width, 4);
    fillFourBytes(infoHeader, height, 8);
    fillFourBytes(infoHeader, imageSize, 20);

    return infoHeader;
}

void BmpImage::fillFourBytes(unsigned char *array, int value, int initByte)
{
    for (int i = initByte; i < initByte + 4; i++)
    {
        array[i] = (unsigned char)(value >> (8 * (i - initByte)));
    }
}

int BmpImage::get_Height()
{
    return this->height;
}
int BmpImage::get_Width()
{
    return this->width;
}
unsigned char *BmpImage::getDataArray()
{
    return this->bmpPixelArray;
}