#include "Shape.h"


/* ������ �������� ������ */

// ��������� �����
Shape* Shape::CreateShape(char cd) {
	Shape* sh = 0;
	if (cd == 's') cd = 'S';
	if (cd == 'p') cd = 'P';
	switch (cd) {
	case 'S':
		sh = new Square(); break;
	case 'P':
		sh = new Parallel(); break;
	default: cout << "������ �����!\n"; break;
	}
	return sh;
}

// �������� ��������� ����� � ������
bool Point::PointInclude(Point* point, int shapePoints) {
	bool ret = 0;

	//�������� ������� ��������, ��������
	//������������ �� ��� � �������������� �����
	//���������� �� ����� ����� ������

	for (int i = 0; i < shapePoints; ++i) {
		int j = (i + 1) % shapePoints;
		if ((((point[i].y - this->y) >= EPS && (this->y - point[j].y) > EPS) ||
			((this->y - point[i].y) > EPS && (point[j].y - this->y) >= EPS))
			&& ((point[i].y - point[j].y) > EPS) &&
			((((point[i].x - point[j].x) * (this->y - point[j].y) / (point[i].y - point[j].y)
				+ point[j].x) - this->x) > EPS)) {

			ret = !ret;
		}
	}
	return ret;

}

// �������� ��������� ������ � ������
bool Shape::IsInclude(Shape& isOut, Shape& isIn) {

	for (int i = 0; i < isOut.GetSize(); ++i) {
		if (!isOut.GetPoints()[i].PointInclude(isIn.GetPoints(), isIn.GetSize()))
			return 0;
	}
	return 1;
}

// �������� ����������� �����
bool Shape::IsInsert(Shape& one, Shape& two) {

	// ���������, �������� �� �����-���� ����� ������ b � ������ a
	if (two.GetCenter().PointInclude(one.GetPoints(), one.GetSize()))
		return true;
	for (int i = 0; i < two.GetSize(); ++i)
		if (two.GetPoints()[i].PointInclude(one.GetPoints(), one.GetSize()))
			return true;

	// ���������, �������� �� ����� ������ a � ������ b
	if (one.GetCenter().PointInclude(two.GetPoints(), two.GetSize()))
		return true;
	for (int i = 0; i < one.GetSize(); ++i)
		if (one.GetPoints()[i].PointInclude(two.GetPoints(), two.GetSize()))
			return true;

	// ���� �� ����� ���������, ���������� false
	return false;

}

// ��������� �������� �����
void Shape::Compare(Shape& one, Shape& two) {
	if (one.GetArea() - two.GetArea() > EPS) {
		cout << "������� ������ ������ ������\n";
	}
	if (one.GetArea() - two.GetArea() < EPS) {
		cout << "������� ������ ������ ������\n";
	}
	else {
		cout << "������� �����\n";
	}
}


/* ������ �������� */

// ���������� � ��������
void Square::info() {
	cout << "\n�������" << endl;

	cout << "������� 1(x, y)\n";
	cout << _arc[0].x << "\t" << _arc[0].y << endl;
	cout << "������� 2(x, y)\n";
	cout << _arc[1].x << "\t" << _arc[1].y << endl;
	cout << "������� 3(x, y)\n";
	cout << _arc[2].x << "\t" << _arc[2].y << endl;
	cout << "������� 4(x, y)\n";
	cout << _arc[3].x << "\t" << _arc[3].y << endl;

	cout << "����� ������� ������ (x, y)\n";
	cout << _gravity_center.x << "\t" << _gravity_center.y << endl;
}

// ����������� ��������
Square::Square() {
	id = 'S';
	_shapePoints = 4;
	_arc = new Point[4];
	cout << "������� 1(x, y)\n>> ";
	cin >> _arc[0].x >> _arc[0].y;
	cout << "������� 2(x, y)\n>> ";
	cin >> _arc[1].x >> _arc[1].y;
	cout << "������� 3(x, y)\n>> ";
	cin >> _arc[2].x >> _arc[2].y;
	cout << "������� 4(x, y)\n>> ";
	cin >> _arc[3].x >> _arc[3].y;

	_gravity_center.x = (_arc[1].x + _arc[3].x) / 2;
	_gravity_center.y = (_arc[1].y + _arc[3].y) / 2;
}

// ������ � ��������� ��������� ��������
double Square::GetPerimeter() {
	return 4 * (sqrt((_arc[0].x - _arc[1].x) * (_arc[0].x - _arc[1].x)
		+ (_arc[0].y - _arc[1].y) * (_arc[0].y - _arc[1].y)));
}

