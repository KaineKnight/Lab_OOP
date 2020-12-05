
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
		cout << "������� �������� �������:\n";
		cout << "--------------------------------------------\n";
		cout << "1.  ������� 1 ������.\n";					// +
		cout << "2.  ������� 2 ������.\n";					// +
		cout << "3.  ���������� � 1 ������.\n";				// +
		cout << "4.  ���������� � 2 ������.\n";				// +
		cout << "5.  �������� 1 ������.\n";					// +
		cout << "6.  �������� 2 ������.\n";					// +
		cout << "7.  ������� 1 ������.\n";					// +
		cout << "8.  ������� 2 ������.\n";					// +
		cout << "9.  ������� 1 ������.\n";					// +
		cout << "10. ������� 2 ������.\n";					// +
		cout << "11. ��������� 1 ������.\n";				// +
		cout << "12. ��������� 2 ������.\n";				// +
		cout << "13. ��������� ��������� 1 ������ �� 2.\n";	// +
		cout << "14. ��������� ��������� 1 ������ �� 2.\n";	// +
		cout << "15. ��������� ����������� �����.\n";		// +
		cout << "0.  �����.\n";								// +
		cout << "--------------------------------------------\n";
		cout << ">> ";
		cin >> Operation;
		char T;
		double moveX, moveY, angle;
		//�������� �����, ����������� ��� ���������� ������
		switch (Operation) {
		case 0:// �����
			cout << "�������������� �����...\n";
			system("pause");
			break;
		case 1:// ������� 1 ������.
			system("cls");
			if (p1) {
				cout << "������ ��� �������.\n";
				system("pause");
				break;
				//exit(1);
			}
			cout << "���? (�������/��������������) [S/P]\n";
			cin >> T;
			p1 = Shape::CreateShape(T);
			p1->info();
			system("pause");
			break;
		case 2:// ������� 2 ������.
			system("cls");
			if (p2) {
				cout << "������ ��� �������.\n";
				system("pause");
				break;
				//exit(2);
			}
			cout << "���? (�������/��������������) [S/P]\n";
			cin >> T;
			p2 = Shape::CreateShape(T);
			p2->info();
			system("pause");
			break;
		case 3: // ��������� � 1 ������
			system("cls");
			cout << "������ 1 - ";
			p1->info();
			system("pause");
			break;
		case 4: // ���������� � 2 ������
			system("cls");
			cout << "������ 2 - ";
			p2->info();
			system("pause");
			break;
		case 5: // �������� 1 ������
			system("cls");
			cout << "�������� 1 �����:\n<< " << p1->GetPerimeter() << endl;
			system("pause");
			break;
		case 6: // �������� 2 ������
			system("cls");
			cout << "�������� 2 �����:\n<< " << p2->GetPerimeter() << endl;
			system("pause");
			break;
		case 7: // ������� 1 ������
			system("cls");
			cout << "������� 1 �����:\n<< " << p1->GetArea() << endl;
			system("pause");
			break;
		case 8: // ������� 2 ������
			system("cls");
			cout << "������� 2 �����:\n<< " << p1->GetArea() << endl;
			system("pause");
			break;
		case 9: // ������� 1 ������
			system("cls");
			cout << "���� ������� �������� ������ #1?\n";
			cout << "����������� ������������� � ������������� ��������.\n";
			cout << "�� ������� ����� ����� ��� ������ ����������� ������?\n";
			cin >> moveX;
			cout << "�� ������� ����� ����� ��� ���� ����������� ������?\n";
			cin >> moveY;
			p1->Move(moveX, moveY);
			system("pause");
			break;
		case 10:// ������� 2 ������
			system("cls");
			cout << "���� ������� �������� ������ #2?\n";
			cout << "����������� ������������� � ������������� ��������.\n";
			cout << "�� ������� ����� ����� ��� ������ ����������� ������?\n";
			cin >> moveX;
			cout << "�� ������� ����� ����� ��� ���� ����������� ������?\n";
			cin >> moveY;
			p2->Move(moveX, moveY);
			system("pause");
			break;
		case 11:// ��������� 1 ������
			system("cls");
			cout << "������� ����, �� ������� ������� ��������� ������:\n>> ";
			cin >> angle;
			p1->Rotate(angle);
			system("pause");
			break;
		case 12:// ��������� 2 ������
			system("cls");
			cout << "������� ����, �� ������� ������� ��������� ������:\n>> ";
			cin >> angle;
			p1->Rotate(angle);
			system("pause");
			break;
		case 13:// ��������� ��������� 1 ������ �� 2
			system("cls");
			if (p1->IsInclude(*p1, *p2) == 0) {
				cout << "������ 1 �� �������� � ������ 2" << endl;
			}
			else {
				cout << "������ 1 �������� � ������ 2" << endl;
			}
			system("pause");
			break;
		case 14:// ��������� ��������� 2 ������ �� 1
			system("cls");
			if (p1->IsInclude(*p2, *p1) == 0) {
				cout << "������ 2 �� �������� � ������ 1" << endl;
			}
			else {
				cout << "������ 2 �������� � ������ 1" << endl;
			}
			system("pause");
			break;
		case 15:// ��������� ����������� �����
			system("cls");
			if (p1->IsInsert(*p1, *p2) == 0) {
				cout << "������ �� ������������\n";
			}
			else {
				cout << "������ ������������\n";
			}
			system("pause");
			break;
		case 16:// �������� �������
			p1->Compare(*p1, *p2);
		default:
			cout << "������� �������� ��������...\n";
			system("pause");
			break;
		}
		system("cls");
	} while (Operation);
	delete p1;
	delete p2;
}
