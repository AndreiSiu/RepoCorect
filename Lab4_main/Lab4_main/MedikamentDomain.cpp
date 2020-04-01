#include "pch.h"
#include "MedikamentDomain.h"


MedikamentDomain::MedikamentDomain()
{
}

MedikamentDomain::MedikamentDomain(std::string name, double konz, int menge,
	double preis) {
	this->name = name;
	this->konzentration = konz;
	this->menge = menge;
	this->preis = preis;

}

void MedikamentDomain::SetName(std::string x) {
	this->name = x;
}

void MedikamentDomain::SetKonzentration(double konz) {
	this->konzentration = konz;
}

void MedikamentDomain::SetMenge(int menge) {
	this->menge = menge;
}

void MedikamentDomain::SetPreis(double preis) {
	this->preis = preis;
}

std::string MedikamentDomain::GetName() {
	return this->name;
}

double MedikamentDomain::GetKonzentration() {
	return this->konzentration;
}

int MedikamentDomain::GetMenge() {
	return this->menge;
}

double MedikamentDomain::GetPreis() {
	return this->preis;
}

MedikamentDomain::~MedikamentDomain()
{
}
