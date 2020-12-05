#pragma once
//#define _USE_MATH_DEFINES
#define PI 3.14159265
// Константа для сравнения вещественных чисел
#define EPS 0.1e-30f
#include <iostream>
#include <math.h>
#include <cmath>
#include <cstddef>
using std::cin;
using std::cout;
using std::endl;

struct Point {
	double x, y;
	bool PointInclude(Point* point, int shapePoints);
};

class Shape {
protected:
	Point* _arc = nullptr; // массив точек
	double _area = 0; // площадь фигуры
	double _perimeter = 0; // периметр фигуры
	Point _gravity_center; // центр тяжести
	int _shapePoints = 0; // количество точек фигуры
public:
	virtual ~Shape() {}
	virtual void info() = 0;
	virtual double GetPerimeter() {return _perimeter;}
	virtual double GetArea() {return _area;}
	virtual void Rotate(double angle) = 0;
	virtual void Move(double moveX, double moveY) = 0;
	static Shape* CreateShape(char cd);
	char id;
	int GetSize() {return _shapePoints;}
	Point* GetPoints() {return _arc;}
	Point& GetCenter() {return _gravity_center;}


	bool IsInclude(Shape& isOut, Shape& isIn);

	bool IsInsert(Shape& one, Shape& two);

	void Compare(Shape& one, Shape& two);

};

class Square : public Shape {
public:

	void info() override;

	Square();

	double GetPerimeter() override;

	double GetArea() override;

	void Move(double moveX, double moveY) override;

	void Rotate(double angle) override;

	~Square();

private:
	
};


class Parallel : public Shape {
public:
	void info() override;

	Parallel();

	double GetPerimeter() override;

	double GetArea() override;

	void Move(double moveX, double moveY) override;

	void Rotate(double angle) override;

	~Parallel();

private:

};


