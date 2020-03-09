#include "pch.h"
#include <iostream>
#include "Ub9.h"
#include "Ub1.h"
using namespace std;

int main()
{

	int key;
	bool running = true;
	while (running) {
		cout << "\n1.Ubung1\n2.Ubung9\n0.Exit";
		cout << "\nWahle eine Option: ";
		cin >> key;
		if (key == 1) {
			//pune aici!
		}
		if (key == 2) {
			Show_Ub9();
		}
		if (key == 0) {
			running = false;
		}
		
	}
	cout << "\nCeau!";
}
