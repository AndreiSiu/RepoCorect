#include "pch.h"
#include <iostream>
#include "MedikamentRepo.h"


MedikamentRepo::MedikamentRepo()
{
}

void MedikamentRepo::show_medikamente() {

	for (std::vector<MedikamentDomain>::iterator ptr = medikamente.begin();
		ptr < medikamente.end(); ptr++) {

		std::cout << ptr->GetName() <<' ';

	}
	std::cout << '\n';
}

MedikamentRepo::~MedikamentRepo()
{
}
