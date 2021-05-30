#include <iostream>
#include "complex.h"
#include <cmath>
#include <fstream>
#include <vector>
#include "hsv2rgb.h"
#include <stdlib.h>

#define width 1200
#define height 1200

int main() {

    //burning ship fractal 
	int maxItr = 1000; //the maximum number of iterations
	char* colorOutput = (char *)malloc(3*width*height*sizeof(char));
	for (int row = 0; row < height; row++) { //cols
		for (int col = 0; col < width; col++) {  //rows
			complex z(0,0); //for burning ship, z0 = 0, so we can use the default constructor
			complex c(double(col)*(4/double(width))-2, double(row)*(4/double(height))-2); // c is initialized to coordinates
			int iter = 0; 
			std::vector<int> colorRGB;
			double h = 0;
			while ((z.real*z.real + z.imag*z.imag) < 4 && iter < maxItr) { //go through iterations
				//complex zabs(std::abs(z.real), std::abs(z.imag));  //burning ship
				complex zabs(z.real, z.imag);  //tricorn
				//complex zabs(z.real, z.imag);  //mandlebrot
				z = (zabs * zabs) + c;
				iter++;
			}
			if (iter == maxItr) { // did not diverge 
			//set color to black 
				colorRGB = { 0,0,0 };
			}
			else {
				h = log10(iter) * 50; //getting the hue
				colorRGB = hsv2rgb(h); //converting to rgb come back to this
				//colorRGB = { 0, 0, (int(fmod(h, 255))) };
				
			}

			char r = char(colorRGB[0]); //cast r, g, and b to char 
			char g = char(colorRGB[1]);
			char b = char(colorRGB[2]); 

			if (colorOutput!=NULL) {
				*(colorOutput + 3 * (col + row * width)) = r;
				*(colorOutput + 3 * (col + row * width) + 1) = g;
				*(colorOutput + 3 * (col + row * width) + 2) = b;
			}

		}
	}

	std::ofstream myfile("outputFractal.ppm", std::ios::binary);
	if (myfile.is_open()) {
		myfile << "P6 " <<  width << " " <<  height << " 255\n"; //header that format(color), width, height, max color
		myfile.write(colorOutput, 3 * width * height * sizeof(char));
		myfile.close();
	}
	else {
		std::cout << "failed to open" << std::endl;
	}



	free(colorOutput);
	return 0;
}