// ������ � ��������� ������� ��������
double Square::GetArea() {
	return (_arc[0].x - _arc[1].x) * (_arc[0].x - _arc[1].x)
		+ (_arc[0].y - _arc[1].y) * (_arc[0].y - _arc[1].y);
}

// ������������ ���������
void Square::Move(double moveX, double moveY) {
	for (int i = 0; i < _shapePoints; i++) {
		_arc[i].x += moveX;
		_arc[i].y += moveY;
	}
	_gravity_center.x = (_arc[1].x + _arc[3].x) / 2;
	_gravity_center.y = (_arc[1].y + _arc[3].y) / 2;
}

// ������� ��������
void Square::Rotate(double angle) {
	for (int i = 0; i < _shapePoints; i++) {
		double tempX = _arc[i].x;
		double tempY = _arc[i].y;
		_arc[i].x = (tempX * cos(angle * PI / 180)) + (tempY * sin(angle * PI / 180));
		_arc[i].y = (-1 * tempX * sin(angle * PI / 180)) + (tempY * cos(angle * PI / 180));
	}
	_gravity_center.x = (_arc[1].x + _arc[3].x) / 2;
	_gravity_center.y = (_arc[1].y + _arc[3].y) / 2;
}

// ���������� ��������
Square::~Square() {
	delete[] _arc;
}


/* ������ ��������������� */

// ���������� � ���������������
void Parallel::info() {
	cout << "\n��������������" << endl;

	cout << "������� 1(x, y)\n";
	cout << _arc[0].x << "\t" << _arc[0].y << endl;
	cout << "������� 2(x, y)\n";
	cout << _arc[1].x << "\t" << _arc[1].y << endl;
	cout << "������� 3(x, y)\n";
	cout << _arc[2].x << "\t" << _arc[2].y << endl;
	cout << "������� 4(x, y)\n";
	cout << _arc[3].x << "\t" << _arc[3].y << endl;

	cout << "����� ������� ������(x, y)\n";
	cout << _gravity_center.x << "\t" << _gravity_center.y << endl;
}

// ����������� ���������������
Parallel::Parallel() {
	id = 'P';
	_shapePoints = 4;
	_arc = new Point[4];
	cout << "������� 1(x, y)\n>> ";
	cin >> _arc[0].x >> _arc[0].y;
	cout << "������� 2(x, y)\n>> ";
	cin >> _arc[1].x >> _arc[1].y;
	cout << "������� 3(x, y)\n>> ";
	cin >> _arc[2].x >> _arc[2].y;
	cout << "������� 4(x, y)\n>> ";
	cin >> _arc[3].x >> _arc[3].y;

	_gravity_center.x = (_arc[1].x + _arc[3].x) / 2;
	_gravity_center.y = (_arc[1].y + _arc[3].y) / 2;
}

// ������ � ��������� ��������� ���������������
double Parallel::GetPerimeter() {
	return 2 * (sqrt((_arc[0].x - _arc[1].x) * (_arc[0].x - _arc[1].x)
		+ (_arc[0].y - _arc[1].y) * (_arc[0].y - _arc[1].y))) +
		2 * (sqrt((_arc[1].x - _arc[1].x) * (_arc[1].x - _arc[2].x)
			+ (_arc[1].y - _arc[2].y) * (_arc[1].y - _arc[2].y)));
}

// ������ � ��������� ������� ���������������
double Parallel::GetArea() {
	return abs(_arc[0].y - _arc[1].y) * sqrt((_arc[0].x - _arc[3].x) * (_arc[0].x - _arc[3].x)
		+ (_arc[0].y - _arc[3].y) * (_arc[0].y - _arc[3].y));
}

// ������������ ��������������
void Parallel::Move(double moveX, double moveY) {
	for (int i = 0; i < _shapePoints; i++) {
		_arc[i].x += moveX;
		_arc[i].y += moveY;
	}
	_gravity_center.x = (_arc[1].x + _arc[3].x) / 2;
	_gravity_center.y = (_arc[1].y + _arc[3].y) / 2;
}

// ������� ���������������
void Parallel::Rotate(double angle) {
	for (int i = 0; i < _shapePoints; i++) {
		double tempX = _arc[i].x;
		double tempY = _arc[i].y;
		_arc[i].x = (tempX * cos(angle * PI / 180)) + (tempY * sin(angle * PI / 180));
		_arc[i].y = (-1 * tempX * sin(angle * PI / 180)) + (tempY * cos(angle * PI / 180));
	}
	_gravity_center.x = (_arc[1].x + _arc[3].x) / 2;
	_gravity_center.y = (_arc[1].y + _arc[3].y) / 2;
}

// ���������� ���������������
Parallel::~Parallel() {
	delete[] _arc;
}