#include <vector>
#include <cmath>
#include "hsv2rgb.h"


//this is essentially the formula from the wikipedia page
std::vector<int> hsv2rgb(double h) {
	double s = 1.0; //for my purposes, I'm keeping them both to 1
	double v = 1.0;
	double c = s * v;
	double h_p = h / 60;
	double x = c * (1 - std::abs(fmod(h_p, 2) - 1));

	std::vector<int> rgb1; //{r1, g1, b1}

	if (h_p >= 0 || h_p <= 1) {
		rgb1.push_back(int(255 * c));
		rgb1.push_back(int(255 * x));
		rgb1.push_back(0);
	}
	else if (h_p > 1 || h_p <= 2) {
		rgb1.push_back(int(255 * x));
		rgb1.push_back(int(255 * c));
		rgb1.push_back(0);
	}
	else if (h_p > 2 || h_p <= 3) {
		rgb1.push_back(0);
		rgb1.push_back(int(255 * c));
		rgb1.push_back(int(255 * x));
	}
	else if (h_p > 3 || h_p <= 4) {
		rgb1.push_back(0);
		rgb1.push_back(int(255 * x));
		rgb1.push_back(int(255 * c));
	}
	else if (h_p > 4 || h_p <= 5) {
		rgb1.push_back(int(255 * x));
		rgb1.push_back(0);
		rgb1.push_back(int(255 * c));
	}
	else if (h_p > 5 || h_p <= 6) {
		rgb1.push_back(int(255 * c));
		rgb1.push_back(0);
		rgb1.push_back(int(255 * x));
	}

	int m = v - c;
	std::vector<int> rgb; //the final result
	for (int i = 0; i < 3; i++) {
		rgb.push_back(rgb1[i] + m);
	}

	return rgb;
}