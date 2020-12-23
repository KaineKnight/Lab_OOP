#pragma once
#include <iostream>
using std::string;
using std::ostream;
using std::istream;

class Town {
public:
	Town() = default;
	Town(string name, int revenue, int price, int greenZones) {
		this->_name = name;
		this->_revenue = revenue;
		this->_price = price;
		this->_greenZones = greenZones;
	}
	string GetName() {
		return _name;
	}
	~Town() = default;
	int GetRevenue() {
		return _revenue;
	}
	int GetPrice() {
		return _price;
	}
	int GetGreenZones() {
		return _greenZones;
	}
	void SetName(string name) {
		this->_name = name;
	}
	void SetRevenue(int revenue) {
		this->_revenue = revenue;
	}
	void SetPrice(int price) {
		this->_price = price;
	}
	void SetGreenZones(int greenZones) {
		this->_greenZones = greenZones;
	}
private:
	string _name = ""; // Название города
	int _revenue = -1; // Средний доход жителя
	int _price = -1; // Средняя цена кв.м. жилья
	int _greenZones = -1; // Зеленые зоны в процентах
};

// Вывод в поток
ostream& operator<<(ostream& os, Town& town) {
	os << town.GetName() << "\t" << town.GetRevenue() << "\t";
	os << town.GetPrice() << "\t" << town.GetGreenZones() << "\t\n";
	return os;
}

// Вывод из потока
istream& operator>>(istream& is, Town& town) {
	string name = "";
	int revenue = -1, price = -1, greenZones = -1;
	is >> name >> revenue >> price >> greenZones;
	town.SetName(name);
	town.SetRevenue(revenue);
	town.SetPrice(price);
	town.SetGreenZones(greenZones);
	return is;
}
