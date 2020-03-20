#include "pch.h"
#include "complex.h"
#include <cmath>
#include <iostream>

using namespace std;

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

void Complex::show_compl() {
	//de la show_complex, doar arata forma lui

	cout << this->imag << 'i' << " + " << this->real << '\n';
}

double Complex::abs(){
	//radacina/modulul unui numar complex
	//e nevoie de ea si la show_expo

	return sqrt(this->real * this->real + this->imag * this->imag);
}

void Complex::show_expo() {
	//arata/calculeaza forma eponentiala a numarului complex

	double r = this->abs();
	double a, pi = 3.1415;

	if (this->real == 0)
	{
		if (this->imag > 0)
			a = pi / 2;
		else
			a = -pi / 2;
	}
	else
		if (this->real > 0)
			a = atan(this->imag / this->real);
		else
			a = atan(this->imag / this->real) + pi;

	cout << r << " * e^( i*" << a << " )";
}

Complex Complex::quot(Complex x)
{
	//functie ce imparte 2 numere complexe
	if (x.real == 0 || x.imag == 0)
	{
		exception div_by_zero;
		throw div_by_zero;
	}

	double r = (this->real * x.real + this->imag * x.imag), i = (this->imag * x.real - this->real * x.imag);
	r /= (x.real * x.real + x.imag * x.imag);
	i /= (x.real * x.real + x.imag * x.imag);
	return Complex(r, i);

}

Complex Complex::mul(Complex x)
{ //functie care returneaza inmultirea a doua numere complexe
	return Complex(this->real * x.real - this->imag * x.imag, this->imag * x.real + this->real * x.imag);
}

Complex Complex::add(Complex x)
{ //functie care returneaza adunarea a doua numere complexe
	return Complex(this->real + x.real, this->imag + x.imag);
}

Complex Complex::polar_form()
{ //functie care calculeaza si returneaza forma polara a unui nr complex
	double r = this->abs(), a, PI = 3.1415926;

	//calculeaza forma polara
	if (!this->real)
	{
		if (this->imag > 0)
			a = PI / 2;
		else
			a = -PI / 2;
	}
	else
		if (this->real > 0)
			a = atan(this->imag / this->real);
		else
			a = atan(this->imag / this->real) + PI;

	//partea imaginara si reala a formei polare
	double Nreal = r * cos(a), Nimag = r * sin(a);
	return Complex(Nreal, Nimag);
}