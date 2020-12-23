//Console.h
#pragma once
#include "Queue.h"

class Console {
public:
	void RunProgram();
	~Console();
private:
	int _size = 0;
	Queue* _q;
};