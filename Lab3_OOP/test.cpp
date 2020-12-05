/*
* ����� ����������� �����������, �����, ������� ��� ���
* ��������� ������ ����������
* �������� 21.09.2020
*/

// shape.h

#ifndef VAR15_SHAPE_H
#define VAR15_SHAPE_H

// ��������� ��� ��������� ������������ �����
#define EPS 0.1e-30f

#include <iostream>
#include <cstddef>

// ��������� �����, �������� ���������� ����� � �.�
struct Point
{
    double x = 0, y = 0;

    // �������� ��������� ����� � �������
    bool in_polygon(const Point* poly, size_t p_size) const;
};

// ������� �������� ������� �����
Point* rotate(Point* point, size_t p_size, double angle);

// ����������� ����� �����
class Shape
{
public:
    // �����������
    explicit Shape(Point* points, size_t size);

    // ����������
    virtual ~Shape();

    // ��������� ����� �������� ������
    static Shape* createShape(Point*, char);

    // ����������� �������
    virtual double get_area() const = 0;

    // ��������� ���������
    double get_perimeter() const;

    // ����������� ������� ��������� ���������� � ������
    virtual const char* info() = 0;

    // ��������� ��������� �� ������ ������� �����
    const Point* get_points() const;

    // ��������� ������ ������
    const Point& get_center() const;

    // ��������� ���������� ����� ������
    size_t get_size() const;

    // �������� ������ �� ���. ������
    void move_to(Point to);

protected:
    // ������
    size_t _size;
    // ����� ���������� � ������� 1.
    // � ������� 0 ��������
    Point* _points = nullptr;
    // ������������� ������ (�� ���� ����� ��, �� �� ���� � �������)
    char _id;
};

// ����������� ���������� ����� ����� �������
double distance(Point p1, Point p2);

#endif //VAR15_SHAPE_H

// shape.cpp
#include "shape.h"
#include "octagon.h"
#include "rectangle.h"

#include <cmath>
#include <iostream>
#include <cstring>

