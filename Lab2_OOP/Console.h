//Console.h
#pragma once
#include "Triangle.h"

class Console {
private:
	void SecondOp(Triangle* triangle);
	Triangle* triangle = nullptr;
	//Equilateral eq;
	//Isosceles iso;
	//Right rt;
public:
	Console() = default;
	void RunProgram();
	~Console() {
		if (triangle != nullptr) {
			delete triangle;
			triangle = nullptr;
		}
	}
};

