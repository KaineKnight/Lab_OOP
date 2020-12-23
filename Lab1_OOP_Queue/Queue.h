//Queue.h
#pragma once


class Queue {
public:
	explicit Queue(int size); // конструктор
	Queue(Queue const& other); // конструктор копирования
	bool isEmpty(); // метод проверки очереди на пустоту и заполненность
	int push(int data); // метод добавления элементов в очередь
	int pop(); // метод извлечения элемента из очереди
	const int& front(); // метод возвращения первого элемента без извлечения
	Queue& operator=(Queue const& other); // конструктор оператора присваивания
	bool operator ==(Queue const& other);
	bool operator !=(Queue const& other);
	Queue& operator +(Queue const& other);
	Queue& operator -(Queue const& other);
	Queue& operator ++(int value); // постфикс
	Queue& operator --(int value); // постфикс
	Queue& operator ++(); // префикс
	Queue& operator --(); // префикс
	int & operator [](int v); // для массива
	friend void ChangeSize(Queue& object); // дружественная функция для доступа к private
	int GetId();
	static int GetCount();

	~Queue(); // деструктор
private:
	void swap(Queue& other); // вспомогательная функция для реализации конструктора оператора присваивания
	int _size; 
	int* _queue; 
	int _head, _tail;
	static int count;
	int id = 0;
};

