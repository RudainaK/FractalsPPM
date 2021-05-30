#pragma once

class complex {
public:
	double real;
	double imag;

	complex() { //default constructor 
		real = 0;
		imag = 0;
	}

	complex(double r, double i) { //constructor with args
		real = r;
		imag = i;
	}

	complex operator+(complex other) {
		complex n;
		n.real = this->real + other.real;
		n.imag = this->imag + other.imag;
		return n;
	}

	complex operator*(complex other) {
		complex n;
		n.real = (this->real) * (other.real) - (this->imag) * (other.imag);
		n.imag = (this->real) * (other.imag) + (other.real) * (this->imag);
		return n;
	}



};