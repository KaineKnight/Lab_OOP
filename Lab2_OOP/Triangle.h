//Triangle.h
#pragma once
//Базовый класс Треугольник
class Triangle {
public:
	Triangle() = default;
	Triangle(double a, double b, double angle);
	void SetTriangle(double a, double b, double angle); // функция для задания сторон и угла
	virtual double Area(); // площадь
	virtual double Perimeter(); // периметр
	~Triangle() {}
protected:
	double _a; //первая сторона
	double _b; //вторая сторона
	double _angle;//угол между ними
};

class Equilateral : public Triangle {
public:
	Equilateral() = default;
	Equilateral(double a);
	void SetTriangle(double a);
	double Area() override;
	double Perimeter() override;
	~Equilateral() {}
private:
	//double _a;
};

class Isosceles : public Triangle {
public:
	Isosceles() = default;
	Isosceles(double a, double angle);
	void SetTriangle(double a, double angle);
	double Area() override;
	double Perimeter() override;
	~Isosceles() {}
private:
	//double _a;
	//double _angle;
};

class Right : public Triangle {
public:
	Right() = default;
	Right(double a, double b);
	void SetTriangle(double a, double b);
	double Area() override;
	double Perimeter() override;
	~Right() {}
private:
	//double _a;
	//double _b;
};
