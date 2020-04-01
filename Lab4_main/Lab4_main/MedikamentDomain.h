#pragma once
#include <iostream>
#include <string>
class MedikamentDomain
{
private:
	std::string name;
	double konzentration;
	int menge;
	double preis;

public:
	MedikamentDomain();

	MedikamentDomain(std::string name, double konz, int menge, 
		double preis);

	void SetName(std::string x);

	void SetKonzentration(double konz);

	void SetMenge(int menge);

	void SetPreis(double preis);

	std::string GetName();

	double GetKonzentration();

	int GetMenge();

	double GetPreis();

	~MedikamentDomain();
};

