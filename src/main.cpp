#include <iostream>
#include "BmpImage.h"
#include "BmpImage.cpp"
#include "rgbMatrix.h"
#include "rgbMatrix.cpp"


int main() {
	std::cout << "Hello, BMP!" << std::endl;

	int w =  300;
	int h = 400;

	rgbMatrix *rgb = new rgbMatrix(w, h);

	//Se crea una imagen y se exporta al disco

	rgb->whiteCanvas();

	rgb->CreateRgbArray();

	int size = rgb->get_rgbArraySize();

	BmpImage *defaultImage = new BmpImage("Pagina_en_Blanco", rgb->get_Width(), rgb->get_Height(), rgb->get_rgbArray(), size);

	// se estrae una imagen del disco para que se pueda usar en memoria

	BmpImage *fromDisc = new BmpImage("in.bmp");

	unsigned char* imgData = fromDisc->getDataArray();

	rgbMatrix *outImage = new rgbMatrix(fromDisc->getDataArray(), fromDisc->get_Height(), fromDisc->get_Width());

	outImage->rotate180();

	outImage->CreateRgbArray();

	int size2 = outImage->get_rgbArraySize();

	BmpImage *ReadImage = new BmpImage("out", outImage->get_Width(), outImage->get_Height(), outImage->get_rgbArray(), size2);
	
	
	return 0;
}
 