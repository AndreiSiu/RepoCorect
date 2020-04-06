#pragma once
#include <iostream>
#include "MedikamentController.h"

class MedikamentUI
{
private:
	MedikamentController controller;

	void CreateList();

	void ReadMedicine();

	void DeleteMedicine();

	void DoKette();

	void DoMenge();

	void DoPreis();

	void ShowMenu();

public:
	MedikamentUI();

	void Show_Menu();

	~MedikamentUI();
};

