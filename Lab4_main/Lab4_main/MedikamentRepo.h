#pragma once
#include "MedikamentDomain.h"
#include <vector>
class MedikamentRepo
{
private:
	friend class MedikamentController;

	int current_index = -1;

	std::vector< std::vector<MedikamentDomain> > undo_redo;

	std::vector<MedikamentDomain> medikamente;

public:

	MedikamentRepo();

	void show_medikamente();

	~MedikamentRepo();
};

