#include "pch.h"
#include "complex.h"
#include <iostream>

Complex::Complex(double imag, double real) {

	this->imag = imag;
	this->real = real;
}

double Complex::GetReal() {
	//Getter pentru variabila privata real
	return this->real;
}

double Complex::GetImag() {
	//Getter pentru variabila privata imaginara
	return this->imag;
}

void Complex::SetImag(double imag)
{ //Setter pentru var privata imaginara
	this->imag = imag;
}

void Complex::SetReal(double real)
{ //Setter pentru var privata real
	this->real = real;
}