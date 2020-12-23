//Queue.h
#pragma once


class Queue {
public:
	explicit Queue(int size); // �����������
	Queue(Queue const& other); // ����������� �����������
	bool isEmpty(); // ����� �������� ������� �� ������� � �������������
	int push(int data); // ����� ���������� ��������� � �������
	int pop(); // ����� ���������� �������� �� �������
	const int& front(); // ����� ����������� ������� �������� ��� ����������
	Queue& operator=(Queue const& other); // ����������� ��������� ������������
	bool operator ==(Queue const& other);
	bool operator !=(Queue const& other);
	Queue& operator +(Queue const& other);
	Queue& operator -(Queue const& other);
	Queue& operator ++(int value); // ��������
	Queue& operator --(int value); // ��������
	Queue& operator ++(); // �������
	Queue& operator --(); // �������
	int & operator [](int v); // ��� �������
	friend void ChangeSize(Queue& object); // ������������� ������� ��� ������� � private
	int GetId();
	static int GetCount();

	~Queue(); // ����������
private:
	void swap(Queue& other); // ��������������� ������� ��� ���������� ������������ ��������� ������������
	int _size; 
	int* _queue; 
	int _head, _tail;
	static int count;
	int id = 0;
};

