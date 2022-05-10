#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "bmp.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

class Image {

public:
	/*
		accessors
	*/
	LONG getWidth() {
		return width;
	}

	LONG getHeight() {
		return height;
	}

	/*
		utility methods
	*/

	void generate(LONG _width, LONG _height) {
		width = _width;
		height = _height;

		// allocate memory for arrays
		data = new RGBTRIPLE * [height];
		for (int i = 0; i < height; i++) {
			data[i] = new RGBTRIPLE[width];
		}
	}

	void clear() {
		for (int i = 0; i < height; i++) {
			data[i] = nullptr;
		}
		data = nullptr;

		// reset properties
		width = 0;
		height = 0;
	}

	bool inBounds(int x, int y) {
		return x < width && y < height;
	}

	bool setPixel(int x, int y, BYTE r, BYTE g, BYTE b) {
		if (!inBounds(x, y)) {
			return false;
		}
		data[y][x] = { b, g, r };
		return true;
	}

	bool setPixel(int x, int y, double r, double g, double b) {
		return setPixel(x, y,
			(BYTE)(r * 255 + 0.5),
			(BYTE)(g * 255 + 0.5),
			(BYTE)(b * 255 + 0.5)
		);
	}

	/*
		input/output
	*/

    RGBTRIPLE getColor(int x, int y){
        return data[x][y];
    }

    void Read(const char* path)
{
    std::ifstream f;
    f.open(path, std::ios::in | std::ios::binary);

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

    width = informationHeader[4] + (informationHeader[5] << 8) + (informationHeader[6] << 16) + (informationHeader[7] << 24);
    height = informationHeader[8] + (informationHeader[9] << 8) + (informationHeader[10] << 16) + (informationHeader[11] << 24);

    data[width][height];

    const int paddingAmount = ((4 - (width * 3) % 4) % 4);


    for (int y = 0; y < height; y++)
    {
        for (int x = 0 ; x < width ; x++)
        {
            unsigned char color[3]; 
            f.read(reinterpret_cast<char*>(color),3);
            data[x][y].rgbtRed = static_cast<float>(color[2])/255.0f;
            data[x][y].rgbtGreen = static_cast<float>(color[1])/255.0f;
            data[x][y].rgbtBlue = static_cast<float>(color[0])/255.0f;

        }
        f.ignore(paddingAmount);
    }

    f.close();
    std::cout << "File read "<< std::endl;
}
	
	void Export(const char* path){

    std::ofstream f;
    f.open(path, std::ios::out | std::ios::binary);

    if(!f.is_open())
    {
        std::cout<<"File could not be open\n";
        return;
    }

    unsigned char bmpPad[3] ={0,0,0};
    const int paddingAmount = ((4 - (width* 3) % 4) % 4);
    const int fileHeaderSize = 14;
    const int informationHeaderSize = 40;
    const int fileSize = fileHeaderSize + informationHeaderSize + width*height + paddingAmount*height;


    unsigned char fileHeader[fileHeaderSize];

    // File type
    fileHeader[ 0] = 'B';
    fileHeader[ 1] = 'M';
    //File size
    fileHeader[ 2] = fileSize;
    fileHeader[ 3] = fileSize >>  8;
    fileHeader[ 4] = fileSize >> 16;
    fileHeader[ 5] = fileSize >> 24;
    //Comprension
    fileHeader[ 6] = 0;
    fileHeader[ 7] = 0;
    fileHeader[ 8] = 0;
    fileHeader[ 9] = 0;
    fileHeader[10] = fileHeaderSize + informationHeaderSize;

    unsigned char informationHeader[informationHeaderSize];

    //Header Size
    informationHeader[ 0] = informationHeaderSize;
    //from 0 to 3 are cero
    informationHeader[ 1] = 0;
    informationHeader[ 2] = 0;
    informationHeader[ 3] = 0;
    //image width
    informationHeader[ 4] = width;
    informationHeader[ 5] = width >>  8;
    informationHeader[ 6] = width >> 16;
    informationHeader[ 7] = width >> 24;

    // image height 
    informationHeader[ 8] = height;
    informationHeader[ 9] = height >>  8;
    informationHeader[10] = height >> 16;
    informationHeader[11] = height >> 24;

    //planes
    informationHeader[12] = 1;
    informationHeader[13] = 0;
    informationHeader[14] = 24;
    informationHeader[15] = 0;
    
    informationHeader[16] = 0;
    informationHeader[17] = 0;
    informationHeader[18] = 0;
    informationHeader[19] = 0;


    informationHeader[20] = 0;
    informationHeader[21] = 0;
    informationHeader[22] = 0;
    informationHeader[23] = 0;


    informationHeader[24] = 0;
    informationHeader[25] = 0;
    informationHeader[26] = 0;
    informationHeader[27] = 0;


    informationHeader[28] = 0;
    informationHeader[29] = 0;
    informationHeader[30] = 0;
    informationHeader[31] = 0;


    informationHeader[33] = 0;
    informationHeader[34] = 0;
    informationHeader[35] = 0;
    informationHeader[36] = 0;

    informationHeader[37] = 0;
    informationHeader[38] = 0;
    informationHeader[39] = 0;


    f.write(reinterpret_cast<char*>(fileHeader), fileHeaderSize);
    f.write(reinterpret_cast<char*>(informationHeader), informationHeaderSize);


    for( int y = 0; y < height; y++){

        for ( int x = 0; x < width; x++){
            unsigned char r = static_cast<unsigned char>(getColor(x,y).rgbtRed*255.0f); 
            unsigned char g = static_cast<unsigned char>(getColor(x,y).rgbtGreen*255.0f); 
            unsigned char b = static_cast<unsigned char>(getColor(x,y).rgbtBlue*255.0f); 

            unsigned char color[] = {b,g,r};
            f.write(reinterpret_cast<char*>(color),3);
        }
        f.write(reinterpret_cast<char*>(bmpPad), paddingAmount);
    }

    f.close();

    std::cout<<"File Created\n";

}

