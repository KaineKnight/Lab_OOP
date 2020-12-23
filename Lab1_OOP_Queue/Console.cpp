//Console.cpp
#include "Console.h"
#include "Queue.h"
#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;




void Console::RunProgram() {
	cout << " Enter The Queue's max size\n>> ";
	cin >> _size;
	_q = new Queue(_size);
	Queue& q = *_q;

	system("cls");
	cout << "================Queue================\n";
	cout << "-------------------------------------\n";
	cout << "1. Push Element\n";
	cout << "2. Pop Element\n";
	cout << "3. Check if Queue isEmpty\n";
	cout << "4. Get front element without popping\n";
	cout << "5. Show menu again\n";
	cout << "0. Exit program\n";
	cout << "-------------------------------------\n";
	int Operation;
	do {
		int element;
		cout << ">> ";
		cin >> Operation;
		switch (Operation) {
		case 0:
			cout << "Exiting program...\n";
			break;
		case 1:
			cout << "Enter new element\n>>>> ";
			cin >> element;
			if (!q.push(element)) {
				cout << "End of Queue! Can't push any more elements!" << endl;
			}
			break;
		case 2:
			try {
				cout << "Element popped " << q.pop() << endl;
			}
			catch (const std::exception&) {
				cout << "No elements" << endl;
			}
			break;
		case 3:
			if (q.isEmpty()) {
				cout << "Queue is Empty" << endl;
			}
			else {
				cout << "Queue is not Empty" << endl;
			}
			break;
		case 4:
			try {
				cout << "Front element: " << q.front() << endl;
			}
			catch (const std::exception&) {
				cout << "No elements" << endl;
			}
			break;
		case 5:
			system("cls");
			cout << "================Queue================\n";
			cout << "-------------------------------------\n";
			cout << "1. Push Element\n";
			cout << "2. Pop Element\n";
			cout << "3. Check if Queue isEmpty\n";
			cout << "4. Get front element without popping\n";
			cout << "5. Show menu again\n";
			cout << "0. Exit program\n";
			cout << "-------------------------------------\n";
			break;
		default:
			cout << "Incorrect command" << endl;
			break;
		}
	} while (Operation);
}


Console::~Console() {
	delete _q;
}