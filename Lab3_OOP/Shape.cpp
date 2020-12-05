#include "Shape.h"


/* Методы базового класса */

// Фабричный метод
Shape* Shape::CreateShape(char cd) {
	Shape* sh = 0;
	if (cd == 's') cd = 'S';
	if (cd == 'p') cd = 'P';
	switch (cd) {
	case 'S':
		sh = new Square(); break;
	case 'P':
		sh = new Parallel(); break;
	default: cout << "Ошибка ввода!\n"; break;
	}
	return sh;
}

// Проверка включения точки в фигуру
bool Point::PointInclude(Point* point, int shapePoints) {
	bool ret = 0;

	//Проходим границы полигона, проверяя
	//пересекаются ли они с горизонтальным лучем
	//выпушенным из нашей точки вправо

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

// Проверка включения фигуры в фигуру
bool Shape::IsInclude(Shape& isOut, Shape& isIn) {

	for (int i = 0; i < isOut.GetSize(); ++i) {
		if (!isOut.GetPoints()[i].PointInclude(isIn.GetPoints(), isIn.GetSize()))
			return 0;
	}
	return 1;
}

// Проверка пересечения фигур
bool Shape::IsInsert(Shape& one, Shape& two) {

	// Проверяем, включены ли какие-либо точки фигуры b в фигуре a
	if (two.GetCenter().PointInclude(one.GetPoints(), one.GetSize()))
		return true;
	for (int i = 0; i < two.GetSize(); ++i)
		if (two.GetPoints()[i].PointInclude(one.GetPoints(), one.GetSize()))
			return true;

	// Проверяем, включены ли точки фигуры a в фигуру b
	if (one.GetCenter().PointInclude(two.GetPoints(), two.GetSize()))
		return true;
	for (int i = 0; i < one.GetSize(); ++i)
		if (one.GetPoints()[i].PointInclude(two.GetPoints(), two.GetSize()))
			return true;

	// Если не нашли включение, возвращаем false
	return false;

}

// Сравнение площадей фигур
void Shape::Compare(Shape& one, Shape& two) {
	if (one.GetArea() - two.GetArea() > EPS) {
		cout << "Площадь первой фигуры больше\n";
	}
	if (one.GetArea() - two.GetArea() < EPS) {
		cout << "Площадь второй фигуры больше\n";
	}
	else {
		cout << "Площади равны\n";
	}
}


/* Методы квадрата */

// Информация о квадрате
void Square::info() {
	cout << "\nКвадрат" << endl;

	cout << "Вершина 1(x, y)\n";
	cout << _arc[0].x << "\t" << _arc[0].y << endl;
	cout << "Вершина 2(x, y)\n";
	cout << _arc[1].x << "\t" << _arc[1].y << endl;
	cout << "Вершина 3(x, y)\n";
	cout << _arc[2].x << "\t" << _arc[2].y << endl;
	cout << "Вершина 4(x, y)\n";
	cout << _arc[3].x << "\t" << _arc[3].y << endl;

	cout << "Центр тяжести фигуры (x, y)\n";
	cout << _gravity_center.x << "\t" << _gravity_center.y << endl;
}

// Конструктор квадрата
Square::Square() {
	id = 'S';
	_shapePoints = 4;
	_arc = new Point[4];
	cout << "Вершина 1(x, y)\n>> ";
	cin >> _arc[0].x >> _arc[0].y;
	cout << "Вершина 2(x, y)\n>> ";
	cin >> _arc[1].x >> _arc[1].y;
	cout << "Вершина 3(x, y)\n>> ";
	cin >> _arc[2].x >> _arc[2].y;
	cout << "Вершина 4(x, y)\n>> ";
	cin >> _arc[3].x >> _arc[3].y;

	_gravity_center.x = (_arc[1].x + _arc[3].x) / 2;
	_gravity_center.y = (_arc[1].y + _arc[3].y) / 2;
}

// Расчет и получение периметра квадрата
double Square::GetPerimeter() {
	return 4 * (sqrt((_arc[0].x - _arc[1].x) * (_arc[0].x - _arc[1].x)
		+ (_arc[0].y - _arc[1].y) * (_arc[0].y - _arc[1].y)));
}

// Расчет и получение площади квадрата
double Square::GetArea() {
	return (_arc[0].x - _arc[1].x) * (_arc[0].x - _arc[1].x)
		+ (_arc[0].y - _arc[1].y) * (_arc[0].y - _arc[1].y);
}

// Передвижение квадарата
void Square::Move(double moveX, double moveY) {
	for (int i = 0; i < _shapePoints; i++) {
		_arc[i].x += moveX;
		_arc[i].y += moveY;
	}
	_gravity_center.x = (_arc[1].x + _arc[3].x) / 2;
	_gravity_center.y = (_arc[1].y + _arc[3].y) / 2;
}

// Поворот квадрата
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

// Деструктор квадрата
Square::~Square() {
	delete[] _arc;
}


/* Методы параллелограмма */

// Информация о параллелограмме
void Parallel::info() {
	cout << "\nПараллелограмм" << endl;

	cout << "Вершина 1(x, y)\n";
	cout << _arc[0].x << "\t" << _arc[0].y << endl;
	cout << "Вершина 2(x, y)\n";
	cout << _arc[1].x << "\t" << _arc[1].y << endl;
	cout << "Вершина 3(x, y)\n";
	cout << _arc[2].x << "\t" << _arc[2].y << endl;
	cout << "Вершина 4(x, y)\n";
	cout << _arc[3].x << "\t" << _arc[3].y << endl;

	cout << "Центр тяжести фигуры(x, y)\n";
	cout << _gravity_center.x << "\t" << _gravity_center.y << endl;
}

// Конструктор параллелограмма
Parallel::Parallel() {
	id = 'P';
	_shapePoints = 4;
	_arc = new Point[4];
	cout << "Вершина 1(x, y)\n>> ";
	cin >> _arc[0].x >> _arc[0].y;
	cout << "Вершина 2(x, y)\n>> ";
	cin >> _arc[1].x >> _arc[1].y;
	cout << "Вершина 3(x, y)\n>> ";
	cin >> _arc[2].x >> _arc[2].y;
	cout << "Вершина 4(x, y)\n>> ";
	cin >> _arc[3].x >> _arc[3].y;

	_gravity_center.x = (_arc[1].x + _arc[3].x) / 2;
	_gravity_center.y = (_arc[1].y + _arc[3].y) / 2;
}

// Расчет и получение периметра параллелограмма
double Parallel::GetPerimeter() {
	return 2 * (sqrt((_arc[0].x - _arc[1].x) * (_arc[0].x - _arc[1].x)
		+ (_arc[0].y - _arc[1].y) * (_arc[0].y - _arc[1].y))) +
		2 * (sqrt((_arc[1].x - _arc[1].x) * (_arc[1].x - _arc[2].x)
			+ (_arc[1].y - _arc[2].y) * (_arc[1].y - _arc[2].y)));
}

// Расчет и получение площади параллелограмма
double Parallel::GetArea() {
	return abs(_arc[0].y - _arc[1].y) * sqrt((_arc[0].x - _arc[3].x) * (_arc[0].x - _arc[3].x)
		+ (_arc[0].y - _arc[3].y) * (_arc[0].y - _arc[3].y));
}

// Передвижение паралелограмма
void Parallel::Move(double moveX, double moveY) {
	for (int i = 0; i < _shapePoints; i++) {
		_arc[i].x += moveX;
		_arc[i].y += moveY;
	}
	_gravity_center.x = (_arc[1].x + _arc[3].x) / 2;
	_gravity_center.y = (_arc[1].y + _arc[3].y) / 2;
}

// Поворот параллелограмма
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

// Деструктор параллелограмма
Parallel::~Parallel() {
	delete[] _arc;
}