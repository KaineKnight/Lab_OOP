//Console.cpp
#include "Console.h"
#include "Triangle.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// �������, ����������� ��� ��������� �������
void Console::SecondOp(Triangle* triangle) {
	cout << "��� �� ������� �����?\n";
	cout << "1. �������.\n";
	cout << "2. ��������.\n";
	cout << "0. ������.\n";
	int triOp;
	do {
		cout << ">> ";
		cin >> triOp;
		switch (triOp) {
		case 0:
			break;
		case 1:
			cout << triangle->Area() << endl;
			break;
		case 2:
			cout << triangle->Perimeter() << endl;
			break;
		default:
			cout << "�������� �������.\n";
			break;
		}
	} while (triOp);
	//system("pause");
}

//�������� ������� ��� �������������� � ��������
void Console::RunProgram() {
	int Operation;
	do {
		cout << "================Triangle================\n";
		cout << "����� ����������� ������� ���������?\n";
		cout << "-------------------------------------\n";
		cout << "1. ��������������.\n";
		cout << "2. ��������������.\n";
		cout << "3. ��������������.\n";
		cout << "4. ��������������.\n";
		cout << "0. �����.\n";
		cout << "-------------------------------------\n";
		cout << ">> ";
		cin >> Operation;
		int a, b, angle;
		if (triangle != nullptr) {
			delete triangle;
			triangle = nullptr;
		}
		//�������� �����, ����������� ��� ���������� ������
		switch (Operation) {
		case 0:
			cout << "�������������� �����...\n";
			break;
		case 1:
			system("cls");
			cout << "�������������� �����������.";
			cout << "�������, ����������, ����� ���� ������ � ���� ����� ���� (� ��������)\n";
			cout << "a = ";
			cin >> a;
			cout << "b = ";
			cin >> b;
			cout << "angle= ";
			cin >> angle;
			triangle = new Triangle(a, b, angle);
			//triangle.SetTriangle(a, b, angle);
			SecondOp(triangle);
			break;
		case 2:
			system("cls");
			cout << "�������������� �����������.";
			cout << "�������, ����������, ����� c������\n";
			cout << "a = ";
			cin >> a;
			triangle = new Equilateral(a);
			//eq.SetTriangle(a);
			SecondOp(triangle);
			break;
		case 3:
			system("cls");
			cout << "�������������� �����������.";
			cout << "�������, ����������, �����  ������ ������ � ���� ����� ���� (� ��������)\n";
			cout << "a = ";
			cin >> a;
			cout << "angle = ";
			cin >> angle;
			triangle = new Isosceles(a, angle);
			//iso.SetTriangle(a, angle);
			SecondOp(triangle);
			break;
		case 4:
			system("cls");
			cout << "������������� �����������.";
			cout << "�������, ����������, ����� ���� ������\n";
			cout << "a = ";
			cin >> a;
			cout << "b = ";
			cin >> b;
			triangle = new Right(a, b);
			//rt.SetTriangle(a, b);
			SecondOp(triangle);
			break;
		default:
			cout << "������� �������� ��������...\n";
			break;
		}
		system("cls");
	} while (Operation);

}