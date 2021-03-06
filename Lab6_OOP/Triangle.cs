﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriangleClass
{
	abstract class Triangle
	{
		protected double _a = -1;
		protected double _b = -1;
		protected double _angle = -1;

		public abstract double Area();

		public abstract double Perimeter();

	}

	class Equilateral : Triangle 
	{
		public Equilateral() { }

		public Equilateral(double a)
		{
			_a = a;
		}

		public void SetTriangle(double a)
		{
			_a = a;
		}

		public override double Area()
		{ //площадь равностороннего треугольника
			return (_a * _a * (System.Math.Sqrt(3)) / 4);
		}

		public override double Perimeter()
		{ //периметр равностороннего треугольника
			return 3 * _a;
		}

	}

	class Isosceles : Triangle
	{
		public Isosceles() { }

		public Isosceles(double a, double angle) 
		{
			_a = a;
			_angle = angle* System.Math.PI / 180;
		}

		public void SetTriangle(double a, double angle)
		{
			_a = a;
			_angle = angle * System.Math.PI / 180;
		}

		public override double Area()
		{ //площадь равнобедренного треугольника
			return (_a * _a * System.Math.Sin(_angle)) / 2;
		}

		public override double Perimeter()
		{ //периметр равнобедренного треугольника
			return _a + _a + (System.Math.Sqrt(2 * _a * _a * (1 - System.Math.Cos(_angle))));
		}
	}

	class Right : Triangle
	{
		public Right() { }

		public Right(double a, double b) 
		{
			_a = a;
			_b = b;
		}

		public void SetTriangle(double a, double b)
		{
			_a = a;
			_b = b;
		}

		public override double Area()
		{ //площадь прямоугольного треугольника
			return _a * _b / 2;
		}

		public override double Perimeter()
		{ //периметр прямоугольного треугольника
			return _a + _b + (System.Math.Sqrt(_a * _a + _b * _b));
		}

	}

}
