#pragma once

class Complex {

private:
	//Declararea variabilelor
	double imag;
	double real;

public:
	//Aici scriem numele functiilor cu parametri lor si sa nu uitam de `;`
	Complex(double imag, double real);

	double GetReal();

	double GetImag();

	void SetImag(double imag);

	void SetReal(double real);

};
