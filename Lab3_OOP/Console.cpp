
#include "Console.h"
#include "Shape.h"
#include <iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

void Console::Starter() {
	setlocale(LC_ALL, "ru");
	int Operation;
	Shape* p1 = 0;
	Shape* p2 = 0;
	do {
		cout << "===================Shapes===================\n";
		cout << "Введите желаемую команду:\n";
		cout << "--------------------------------------------\n";
		cout << "1.  Создать 1 фигуру.\n";					// +
		cout << "2.  Создать 2 фигуру.\n";					// +
		cout << "3.  Информация о 1 фигуре.\n";				// +
		cout << "4.  Информация о 2 фигуре.\n";				// +
		cout << "5.  Периметр 1 фигуры.\n";					// +
		cout << "6.  Периметр 2 фигуры.\n";					// +
		cout << "7.  Площадь 1 фигуры.\n";					// +
		cout << "8.  Площадь 2 фигуры.\n";					// +
		cout << "9.  Двигать 1 фигуру.\n";					// +
		cout << "10. Двигать 2 фигуру.\n";					// +
		cout << "11. Повернуть 1 фигуру.\n";				// +
		cout << "12. Повернуть 2 фигуру.\n";				// +
		cout << "13. Проверить включение 1 фигуры во 2.\n";	// +
		cout << "14. Проверить включение 1 фигуры во 2.\n";	// +
		cout << "15. Проверить пересечение фигур.\n";		// +
		cout << "0.  Выход.\n";								// +
		cout << "--------------------------------------------\n";
		cout << ">> ";
		cin >> Operation;
		char T;
		double moveX, moveY, angle;
		//оператор свитч, необходимый для считывания данных
		switch (Operation) {
		case 0:// Выход
			cout << "Осуществляется выход...\n";
			system("pause");
			break;
		case 1:// Создать 1 фигуру.
			system("cls");
			if (p1) {
				cout << "Фигура уже создана.\n";
				system("pause");
				break;
				//exit(1);
			}
			cout << "Тип? (Квадрат/Параллелограмм) [S/P]\n";
			cin >> T;
			p1 = Shape::CreateShape(T);
			p1->info();
			system("pause");
			break;
		case 2:// Создать 2 фигуру.
			system("cls");
			if (p2) {
				cout << "Фигура уже создана.\n";
				system("pause");
				break;
				//exit(2);
			}
			cout << "Тип? (Квадрат/Параллелограмм) [S/P]\n";
			cin >> T;
			p2 = Shape::CreateShape(T);
			p2->info();
			system("pause");
			break;
		case 3: // Иформация о 1 фигуре
			system("cls");
			cout << "Фигура 1 - ";
			p1->info();
			system("pause");
			break;
		case 4: // Информация о 2 фигуре
			system("cls");
			cout << "Фигура 2 - ";
			p2->info();
			system("pause");
			break;
		case 5: // Периметр 1 фигуры
			system("cls");
			cout << "Периметр 1 равен:\n<< " << p1->GetPerimeter() << endl;
			system("pause");
			break;
		case 6: // Периметр 2 фигуры
			system("cls");
			cout << "Периметр 2 равен:\n<< " << p2->GetPerimeter() << endl;
			system("pause");
			break;
		case 7: // Площадь 1 фигуры
			system("cls");
			cout << "Площадь 1 равна:\n<< " << p1->GetArea() << endl;
			system("pause");
			break;
		case 8: // Площадь 2 фигуры
			system("cls");
			cout << "Площадь 2 равна:\n<< " << p1->GetArea() << endl;
			system("pause");
			break;
		case 9: // Двигать 1 фигуру
			system("cls");
			cout << "Куда желаете сдвинуть фигуру #1?\n";
			cout << "Используйте положительные и отрицательные значения.\n";
			cout << "На сколько точек влево или вправо переместить фигуру?\n";
			cin >> moveX;
			cout << "На сколько точек вверх или вниз переместить фигуру?\n";
			cin >> moveY;
			p1->Move(moveX, moveY);
			system("pause");
			break;
		case 10:// Двигать 2 фигуру
			system("cls");
			cout << "Куда желаете сдвинуть фигуру #2?\n";
			cout << "Используйте положительные и отрицательные значения.\n";
			cout << "На сколько точек влево или вправо переместить фигуру?\n";
			cin >> moveX;
			cout << "На сколько точек вверх или вниз переместить фигуру?\n";
			cin >> moveY;
			p2->Move(moveX, moveY);
			system("pause");
			break;
		case 11:// Повернуть 1 фигуру
			system("cls");
			cout << "Введите угол, на который желаете повернуть фигуру:\n>> ";
			cin >> angle;
			p1->Rotate(angle);
			system("pause");
			break;
		case 12:// Повернуть 2 фигуру
			system("cls");
			cout << "Введите угол, на который желаете повернуть фигуру:\n>> ";
			cin >> angle;
			p1->Rotate(angle);
			system("pause");
			break;
		case 13:// Проверить включение 1 фигуры во 2
			system("cls");
			if (p1->IsInclude(*p1, *p2) == 0) {
				cout << "Фигура 1 не включена в Фигуру 2" << endl;
			}
			else {
				cout << "Фигура 1 включена в Фигуру 2" << endl;
			}
			system("pause");
			break;
		case 14:// Проверить включение 2 фигуры во 1
			system("cls");
			if (p1->IsInclude(*p2, *p1) == 0) {
				cout << "Фигура 2 не включена в Фигуру 1" << endl;
			}
			else {
				cout << "Фигура 2 включена в Фигуру 1" << endl;
			}
			system("pause");
			break;
		case 15:// Проверить пересечение фигур
			system("cls");
			if (p1->IsInsert(*p1, *p2) == 0) {
				cout << "Фигуры не пересекаются\n";
			}
			else {
				cout << "Фигуры пересекаются\n";
			}
			system("pause");
			break;
		case 16:// Сравнить площади
			p1->Compare(*p1, *p2);
		default:
			cout << "Введено неверное значение...\n";
			system("pause");
			break;
		}
		system("cls");
	} while (Operation);
	delete p1;
	delete p2;
}
