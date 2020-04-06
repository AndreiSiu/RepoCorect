#pragma once
#include "MedikamentRepo.h"
class MedikamentController
{
private:
	friend class MedikamentUI;

	int size;

	/*
		loscht alle Undo-s wenn man der User eine Veranderung macht
	*/
	void Change();

	MedikamentRepo repo;

	/*
		Nimmt ein String als Parameter und liefert alle Medikamente
		die den entsprechenden String enthalten
	*/
	std::vector<std::string> Kette(std::string sir);

	/*
		Fugt Medikamente in dem Repo ein
	*/
	void addMedikament(MedikamentDomain m);

	/*
		Loscht Medikamente aus dem Repo
	*/
	void deleteMedikament(MedikamentDomain m);

	/*
		Nimmt ein Integer als Parameter und liefert alle Medikamente
		die die Menge kleiner als diesen Integer haben
	*/
	std::vector<std::string> Knapp_Menge(int x);

	/*
		-Speichert alle Medikamente in einem anderen Vektor
		-Sortiert diesen neuen Vektor nach Preis
		-Liefert diesen neuen sortierten Vektor
	*/
	std::vector<MedikamentDomain> Preis();

	/*
		Auf dem repo.undo_redo geht der Index, falls moglich, ein Schritt zuruck
	*/
	void Undo();

	/*
		Auf dem repo.undo_redo geht der Index, falls moglich, ein Schritt vorne
	*/
	void Redo();

public:

	MedikamentController();

	std::vector<MedikamentDomain> GetMedikamente() { return repo.medikamente; }

	std::vector<std::string> GetKette(std::string sir) { return this->Kette(sir); }

	std::vector<std::string> GetMenge(int x) { return this->Knapp_Menge(x); }

	std::vector<MedikamentDomain> GetPreis() { return this->Preis(); }

	void DoUndo() { this->Undo(); }

	void DoRedo() { this->Redo(); }

	void AddMed(MedikamentDomain m) { this->addMedikament(m); }

	void DeleteMed(MedikamentDomain m) { this->deleteMedikament(m); }

	int GetSize() { return this->repo.medikamente.size(); }

	~MedikamentController();
};

