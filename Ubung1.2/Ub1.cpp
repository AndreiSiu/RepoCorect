#include "pch.h"
#include<iostream>
#include "Ub1.h"

using namespace std;

int Prim(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i < n / 2 + 1; i++)
		if (n%i == 0)
			return false;
	return true;
}
void UB1_a()
{
	int n;
	cout << "n=" << ' ';
	cin >> n;
	for (int i = 0; i < n; i++)
		if (Prim(i))
			cout << i << ' ';
}
void UB1_b()
{
	int v[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int smax, ctmax, ct;
	smax = ctmax = ct = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i] > v[i - 1])
			ct++;
		if (ctmax < ct)
		{
			ctmax = ct;
			smax = i;
		}
		if (v[i] < v[i - 1])
			ct = 0;
	}
	for (int i = smax - ctmax; i < smax + 1; i++)
		cout << v[i] << ' ';
}

void schema1()
{
	int key;
	bool running = true;
	while (running) {
		cout << "\n1.Ubung1_a\n2.Ubung1_b\n0.Exit";
		cout << "\nWahle eine Option: ";
		cin >> key;
		if (key == 1) {
			UB1_a();
		}
		if (key == 2) {
			UB1_b();
		}
		if (key == 0) {
			running = false;
		}

	}
}
