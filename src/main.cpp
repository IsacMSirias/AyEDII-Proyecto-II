#include <iostream>
#include "image.hpp"

int main() {
	std::cout << "Hello, BMP!" << std::endl;

	Image img;
    img.generate(400,400);
	
    img.Read("in.bmp");
	// img.reflectX();
	img.Export("out.bmp");

	img.clear();

	return 0;
}
