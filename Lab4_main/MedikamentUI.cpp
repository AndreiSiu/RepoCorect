#include "pch.h"
#include "MedikamentUI.h"


MedikamentUI::MedikamentUI()
{
}

void MedikamentUI::CreateList() {

	MedikamentDomain m1 = MedikamentDomain("Nurofen", 1, 5, 30);
	MedikamentDomain m2 = MedikamentDomain("Ibuprofen", 10.2, 1, 12);
	//MedikamentDomain m3 = MedikamentDomain("Nurofen", 1, 6, 30);
	MedikamentDomain m4 = MedikamentDomain("Strepsils", 20.1, 10, 5.4);
	MedikamentDomain m5 = MedikamentDomain("Paracetamol", 201, 10, 5.4);

	this->controller.addMedikament(m1);
	this->controller.addMedikament(m2);
	this->controller.addMedikament(m4);
	this->controller.addMedikament(m5);
}

void MedikamentUI::ShowMenu() {
	std::cout << "\n1.Add Medikament \n2.Delete Medikament \n3.Such Medikamente nach string \n4.Such Medikamente nach Menge \n5.Gruppiere nach Preis \n6.Zeige Medikamente \n7.Undo \n8.Redo \n0.Back";
	std::cout << "\nWahle eine Option: ";
}

void MedikamentUI::ReadMedicine() {
	std::cout << "Gib Namen: ";
	std::string name;
	std::cin >> name;

	std::cout << "Gib Konzentration: ";
	double konz;
	std::cin >> konz;

	std::cout << "Gib Menge: ";
	int menge;
	std::cin >> menge;

	std::cout << "Gib Preis: ";
	double preis;
	std::cin >> preis;
	MedikamentDomain m = MedikamentDomain(name, konz, menge, preis);

	controller.addMedikament(m);

	std::cout << '\n';
}

void MedikamentUI::DeleteMedicine() {
	std::cout << "Gib Namen: ";
	std::string name;
	std::cin >> name;

	std::cout << "Gib Konzentration: ";
	double konz;
	std::cin >> konz;

	MedikamentDomain m = MedikamentDomain(name, konz, -1, -1);

	controller.deleteMedikament(m);
	std::cout << '\n';
}

void MedikamentUI::DoKette() {
	//John da un string
	std::vector<std::string> med;

	std::cout << "Gib ein string: ";
	std::string sir;
	std::cin >> sir;
	med = controller.Kette(sir);

	std::cout << '\n';
	std::vector < std::string > ::iterator ptr;
	for (ptr = med.begin(); ptr < med.end(); ptr++)
	{
		std::cout << *ptr << std::endl;
	}

	std::cout << '\n';
}

void MedikamentUI::DoMenge() {
	int menge;
	std::cout << "Gib Menge: ";
	std::cin >> menge;
	std::vector<std::string> med;
	med = controller.Knapp_Menge(menge);

	std::cout << '\n';
	std::vector < std::string > ::iterator ptr;
	for (ptr = med.begin(); ptr < med.end(); ptr++)
	{
		std::cout << *ptr << std::endl;
	}

	std::cout << '\n';
}

void MedikamentUI::DoPreis() {

	std::vector<MedikamentDomain> med_preis;
	med_preis = controller.Preis();

	std::cout << '\n';

	//Afisare de medicamente cu acelasi pret, pret care este sortat
	std::vector<MedikamentDomain>::iterator i = med_preis.begin();
	while (i < med_preis.end()) {

		std::cout << i->GetPreis() << ": ";
		double aux = i->GetPreis();
		while (aux == i->GetPreis()) {
			std::cout << i->GetName() <<", ";
			i++;
			if (i == med_preis.end()) {
				std::cout << '\n';
				return;
			}
		}
		std::cout << '\n';
	}
	
}

void MedikamentUI::Show_Menu() {
	
	this->CreateList();

	int key;
	bool running = true;
	while (running) {
		this->ShowMenu();
		std::cin >> key;
		if (key == 1) {
			
			this->ReadMedicine();
			
		}
		if (key == 2) {

			this->DeleteMedicine();

		}
		if (key == 3) {
			
			this->DoKette();

		}
		if (key == 4) {

			this->DoMenge();

		}
		if (key == 5) {

			this->DoPreis();

		}
		if (key == 6) {
			std::cout << '\n';
			this->controller.repo.show_medikamente();

		}
		if (key == 7) {

			this->controller.Undo();
			std::cout << '\n';

		}

		if (key == 8) {
			this->controller.Redo();
			std::cout << '\n';

		}

		if (key == 0) {
			running = false;
		}

	}
}

MedikamentUI::~MedikamentUI()
{
}
