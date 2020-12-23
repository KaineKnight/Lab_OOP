//Console.cpp
#include "Console.h"
#include "Triangle.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// функция, необходимая для обработки подменю
void Console::SecondOp(Triangle* triangle) {
	cout << "Что вы желаете найти?\n";
	cout << "1. Площадь.\n";
	cout << "2. Периметр.\n";
	cout << "0. Отмена.\n";
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
			cout << "Неверная команда.\n";
			break;
		}
	} while (triOp);
	//system("pause");
}

//основная функция для взаимодействия с консолью
void Console::RunProgram() {
	int Operation;
	do {
		cout << "================Triangle================\n";
		cout << "Какой треугольник желаете посчитать?\n";
		cout << "-------------------------------------\n";
		cout << "1. Разносторонний.\n";
		cout << "2. Равносторонний.\n";
		cout << "3. Равнобедренный.\n";
		cout << "4. Прямоугольныйк.\n";
		cout << "0. Выйти.\n";
		cout << "-------------------------------------\n";
		cout << ">> ";
		cin >> Operation;
		int a, b, angle;
		if (triangle != nullptr) {
			delete triangle;
			triangle = nullptr;
		}
		//оператор свитч, необходимый для считывания данных
		switch (Operation) {
		case 0:
			cout << "Осуществляется выход...\n";
			break;
		case 1:
			system("cls");
			cout << "Разносторонний треугольник.";
			cout << "Введите, пожалуйста, длины двух сторон и угол между ними (в градусах)\n";
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
			cout << "Равносторонний треугольник.";
			cout << "Введите, пожалуйста, длину cтороны\n";
			cout << "a = ";
			cin >> a;
			triangle = new Equilateral(a);
			//eq.SetTriangle(a);
			SecondOp(triangle);
			break;
		case 3:
			system("cls");
			cout << "Равнобедренный треугольник.";
			cout << "Введите, пожалуйста, длину  равных сторон и угол между ними (в градусах)\n";
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
			cout << "Прямоугольный треугольник.";
			cout << "Введите, пожалуйста, длины двух сторон\n";
			cout << "a = ";
			cin >> a;
			cout << "b = ";
			cin >> b;
			triangle = new Right(a, b);
			//rt.SetTriangle(a, b);
			SecondOp(triangle);
			break;
		default:
			cout << "Введено неверное значение...\n";
			break;
		}
		system("cls");
	} while (Operation);

}