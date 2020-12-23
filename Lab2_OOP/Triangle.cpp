//Triangle.cpp
#define _USE_MATH_DEFINES
#include "Triangle.h"
#include <math.h>
//#define PI 3.14159265

//Базовый класс
Triangle::Triangle(double a, double b, double angle) {
	_a = a;
	_b = b;
	_angle = angle * M_PI / 180;
}

void Triangle::SetTriangle(double a, double b, double angle) {
	_a = a;
	_b = b;
	_angle = angle * M_PI / 180;
}

double Triangle::Area() { //площадь разностороннего треугольника
	return (_a * _b * sin(_angle)) / 2;
}

double Triangle::Perimeter() { //периметр разностороннего треугольника
	return _a + _b + (sqrt(_a * _a + _b * _b - 2 * _a * _b * cos(_angle)));
}

Equilateral::Equilateral(double a) {
	_a = a;
}

void Equilateral::SetTriangle(double a) {
	_a = a;
}

double Equilateral::Area() { //площадь равностороннего треугольника
	return (_a * _a * (sqrt(3)) / 4);
}

double Equilateral::Perimeter() { //периметр равностороннего треугольника
	return 3 * _a;
}

Isosceles::Isosceles(double a, double angle) {
	_a = a;
	_angle = angle * M_PI / 180;
}

void Isosceles::SetTriangle(double a, double angle) {
	_a = a;
	_angle = angle * M_PI / 180;
}

double Isosceles::Area() { //площадь равнобедренного треугольника
	return (_a * _a * sin(_angle)) / 2;
}

double Isosceles::Perimeter() { //периметр равнобедренного треугольника
	return _a + _a + (sqrt(2 * _a * _a * (1 - cos(_angle))));
}

Right::Right(double a, double b) {
	_a = a;
	_b = b;
}

void Right::SetTriangle(double a, double b) {
	_a = a;
	_b = b;
}

double Right::Area() { //площадь прямоугольного треугольника
	return _a * _b / 2;
}

double Right::Perimeter() { //периметр прямоугольного треугольника
	return _a + _b + (sqrt(_a * _a + _b * _b));
}
