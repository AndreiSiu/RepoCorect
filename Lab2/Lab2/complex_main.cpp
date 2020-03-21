#include "pch.h"
#include "complex.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void show_vector(vector<Complex> c, int anzahl) {

	for (int i = 0; i < anzahl; i++) {
		c[i].show_compl();
	}
}

int main()
{
	/*Complex c = Complex(2, 3);
	c.show_compl();
	c.show_expo();
	cout << '\n';*/

	vector<Complex> c; //pentru a crea un vector care sa contina elemente de tip complex

	ifstream f("zahlen.txt"); ///iau elementele din fisierul "zahlen.txt"
	double x, y;
	int anzahl = 0;
	while (f >> x) {
		anzahl++;     ///numar nr de elemente ce se adauga in vector
		f >> y;
		c.push_back(Complex(x, y));
	}
	f.close();

	show_vector(c, anzahl);
	cout << '\n';

	//Sortarea vectorului dupa modulul numerelor
	for (int i = 0; i < anzahl; i++) {

		for (int j = i; j < anzahl; j++)
		{
			if (c[i].abs() > c[j].abs()) {
				Complex t = c[i];
				c[i] = c[j];
				c[j] = t;
			}
		}
	}

	//vectorul dupa sortare
	show_vector(c, anzahl);

	Complex sum = Complex(0,0);
	for (int i = 0; i < anzahl; i++) {
		sum = sum.add(c[i]);
	}
	cout << "Die Summe der complexe Zahlen ist: ";
	sum.show_compl();

	cout << "Fertig";
	system("pause");
	return 0;
}

