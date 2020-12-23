//Triangle.h
#pragma once
//������� ����� �����������
class Triangle {
public:
	Triangle() = default;
	Triangle(double a, double b, double angle);
	void SetTriangle(double a, double b, double angle); // ������� ��� ������� ������ � ����
	virtual double Area(); // �������
	virtual double Perimeter(); // ��������
	~Triangle() {}
protected:
	double _a; //������ �������
	double _b; //������ �������
	double _angle;//���� ����� ����
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
