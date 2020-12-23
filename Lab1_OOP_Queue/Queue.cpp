//Queue.cpp
#include "Queue.h"
#include <stdexcept>
#define SWAP(A, B) { int t = A; A = B; B = t; }
#define SWAPP(A, B) { int* t = A; A = B; B = t; }

Queue::Queue(int size) {
	_size = size + 1;
	_queue = new int[_size];
	_head = 0;
	_tail = 0;
}

Queue::Queue(Queue const& other) {
	_size = other._size;
	_queue = new int[_size];
	_head = other._head;
	_tail = other._tail;
	for (int i = 0; i < _size; i++) {
		_queue[i] = other._queue[i];
	}
	count++;
	id=count;
}

bool Queue::isEmpty() {
	return (_head == _tail);
}

int Queue::push(int data) {
	int oldtail = _tail;
	_tail = (_tail + 1) % _size;

	if (_tail == _head) {
		_tail = oldtail;
		return 0;
	}
	_queue[oldtail] = data;
	return 1;
}

int Queue::pop() {
	if (this->isEmpty()) {
		throw std::runtime_error("Queue is Empty");
	}
	int headd = _queue[_head];
	_head = (_head + 1) % _size;
	return headd;
}

const int& Queue::front() {
	if (this->isEmpty()) {
		throw std::runtime_error("Queue is Empty");
	}
	return _queue[_head];
}

Queue& Queue::operator=(Queue const& other) {
	if (this != &other) {
		Queue(other).swap(*this);
	}
	return *this;
}

//bool Queue::operator ==(Queue const& other) {
//
//}
//
//bool Queue::operator !=(Queue const& other) {
//
//}

int& Queue::operator[] (int index) {
	return _queue[index];
}

Queue::~Queue() {
	delete[] _queue;
}

void Queue::swap(Queue& other) {
	SWAPP(this->_queue, other._queue);
	SWAP(this->_head, other._head);
	SWAP(this->_tail, other._tail);
	SWAP(this->_size, other._size);
}

void ChangeSize(Queue& object) {
	object._size = 1000;
}

int Queue::count = 0;

int Queue::GetId(){
	return id;
}

int Queue::GetCount() {
	return count;
}
