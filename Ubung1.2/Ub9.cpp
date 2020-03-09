#include "Ub9.h"
#include "pch.h"
#include <iostream>

using namespace std;


int Potenz(int x, int power) {
	int aux = x, var = x;
	while (power != 1) {
		aux = aux * var;
		power--;
	}
	return aux;

}


int Reihe(int v[100], int n, int& mx) {
	int ct, ok, j;
	ct = 0;
	ok = 0;
	for (int i = 0; i < n; i++) {
		if ((v[i] >= 0 && v[i + 1] < 0) || v[i] < 0 && v[i + 1] >= 0) {
			ct++;
			ok = 1;
		}
		else {
			ok = 0;
		}
		if (mx < ct && ok == 0) {
			mx = ct;
			ct = 0;
			j = i - mx;
		}
	}
	return j;
}


void Show_Ub9() {
	int key;
	bool running = true;
	while (running) {
		cout << "\n1.a) \n2.b) \n0.Back";
		cout << "\nWahle eine Option: ";
		cin >> key;
		if (key == 1) {
			cout<<'\n'<<Potenz(2, 3)<<'\n';
		}
		if (key == 2) {
			int v[] = { 8, -3, -4, 0, -1, 2, -5, -7 }, mx = 0, n = 8;
			int poz = Reihe(v, n, mx);
			cout << "b)";
			while (mx != -1) {
				cout << v[poz] << ' ';
				poz++;
				mx--;
			}
			cout << '\n';
		}
		if (key == 0) {
			running = false;
		}

	}
}