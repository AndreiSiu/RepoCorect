#pragma once
#include "MedikamentDomain.h"
#include <vector>
class MedikamentRepo
{
private:
	friend class MedikamentController;

	int current_index = -1;

	//Ein Vektor fur die Undo/Redo Methode
	std::vector< std::vector<MedikamentDomain> > undo_redo;

	//Vektor fur die medikamente
	std::vector<MedikamentDomain> medikamente;

public:

	MedikamentRepo();

	//Zeigt die Medikamente auf den Bildschirn
	void show_medikamente();

	~MedikamentRepo();
};

