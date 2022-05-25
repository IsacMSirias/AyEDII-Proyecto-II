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
	graphics->triangle(rgbColor(0,0,0),20,20, 299,300, 2, *rgb);
	graphics->square(rgbColor(111,222,111), 10,10, 190, 190, 2, *rgb);
	graphics->circle(rgbColor(0, 0, 255), 100, 100, 300, 300, *rgb);

	rgb->CreateRgbArray();

	int size = rgb->get_rgbArraySize();

	BmpImage *defaultImage = new BmpImage("Pagina_en_Blanco", rgb->get_Width(), rgb->get_Height(), rgb->get_rgbArray(), size);

	// se estrae una imagen del disco para que se pueda usar en memoria

	BmpImage *fromDisc = new BmpImage("blackbuck.bmp");

	unsigned char* imgData = fromDisc->getDataArray();

	rgbMatrix *outImage = new rgbMatrix(imgData, fromDisc->get_Height(), fromDisc->get_Width());

	graphics->experimentalFilter2(*outImage);
	//graphics->paintFill(outImage->getColor(140,140), rgbColor(255,0,0), 140,140, *outImage);
	
	outImage->CreateRgbArray();

	int size2 = outImage->get_rgbArraySize();

	BmpImage *ReadImage = new BmpImage("outfill", outImage->get_Width(), outImage->get_Height(), outImage->get_rgbArray(), size2);
	
	
	return 0;
}
 