// ����������� ���������� ����� ����� �������
double distance(Point p1, Point p2)
{
    // ��������� ����������� �� ������� ��������
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

/// �������� ��������� ����� � �������
// ������������ �������� ����, ��� �������
// ���� ���, ���������� �� ����� ���������� ������
// ������ ���������� ���, �� ����� ����� ��� ��������.
// ���� �� ������ - �� ����� ������
bool Point::in_polygon(const Point* poly, size_t p_size) const
{
    bool ans = false;

    /* �������� ������� ��������, ��������
     * ������������ �� ��� � �������������� �����
     * ���������� �� ����� ����� ������
     * */
    for (size_t i = 0; i < p_size; ++i)
    {
        size_t j = (i + 1) % p_size;
        if ((((poly[i].y - this->y) >= EPS && (this->y - poly[j].y) > EPS) ||
            ((this->y - poly[i].y) > EPS && (poly[j].y - this->y) >= EPS))
            && ((poly[i].y - poly[j].y) > EPS) &&
            ((((poly[i].x - poly[j].x) * (this->y - poly[j].y) / (poly[i].y - poly[j].y) + poly[j].x) - this->x) > EPS))
            ans = !ans;
    }

    return ans;
}

// ����������� �����
Shape::Shape(Point* points, size_t size)
    : _size(size), _points(points), _id(0)
{}

// ���������� �����
Shape::~Shape()
{
    delete[]_points;
}

// ������� ��������
Point* rotate(Point* points, size_t p_size, double angle)
{
    if (points != nullptr)
    {
        double new_x;
        double new_y;

        angle = angle * M_PI / 180;
        for (int i = 1; i <= p_size; ++i)
        {
            new_x = (points[i].x - points[0].x) * cos(angle) + (points[i].y - points[0].y) * sin(angle);
            new_y = -(points[i].x - points[0].x) * sin(angle) + (points[i].y - points[0].y) * cos(angle);

            points[i].x = new_x;
            points[i].y = new_y;
        }
    }
    return points;
}

//��������� �����
Shape* Shape::createShape(Point* points, char cd)
{
    Shape* sh = nullptr;
    // � ����������� �� ������, ������� �������
    switch (cd)
    {
    case 'R':
        sh = new Rectangle(points);
        break;
    case 'O':
        sh = new Octagon(points);
        break;
    default:
        break;
    }
    return sh;
}

// ��������� ������� �����.
// ����� ���������� � ������� 1.
// � ������� 0 ��������
const Point* Shape::get_points() const
{
    return _points + 1;
}

// ��������� �������
size_t Shape::get_size() const
{
    return _size;
}

// ����������� ������
void Shape::move_to(Point to)
{
    Point p_v = { to.x - _points[0].x, to.y - _points[0].y };
    _points[0] = to;
    for (int i = 1; i <= _size; ++i)
    {
        _points[i].x += p_v.x;
        _points[i].y += p_v.y;
    }
}

// ��������� ���������� ������ ������
const Point& Shape::get_center() const
{
    return _points[0];
}

// �������� ������
double Shape::get_perimeter() const
{
    const Point* p = this->get_points();
    double P = 0;
    for (size_t i = 0; i < this->get_size(); ++i)
    {
        size_t j = (i + 1) % this->get_size();
        P += distance(p[i], p[j]);
    }
    return P;
}


// rectangle.h
#ifndef VAR15_RECTANGLE_H
#define VAR15_RECTANGLE_H

#include "shape.h"

// ����� ��������������
class Rectangle : public Shape
{
public:
    // �����������
    explicit Rectangle(Point* points);
    // ����������
    const char* info() override;
    // ��������� ������
    double get_width() const;
    // ��������� ������
    double get_height() const;
    // ��������� �������
    double get_area() const override;
};

#endif //VAR15_RECTANGLE_H

// rectangle.cpp
// ����������� ��������������
Rectangle::Rectangle(Point* points) : Shape(points, 4)
{
    _id = 'R';
}

// ���������� � ��������������
const char* Rectangle::info()
{
    return "Rectangle";
}

// ��������� ������ ��������������
double Rectangle::get_height() const
{
    return distance(_points[1], _points[2]);
}

// ��������� ������ ��������������
double Rectangle::get_width() const
{
    return distance(_points[2], _points[3]);
}

// ��������� �������
double Rectangle::get_area() const
{
    return this->get_height() * this->get_width();
}


// octagon.h
#ifndef VAR15_OCTAGON_H
#define VAR15_OCTAGON_H

#include "shape.h"

// ����� ���������������
class Octagon : public Shape
{
public:
    // �����������
    explicit Octagon(Point* points);
    // ��������� ����������
    const char* info() override;
    // �������� �������
    double get_area() const override;
};


#endif //VAR15_OCTAGON_H

// octagon.cpp
#include "octagon.h"
#include "cmath"

// �����������
Octagon::Octagon(Point* points) : Shape(points, 8)
{
    _id = 'O';
}

// ����������
const char* Octagon::info()
{
    return "Octagon";
}

// ��������� ������� �� ������� ���������� ������� ����������� ��������������
double Octagon::get_area() const
{
    return 8 * pow(distance(_points[1], _points[2]), 2) / (4 * tan(M_PI / 8));
}

// console.h
#ifndef VAR15_CONSOLE_H
#define VAR15_CONSOLE_H

#include <iostream>
#include "shape.h"
#include "operations.h"

// ����� �������������� � ��������������
class Console
{
public:
    // �����������
    Console();
    // ����������
    ~Console();
    // ���� �����
    void input();
    // ��������� ������
    void run();
    // ����� ���������� � �������
    void show_info();
    // ����� ������
    static void show_commands();
    // ������� ������
    static void clear();
    // ���� ����� ��������� �����
    static Point* input_points(char);
    // ���� ����� ��� ���������������
    static Point* input_octagon();
    // ���� ����� ��� ��������������
    static Point* input_rectangle();

private:
    // ������ ���������� �� ������
    Shape** _shapes;
    // ������ ������, � ������� ���������� �������� (include � ��
    // ��� ��������
    Operations operation;
};

#endif //VAR15_CONSOLE_H

// console.cpp
#include "console.h"
#include <cmath>
#include "operations.h"

// �����������
Console::Console() : _shapes(new Shape* [2])
{
    // �������� ������ �� ��������� �� ������
    for (short i = 0; i < 2; ++i)
        _shapes[i] = nullptr;
}

// ����������
Console::~Console()
{
    for (short i = 0; i < 2; ++i)
        delete _shapes[i];

    delete[]_shapes;
}

// ���� ���������������
Point* Console::input_octagon()
{
    Point* points;
    points = new Point[9];

    std::cout << std::endl << "Input octagon." << std::endl;

    std::cout << "Input octagon's center: " << std::endl;
    std::cout << "x = ";
    std::cin >> points[0].x;
    std::cout << "y = ";
    std::cin >> points[0].y;

    double a;
    std::cout << "Input size of octagon's side: ";
    std::cin >> a;

    double radius = a / (2 * sin(M_PI / 8));

    points[1].x = points[0].x;
    points[1].y = points[0].y - radius;

    points[2].x = points[0].x - radius * sin(M_PI / 4);
    points[2].y = points[0].y - radius * sin(M_PI / 4);

    points[3].x = points[0].x - radius;
    points[3].y = points[0].y;

    points[4].x = points[0].x - radius * sin(M_PI / 4);
    points[4].y = points[0].y + radius * sin(M_PI / 4);

    points[5].x = points[0].x;
    points[5].y = points[0].y + radius;

    points[6].x = points[0].x + radius * sin(M_PI / 4);
    points[6].y = points[0].y + radius * sin(M_PI / 4);

    points[7].x = points[0].x + radius;
    points[7].y = points[0].y;

    points[8].x = points[0].x + radius * sin(M_PI / 4);
    points[8].y = points[0].y - radius * sin(M_PI / 4);

    double angle = 0;
    std::cout << "Which angle of rotation set for this octagon? Angle:";
    std::cin >> angle;
    if (angle != 0)
        rotate(points, 8, angle);
    return points;
}

// ���� ����� ��������������
Point* Console::input_rectangle()
{
    Point* points;
    points = new Point[5];

    double height = 0, weight = 0;
    std::cout << std::endl << "Input rectangle." << std::endl;

    std::cout << "Input center of rectangle:" << std::endl;
    std::cout << "x = ";
    std::cin >> points[0].x;
    std::cout << "y = ";
    std::cin >> points[0].y;

    std::cout << "Input width and height:" << std::endl;
    std::cout << "width = ";
    std::cin >> weight;
    std::cout << "height = ";
    std::cin >> height;

    weight /= 2;
    height /= 2;

    points[1].x = points[0].x - weight;
    points[1].y = points[0].y - height;

    points[2].x = points[0].x - weight;
    points[2].y = points[0].y + height;

    points[3].x = points[0].x + weight;
    points[3].y = points[0].y + height;

    points[4].x = points[0].x + weight;
    points[4].y = points[0].y - height;

    double angle = 0;
    std::cout << "Which angle of rotation set for this rectangle? Angle:";
    std::cin >> angle;
    if (angle != 0)
        rotate(points, 4, angle);
    return points;
}

// ������� ������
void Console::clear()
{
    system("clear");
}

// ���� ����� ���������� ������
Point* Console::input_points(char type)
{
    Point* points;

    switch (type)
    {
    case 'O':
        points = Console::input_octagon();
        break;
    case 'R':
        points = Console::input_rectangle();
        break;
    default:
        points = nullptr;
    }

    return points;
}

// ���� ������
void Console::input()
{

    for (short i = 0; i < 2; ++i)
    {
        std::cout << std::endl;
        std::cout << "Input figure �" << i + 1 << std::endl;
        std::cout << "Type of figure: R (Rectangle), O (Octagon): ";

        char type;
        std::cin >> type;

        if (_shapes[i] != nullptr)
            delete _shapes[i];

        _shapes[i] = Shape::createShape(Console::input_points(type), type);
    }
}

// ����� ������
void Console::show_commands()
{
    std::cout << "========================================\n\n";
    std::cout << "Commands\n";
    std::cout << "1. Input shapes\n";
    std::cout << "2. Show shapes information\n";
    std::cout << "3. Move shape #1\n";
    std::cout << "4. Move shape #2\n";
    std::cout << "5. Check include\n";
    std::cout << "6. Check intersect\n";
    std::cout << "7. Compare areas\n";
    std::cout << "8. Clear screen\n";
    std::cout << "0. Exit\n";
}

// ����� ���������� � �������
void Console::show_info()
{
    for (int i = 0; i < 2; ++i)
    {
        if (_shapes[i] != nullptr)
        {
            std::cout << "Shape #" << i + 1 << std::endl;
            std::cout << _shapes[i]->info() << std::endl;
        }
    }
}

// ������ �������
void Console::run()
{
    Console::clear();
    show_commands();
    short op;
    // ���� ������ �������
    std::cout << ">> ";
    std::cin >> op;

    while (op)
    {
        try
        {
            switch (op)
            {
                // ���� �����
            case 1:
                this->input();
                break;

                // ���������� � �������
            case 2:
                if (_shapes[0] == nullptr || _shapes[1] == nullptr)
                    throw std::runtime_error("Shapes weren't initialized!");

                this->show_info();
                break;

                // ����������� ������ ������
            case 3:

                if (_shapes[0] == nullptr)
                    throw std::runtime_error("Shape #1 wasn't initialized!");
                else
                {
                    Point p_to;
                    std::cout << "Move to\n\tx =";
                    std::cin >> p_to.x;
                    std::cout << "\ty = ";
                    std::cin >> p_to.y;
                    _shapes[0]->move_to(p_to);
                }
                break;

                // ����������� ������ ������
            case 4:

                if (_shapes[1] == nullptr)
                    throw std::runtime_error("Shape #2 wasn't initialized!");
                else
                {
                    Point p_to;
                    std::cout << "Move to\n\tx =";
                    std::cin >> p_to.x;
                    std::cout << "\ty = ";
                    std::cin >> p_to.y;
                    _shapes[1]->move_to(p_to);
                }

                break;

                // �������� ��������� �����
            case 5:
                if (_shapes[0] == nullptr || _shapes[1] == nullptr)
                    throw std::runtime_error("Shapes weren't initialized!");

                if (operation.isInclude(*_shapes[0], *_shapes[1]))
                    std::cout << _shapes[0]->info() << "(2) include " << _shapes[1]->info() << "(1)" << std::endl;
                else if (operation.isInclude(*_shapes[1], *_shapes[0]))
                    std::cout << _shapes[1]->info() << "(1) include " << _shapes[0]->info() << "(2)" << std::endl;
                else
                    std::cout << "There no including shapes" << std::endl;
                break;

                // �������� �����������
            case 6:
                if (_shapes[0] == nullptr || _shapes[1] == nullptr)
                    throw std::runtime_error("Shapes weren't initialized!");

                if (operation.isInsert(*_shapes[0], *_shapes[1]))
                    std::cout << _shapes[0]->info() << "(1) insert " << _shapes[1]->info() << "(2)" << std::endl;
                else
                    std::cout << _shapes[0]->info() << "(1) don't insert " << _shapes[1]->info() << "(2)"
                    << std::endl;

                break;

                // ��������� ��������
            case 7:
                if (_shapes[0] == nullptr || _shapes[1] == nullptr)
                    throw std::runtime_error("Shapes weren't initialized!");

                switch (operation.compareAreas(*_shapes[0], *_shapes[1]))
                {
                case 1:
                    std::cout << "Area of " << _shapes[0]->info() << "(1) bigger than " << _shapes[1]->info()
                        << "(2)" << std::endl;
                    break;

                case 2:
                    std::cout << "Area of " << _shapes[1]->info() << "(2) bigger than " << _shapes[0]->info()
                        << "(1)" << std::endl;
                    break;
                case 3:
                    std::cout << "Area of " << _shapes[0]->info() << "(1) equals " << _shapes[1]->info()
                        << "(2)" << std::endl;
                    break;
                }
                break;

                // ������� ������
            case 8:
                Console::clear();
                Console::show_commands();
                break;

            default:
                std::cout << "Incorrect command" << std::endl;
                break;
            }
        }
        catch (std::exception& ex)
        {
            std::cout << ex.what() << std::endl;
        }

        std::cout << ">> ";
        std::cin >> op;
    }

}

// operations.h
#ifndef VAR15_OPERATIONS_H
#define VAR15_OPERATIONS_H

#include "shape.h"

class Operations
{
public:
    bool isInclude(Shape& from, Shape& in);

    bool isInsert(Shape& a, Shape& b);

    int compareAreas(Shape& from, Shape& with);
};

#endif //VAR15_OPERATIONS_H


// operations.cpp

#include "operations.h"
#include "shape.h"

// �������� �� �������� ������ from � ������ in
bool Operations::isInclude(Shape& from, Shape& in)
{
    for (int i = 0; i < from.get_size(); ++i)
    {
        if (!from.get_points()[i].in_polygon(in.get_points(), in.get_size()))
            return false;
    }
    return true;
}

// �������� ����������� �����
bool Operations::isInsert(Shape& a, Shape& b)
{
    // ���������, �������� �� �����-���� ����� ������ b � ������ a
    if (b.get_center().in_polygon(a.get_points(), a.get_size()))
        return true;
    for (int i = 0; i < b.get_size(); ++i)
        if (b.get_points()[i].in_polygon(a.get_points(), a.get_size()))
            return true;

    // ���������, �������� �� ����� ������ a � ������ b
    if (a.get_center().in_polygon(b.get_points(), b.get_size()))
        return true;
    for (int i = 0; i < a.get_size(); ++i)
        if (a.get_points()[i].in_polygon(b.get_points(), b.get_size()))
            return true;

    // ���� �� ����� ���������, ���������� false
    return false;
}

// �������� ��������� �������� �����
// ��� �������� 1 ��������, ��� ������ ������ ������ ������
// ��� �������� 2 ��������, ��� ������ ������ ������ ������
// ��� �������� 3 ��������, ��� ������ �����
int Operations::compareAreas(Shape& from, Shape& with)
{
    if ((from.get_area() - with.get_area()) > EPS) return 1;
    else if ((with.get_area() - from.get_area()) > EPS) return 2;
    else return 3;
}




