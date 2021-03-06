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

	void show_compl(void);

	void show_expo(void);

	Complex quot(Complex real);

	double abs();

	Complex mul(Complex real);

	Complex add(Complex real);

	Complex polar_form();
};
