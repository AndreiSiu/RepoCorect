#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Lab4_main\MedikamentController.h"
#include "..\Lab4_main\MedikamentDomain.h"
#include "..\Lab4_main\MedikamentRepo.h"
#include "..\Lab4_main\MedikamentController.cpp"
#include "..\Lab4_main\MedikamentDomain.cpp"
#include "..\Lab4_main\MedikamentRepo.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(MedikamenteTest)
	{
	public:
		
		TEST_METHOD(AddTest)
		{
			MedikamentController controller;
			Assert::AreEqual(controller.GetSize(), 0);

			for (int i = 1; i <= 200; i++) {
				MedikamentDomain med = MedikamentDomain("Nurofen", i ,2 ,10);
				controller.AddMed(med);
			}
			Assert::AreEqual(controller.GetSize(), 200);

			for (int i = 1; i <= 50; i++) {
				MedikamentDomain med = MedikamentDomain("Nurofen", i, 2, 10);
				controller.AddMed(med);
			}

			Assert::AreEqual(controller.GetSize(), 200);
		}

		TEST_METHOD(DeleteTest){

			MedikamentController controller;

			for (int i = 1; i <= 100; i++) {
				MedikamentDomain med = MedikamentDomain("Nurofen", i, 2, 10);
				controller.AddMed(med);
			}

			for (int i = 1; i <= 50; i++) {
				MedikamentDomain med = MedikamentDomain("Nurofen", i, 2, 10);
				controller.DeleteMed(med);
			}
			Assert::AreEqual(controller.GetSize(), 50);
		}

		TEST_METHOD(KetteTest) {
			MedikamentController controller;

			for (int i = 1; i <= 10; i++) {

				MedikamentDomain med = MedikamentDomain(std::to_string(i) + "fen", i, 1, 1);
				controller.AddMed(med);
			}
			for (int i = 1; i <= 10; i++) {

				MedikamentDomain med = MedikamentDomain(std::to_string(i) + "mol", i, 1, 1);
				controller.AddMed(med);
			}

			for (int i = 1; i <= 20; i++) {

				MedikamentDomain med = MedikamentDomain(std::to_string(i) + "mol", i, 1, 1);
				controller.AddMed(med);
			}
			Assert::AreEqual(controller.GetSize(), 30);

			std::vector<std::string> med_vec1 = controller.GetKette("fen");
			Assert::AreEqual((int)med_vec1.size(), 10);

			std::vector<std::string> med_vec2 = controller.GetKette("mol");
			Assert::AreEqual((int)med_vec2.size(), 20);
		}

		TEST_METHOD(MengeTest) {
			MedikamentController controller;

			for (int i = 1; i <= 50; i++) {
				MedikamentDomain med = MedikamentDomain("Nurofen", i, i, 10);
				controller.AddMed(med);
			}
			std::vector<std::string> vec1 = controller.GetMenge(30);
			Assert::AreEqual((int)vec1.size(), 29);

			std::vector<std::string> vec2 = controller.GetMenge(60);
			Assert::AreEqual((int)vec2.size(), 50);
		}

		TEST_METHOD(PreisTest) {
			MedikamentDomain m1 = MedikamentDomain("Nurofen", 3.3, 3, 20.9);
			MedikamentDomain m2 = MedikamentDomain("Ibuprofen", 20.3, 30, 25);
			MedikamentDomain m3 = MedikamentDomain("Smecta", 99, 20, 20.9);
			MedikamentDomain m4 = MedikamentDomain("Arsenic", 28, 40, 20.9);
			MedikamentDomain m5 = MedikamentDomain("Nurofen", 20.5, 300, 33);
			MedikamentController controller = MedikamentController();
			controller.AddMed(m1);
			controller.AddMed(m2);
			controller.AddMed(m3);
			controller.AddMed(m4);
			controller.AddMed(m5);
			std::vector<MedikamentDomain> vec = controller.GetPreis();
			std::string stringTest1 = vec[2].GetName();
			std::string stringTest2 = "Arsenic";
			std::string stringTest3 = vec[1].GetName();
			std::string stringTest4 = "Smecta";
			std::string stringTest5 = vec[0].GetName();
			std::string stringTest6 = "Nurofen";
			std::string stringTest7 = vec[3].GetName();
			std::string stringTest8 = "Ibuprofen";
			Assert::AreEqual(stringTest1, stringTest2);
			Assert::AreEqual(stringTest4, stringTest3);
			Assert::AreEqual(stringTest5, stringTest6);
			Assert::AreEqual(stringTest8, stringTest7);

		}
		TEST_METHOD(UndoRedoTest) {
			MedikamentController controller;
			MedikamentDomain m1 = MedikamentDomain("Nurofen", 3.3, 3, 20.9);
			MedikamentDomain m2 = MedikamentDomain("Ibuprofen", 20.3, 30, 25);
			MedikamentDomain m3 = MedikamentDomain("Smecta", 99, 20, 20.9);
			MedikamentDomain m4 = MedikamentDomain("Arsenic", 28, 40, 20.9);
			MedikamentDomain m5 = MedikamentDomain("Nurofen", 20.5, 300, 33);

			controller.AddMed(m1);
			controller.AddMed(m2);
			controller.AddMed(m3);
			controller.AddMed(m4);
			controller.AddMed(m5);

			Assert::AreEqual((int)controller.GetSize(), 5);
			controller.DoUndo();
			controller.DoUndo();
			controller.DoUndo();
			Assert::AreEqual((int)controller.GetSize(), 2);

			controller.DoRedo();
			Assert::AreEqual((int)controller.GetSize(), 3);

			MedikamentDomain m6 = MedikamentDomain("Paracetamol", 20.8, 30, 15);
			controller.AddMed(m6);
			controller.DoRedo();
			controller.DoRedo();
			Assert::AreEqual((int)controller.GetSize(), 4);
			controller.DoUndo();
			controller.DoUndo();
			controller.DoUndo();
			Assert::AreEqual((int)controller.GetSize(), 1);
		}
	};
}