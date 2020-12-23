#include "Console.h"
#include <iostream>
#include <fstream>
#include "Town.h"
#include "TownIContainer.h"
//#include <vld.h>
using std::cin;
using std::cout;
using std::string;
using std::fstream;
using std::exception;
using std::endl;
using std::cerr;
using std::runtime_error;


void Console::Starter() {
	setlocale(LC_ALL, "ru");
	string path = "source.txt";
	fstream fs;
	TownIContainer* MyTown = 0;
	try {
		fs.open(path);
		if (!fs) {
			throw runtime_error("Файл отсутствует!\n");
		}
		cout << "Файл открыт.\n Выберите тип хранения: вектор[v] или мап[m]\n";
		char choice;
		cin >> choice;
		MyTown = TownIContainer::CreateTown(choice);
		cout << "Ok\n";
		//VectorTown MyTown;
		fs >> MyTown;
		cout << "\n=============================\n\n";
		cout << MyTown;
		cout << "\n=============================\n";
		
		cout << "Ведите среднюю цену кв. м. жилья и наличие зеленых зон";
		cout << "в процентах, чтобы осуществить поиск:\n";
		cout << "\nPrice, GreenZones\n";
		int price, greenZones;
		cin >> price >> greenZones;
		auto FindTown = MyTown->Find(price, greenZones);
		cout << "\n=============================\n\n";
		for (auto& it : FindTown) {
			cout << it.GetName() << "\t" << it.GetRevenue() << "\t";
			cout << it.GetPrice() << "\t" << it.GetGreenZones() << "\n";
		}
		cout << "\n=============================\n";

	}
	catch (exception& trouble) {
		cerr << trouble.what() << endl;
	}
	delete MyTown;



}