#pragma once
#include "MedikamentRepo.h"
class MedikamentController
{
private:

	int size;

	void Change();

public:
	MedikamentRepo repo;

	MedikamentController();

	void addMedikament(MedikamentDomain m);

	void deleteMedikament(MedikamentDomain m);

	void Kette();

	void Knapp_Menge(int x);

	void Preis();

	void Undo();

	void Redo();

	~MedikamentController();
};