	void scale(float f) {
		horizontalScale(f);
		verticalScale(f);
	}

	void scale(float fx, float fy) {
		horizontalScale(fx);
		verticalScale(fy);
	}

	void horizontalScale(float f) {
		if (f == 1.0f) {
			return;
		}

		// update properties
		width *= f;

		// allocate new array
		RGBTRIPLE** newData = new RGBTRIPLE * [height];
		for (int i = 0; i < height; i++) {
			newData[i] = new RGBTRIPLE[width];
		}

		// load data into new array
		for (int row = 0; row < height; row++) {
			for (int newi = 0, oldi = 0;
				newi < width;
				newi++, oldi++) {
				if (f < 1.0f) {
					// skip cols
					newData[row][newi] = data[row][oldi];
					oldi += 1 / f - 1;
				}
				else {
					// copy cols
					for (int j = 0; j < f; j++) {
						newData[row][newi++] = data[row][oldi];
					}
					newi--;
				}
			}
		}

		// set data
		data = newData;
	}

	void verticalScale(float f) {
		if (f == 1.0f) {
			return;
		}

		// update properties
		height *= f;

		// allocate new array
		RGBTRIPLE** newData = new RGBTRIPLE * [height];
		for (int i = 0; i < height; i++) {
			newData[i] = new RGBTRIPLE[width];
		}

		// load new data
		for (int newi = 0, oldi = 0;
			newi < height;
			newi++, oldi++) {
			if (f < 1.0f) {
				// skip rows
				newData[newi] = data[oldi];
				oldi += 1 / f - 1;
			}
			else {
				// copy rows
				for (int j = 0; j < f; j++) {
					newData[newi++] = data[oldi];
				}
				newi--;
			}
		}

		// set new data
		data = newData;
	}

	/*
		transformations - reflections
	*/

	// reflect across x axis (vertically)
	void reflectX() {
		for (int i = 0; i < height / 2; i++) {
			// make copy of row
			RGBTRIPLE* tmp = data[i];
			data[i] = data[height - 1 - i];
			data[height - 1 - i] = tmp;
		}
	}

	// reflect across y axis (horizontally)
	void reflectY() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width / 2; j++) {
				// swap pixels
				RGBTRIPLE tmp = data[i][j];
				data[i][j] = data[i][width - 1 - j];
				data[i][width - 1 - j] = tmp;
			}
		}
	}

	// reflect across line y = x
	void reflectXY() {
		// update properties
		LONG oldWidth = width;

		width = height;
		height = oldWidth;

		// allocate new array
		RGBTRIPLE** newData = new RGBTRIPLE * [height];
		for (int i = 0; i < height; i++) {
			newData[i] = new RGBTRIPLE[width];
		}

		// load new data
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				newData[i][j] = data[j][i];
			}
		}

		// set new data
		data = newData;
	}

	/*
		transformations - rotations
	*/

	void rotate90CW() {
		reflectXY();
		reflectX();
	}

	void rotate90CCW() {
		reflectXY();
		reflectY();
	}

	void rotate180() {
		rotate90CW();
		rotate90CW();
	}

	/*
		transformations - cropping
	*/

	void crop(int left, int right, int top, int bottom) {
		width -= left + right;
		height -= top + bottom;

		// allocate new array
		RGBTRIPLE** newData = new RGBTRIPLE * [height];
		for (int i = 0; i < height; i++) {
			newData[i] = new RGBTRIPLE[width];
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				newData[i][j] = data[top + i][left + j];
			}
		}

		// set new data
		data = newData;
	}

private:
	LONG width;
	LONG height;

	RGBTRIPLE **data;
};

#endif