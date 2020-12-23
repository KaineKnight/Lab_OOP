//Triangle.cpp
#define _USE_MATH_DEFINES
#include "Triangle.h"
#include <math.h>
//#define PI 3.14159265

//������� �����
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

double Triangle::Area() { //������� ��������������� ������������
	return (_a * _b * sin(_angle)) / 2;
}

double Triangle::Perimeter() { //�������� ��������������� ������������
	return _a + _b + (sqrt(_a * _a + _b * _b - 2 * _a * _b * cos(_angle)));
}

Equilateral::Equilateral(double a) {
	_a = a;
}

void Equilateral::SetTriangle(double a) {
	_a = a;
}

double Equilateral::Area() { //������� ��������������� ������������
	return (_a * _a * (sqrt(3)) / 4);
}

double Equilateral::Perimeter() { //�������� ��������������� ������������
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

double Isosceles::Area() { //������� ��������������� ������������
	return (_a * _a * sin(_angle)) / 2;
}

double Isosceles::Perimeter() { //�������� ��������������� ������������
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

double Right::Area() { //������� �������������� ������������
	return _a * _b / 2;
}

double Right::Perimeter() { //�������� �������������� ������������
	return _a + _b + (sqrt(_a * _a + _b * _b));
}
