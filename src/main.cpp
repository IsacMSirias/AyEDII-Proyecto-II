#include <iostream>
#include "Bitmap Manager/BmpImage.h"
#include "Bitmap Manager/BmpImage.cpp"
#include "Data Structure/rgbMatrix.h"
#include "Data Structure/rgbMatrix.cpp"
#include "Graphic Elements/Graphics.h"
#include "Graphic Elements/Graphics.cpp"


int main() {
	std::cout << "Hello, BMP!" << std::endl;

	int w =  300;
	int h = 400;

	rgbMatrix *rgb = new rgbMatrix(w, h);
	Graphics *graphics = new Graphics();

	//Se crea una imagen y se exporta al disco

	rgb->whiteCanvas();

	//graphics->draw_WhitPen(rgbColor(111,222, 111), 80,60, 40, 22, 1, *rgb);
	
	graphics->draw_WhitPen(rgbColor(0, 0, 0), 10, 10, 200, 200, 4, *rgb);

	rgb->CreateRgbArray();

	int size = rgb->get_rgbArraySize();

	BmpImage *defaultImage = new BmpImage("Pagina_en_Blanco", rgb->get_Width(), rgb->get_Height(), rgb->get_rgbArray(), size);

	// se estrae una imagen del disco para que se pueda usar en memoria

	BmpImage *fromDisc = new BmpImage("blackbuck.bmp");

	unsigned char* imgData = fromDisc->getDataArray();

	rgbMatrix *outImage = new rgbMatrix(fromDisc->getDataArray(), fromDisc->get_Height(), fromDisc->get_Width());

	//filter->negativeFilter(*outImage);
	//graphics->paintFill(outImage->getColor(140,140), rgbColor(255,0,0), 140,140, *outImage);
	
	
	outImage->CreateRgbArray();

	int size2 = outImage->get_rgbArraySize();

	BmpImage *ReadImage = new BmpImage("outfill", outImage->get_Width(), outImage->get_Height(), outImage->get_rgbArray(), size2);
	
	
	return 0;
}
 