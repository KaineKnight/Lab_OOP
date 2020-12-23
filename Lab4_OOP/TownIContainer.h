#pragma once
#include <iostream>
#include<vector>
#include <map>
#include <algorithm>
#include<string>
#include "Town.h"
using std::istream;
using std::copy_if;
using std::sort;
using std::cout;
using std::to_string;

class TownIContainer {
public:
	static TownIContainer* CreateTown(char cd);
	virtual void AddTown(Town& town) = 0;
	virtual ~TownIContainer() = default;
	virtual std::vector<Town> Find(int price, int greenZones) = 0;
	virtual string ToStrings() = 0;
private:
};

class VectorTown : public TownIContainer {
private:
	std::vector<Town> _vecTown;
	auto NameSort() {
		sort(_vecTown.begin(), _vecTown.end(), [](Town t1, Town t2) {
			return t1.GetName() < t2.GetName();
			});
	}
public:
	VectorTown() = default;
	VectorTown(const VectorTown& Town) = default;
	string ToStrings() override {
		string result = "";
		
		for (auto& it : _vecTown) {
			result += it.GetName() + '\t';
			result += to_string(it.GetRevenue()) + '\t';
			result += to_string(it.GetPrice()) + '\t';
			result += to_string(it.GetGreenZones()) + '\n';

		}
		return result;
	}
	VectorTown(std::vector<Town>& vecTown) {
		this->_vecTown = vecTown;
	}
	void AddTown(Town& town) override { // для добавления одного элемента
		_vecTown.push_back(town);
	}
	void AddTowns(std::vector<Town>& vecTown) { // для добавления вектора элементов
		for (auto& it : vecTown) {
			_vecTown.push_back(it);
		}
		//for (auto it = vecTown.begin(); it != vecTown.end(); it++) {
		//	_vecTown.push_back(*it);
		//}
	}
	std::vector<Town>& GetTowns() {
		return _vecTown;
	}
	std::vector<Town> Find(int price, int greenZones) override {
		this->NameSort();
		std::vector<Town> vecTown;
		copy_if(_vecTown.begin(), _vecTown.end(),
			back_inserter(vecTown), [price, greenZones](Town town) {
				return (town.GetPrice() == price) && (town.GetGreenZones() == greenZones);
			});
		return vecTown;
	}
};

istream& operator>>(istream& is, VectorTown& _vecTown) {
	Town town;
	while (is >> town) {
		_vecTown.GetTowns().push_back(town);
	}
	return is;
}

class MapTown : public TownIContainer {
private:
	std::multimap<int, Town> _townMap;
public:
	MapTown() = default;
	MapTown(std::multimap<int, Town>& townMap) {
		for (auto& it : townMap) {
			_townMap.insert(it);
		}
	 }
	string ToStrings() override {
		string result = "";

		for (auto& it : _townMap) {
			result += it.second.GetName() + '\t';
			result += to_string(it.second.GetRevenue()) + '\t';
			result += to_string(it.second.GetPrice()) + '\t';
			result += to_string(it.second.GetGreenZones()) + '\n';

		}
		return result;
	}
	void AddTown(Town& townMap) override {
		_townMap.emplace(townMap.GetPrice(), townMap);
	}
	void AddTowns(std::multimap<int, Town>& townMap) {
		for (auto& it : townMap) {
			_townMap.insert(it);
		}
	}
	std::multimap<int, Town>& GetTowns() {
		return _townMap;
	}
	std::vector<Town> Find(int price, int greenZones) override {
		std::vector<Town> res;
		auto it = _townMap.find(price);
		int k = _townMap.count(price);
		for (int i = 0; i < k; i++) {
			res.push_back(it->second);
			it++;
		}
		return res;
	}
};

istream& operator>>(istream& is, MapTown& townMap) {
	Town town;
	while (is >> town) {
		townMap.GetTowns().emplace(town.GetPrice(), town);
	}
	return is;
}

TownIContainer* TownIContainer::CreateTown(char cd) {
	TownIContainer* t = 0;
	if (cd == 'v') cd = 'V';
	if (cd == 'm') cd = 'M';
	switch (cd) {
	case 'V':
		t = new VectorTown(); break;
	case 'M':
		t = new MapTown(); break;
	default: cout << "Ошибка ввода!\n"; break;
	}
	return t;
}

istream& operator>>(istream& is, TownIContainer* container) {
	Town town;
	while (is >> town) {
		container->AddTown(town);
	}
	return is;
}

ostream& operator<<(ostream& os, TownIContainer* container) {
	string temp = container->ToStrings();
	os << temp;
	return os;
}

ostream& operator<<(ostream& os, VectorTown container) {
	string temp = container.ToStrings();
	os << temp;
	return os;
}

ostream& operator<<(ostream& os, MapTown container) {
	string temp = container.ToStrings();
	os << temp;
	return os;
}