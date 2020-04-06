#include "pch.h"
#include "MedikamentController.h"
#include <algorithm>
#include <iostream>


MedikamentController::MedikamentController()
{
	this->repo = MedikamentRepo();
	this->size = -1;
}

void MedikamentController::addMedikament(MedikamentDomain m) {

	this->Change();
	for (std::vector<MedikamentDomain>::iterator ptr = repo.medikamente.begin();
		ptr < repo.medikamente.end(); ptr++) {

		if (ptr->GetName() == m.GetName() && ptr->GetKonzentration() == m.GetKonzentration()) {
			ptr->SetMenge(ptr->GetMenge() + m.GetMenge());
			//std::cout << "Medikament wurde eingefugt ";

			repo.undo_redo.push_back(repo.medikamente);
			this->size++;
			repo.current_index++;

			return;
		}

	}

	repo.medikamente.push_back(m);

	repo.undo_redo.push_back(repo.medikamente);
	repo.current_index++;
	this->size++;

}

void MedikamentController::deleteMedikament(MedikamentDomain m) {

	this->Change();
		for (std::vector<MedikamentDomain>::iterator ptr = repo.medikamente.begin();
		ptr < repo.medikamente.end(); ptr++) {

		if (ptr->GetName() == m.GetName() && ptr->GetKonzentration() == m.GetKonzentration()) {
			repo.medikamente.erase(ptr);

			repo.undo_redo.push_back(repo.medikamente);
			repo.current_index++;
			this->size++;

			return;
		}

		}

}

std::vector<std::string> MedikamentController::Kette(std::string sir) {

		std::vector<std::string> med;

		for (std::vector<MedikamentDomain>::iterator ptr = repo.medikamente.begin();
			ptr < repo.medikamente.end(); ptr++) {

			if (ptr->GetName().find(sir) != -1) {
				med.push_back(ptr->GetName());
			}

		}

		sort(med.begin(), med.end());
		return med;
}

std::vector<std::string> MedikamentController::Knapp_Menge(int x) {

	std::vector<std::string> vec;
	for (std::vector<MedikamentDomain>::iterator ptr = repo.medikamente.begin();
		ptr < repo.medikamente.end(); ptr++) {

		if (ptr->GetMenge() < x) {

			vec.push_back(ptr->GetName());
		}

	}

	return vec;
}

std::vector<MedikamentDomain> MedikamentController::Preis() {

	//Salvam vectorul de medikamente
	std::vector<MedikamentDomain> med_preis;
	for (std::vector<MedikamentDomain>::iterator i = repo.medikamente.begin();
		i < repo.medikamente.end(); i++) {

		med_preis.push_back(*i);

	}

	//il sortam pe cel nou in functie de pret
	for (std::vector<MedikamentDomain>::iterator i = med_preis.begin();
		i < med_preis.end(); i++) {

		for (std::vector<MedikamentDomain>::iterator j = med_preis.begin();
			j < med_preis.end(); j++) {

			if (j->GetPreis() > i->GetPreis()) {
				MedikamentDomain t = *i;
				*i = *j;
				*j = t;
			}

		}
	}

	return med_preis;

	
}

void MedikamentController::Undo() {

	if (repo.current_index > 0) {
		repo.current_index--;
		repo.medikamente = repo.undo_redo[repo.current_index];
	}
	
}

void MedikamentController::Redo() {

	if (this->size > repo.current_index) {
		repo.current_index++;
		repo.medikamente = repo.undo_redo[repo.current_index];
	}
}

void MedikamentController::Change() {

	if (repo.current_index < this->size) {
		int diff = this->size - repo.current_index;
		while (diff) {
			repo.undo_redo.erase(repo.undo_redo.end()-1);
			diff--;
		}
		
		this->size = repo.current_index;
	}
}

MedikamentController::~MedikamentController()
{
	repo.medikamente.clear();
	repo.undo_redo.clear();
}
