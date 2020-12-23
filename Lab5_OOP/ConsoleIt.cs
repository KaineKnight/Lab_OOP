using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Triangles;

namespace ConsoleIt
{
	class ConsoleI
	{
		public ConsoleI()
		{

		}
		private static Triangle triangle = null;
		public static void RunProgram()
		{
			int Operation;
			do
			{
				Console.WriteLine("================Triangle================");
				Console.WriteLine("Какой треугольник желаете посчитать?");
				Console.WriteLine("-------------------------------------");
				Console.WriteLine("1. Разносторонний.");
				Console.WriteLine("2. Равносторонний.");
				Console.WriteLine("3. Равнобедренный.");
				Console.WriteLine("4. Прямоугольный.");
				Console.WriteLine("0. Выйти.");
				Console.WriteLine("-------------------------------------");
				Console.WriteLine(">> ");
				
				Operation = int.Parse(Console.ReadLine());
				int a, b, angle;
				if (triangle != null)
				{
					triangle = null;
				}

				switch(Operation)
				{
					case 0:
						Console.WriteLine("Осуществляется выход...");
						break;
					case 1:
						Console.Clear();
						Console.WriteLine("Разносторонний треугольник");
						Console.WriteLine("Введите, пожалуйста, длины двух сторон и угол между ними (в градусах)");
						Console.WriteLine("a = ");
						a = int.Parse(Console.ReadLine());
						Console.WriteLine("b = ");
						b = int.Parse(Console.ReadLine());
						Console.WriteLine("angle = ");
						angle = int.Parse(Console.ReadLine());
						triangle = new Triangle(a, b, angle);


						Console.WriteLine("Что вы желаете найти?");
						Console.WriteLine("1. Площадь.");
						Console.WriteLine("2. Периметр.");
						Console.WriteLine("0. Отмена.");
						int triOp1;
						do
						{
							Console.WriteLine(">> ");
							triOp1 = int.Parse(Console.ReadLine());
							switch (triOp1)
							{
								case 0:
									break;
								case 1:
									Console.WriteLine(triangle.Area());
									break;
								case 2:
									Console.WriteLine(triangle.Perimeter());
									break;
								default:
									Console.WriteLine("Неверная команда.");
									break;
							}
						} while (triOp1 != 0);


						break;
					case 2:
						Console.Clear();
						Console.WriteLine("Равносторонний треугольник.");
						Console.WriteLine("Введите, пожалуйста, длину cтороны");
						Console.WriteLine("a = ");
						a = int.Parse(Console.ReadLine());
						triangle = new Equilateral(a);


						Console.WriteLine("Что вы желаете найти?");
						Console.WriteLine("1. Площадь.");
						Console.WriteLine("2. Периметр.");
						Console.WriteLine("0. Отмена.");
						int triOp2;
						do
						{
							Console.WriteLine(">> ");
							triOp2 = int.Parse(Console.ReadLine());
							switch (triOp2)
							{
								case 0:
									break;
								case 1:
									Console.WriteLine(triangle.Area());
									break;
								case 2:
									Console.WriteLine(triangle.Perimeter());
									break;
								default:
									Console.WriteLine("Неверная команда.");
									break;
							}
						} while (triOp2 != 0);

						break;
					case 3:
						Console.Clear();
						Console.WriteLine("Равнобедренный треугольник.");
						Console.WriteLine("Введите, пожалуйста, длину  равных сторон и угол между ними (в градусах)");
						Console.WriteLine("a = ");
						a = int.Parse(Console.ReadLine());
						Console.WriteLine("angle = ");
						angle = int.Parse(Console.ReadLine());
						triangle = new Isosceles(a, angle);

						Console.WriteLine("Что вы желаете найти?");
						Console.WriteLine("1. Площадь.");
						Console.WriteLine("2. Периметр.");
						Console.WriteLine("0. Отмена.");
						int triOp3;
						do
						{
							Console.WriteLine(">> ");
							triOp3 = int.Parse(Console.ReadLine());
							switch (triOp3)
							{
								case 0:
									break;
								case 1:
									Console.WriteLine(triangle.Area());
									break;
								case 2:
									Console.WriteLine(triangle.Perimeter());
									break;
								default:
									Console.WriteLine("Неверная команда.");
									break;
							}
						} while (triOp3 != 0);

						break;
					case 4:
						Console.Clear();
						Console.WriteLine("Прямоугольный треугольник.");
						Console.WriteLine("Введите, пожалуйста, длины двух сторон");
						Console.WriteLine("a = ");
						a = int.Parse(Console.ReadLine());
						Console.WriteLine("b = ");
						b = int.Parse(Console.ReadLine());
						triangle = new Right(a, b);

						Console.WriteLine("Что вы желаете найти?");
						Console.WriteLine("1. Площадь.");
						Console.WriteLine("2. Периметр.");
						Console.WriteLine("0. Отмена.");
						int triOp4;
						do
						{
							Console.WriteLine(">> ");
							triOp4 = int.Parse(Console.ReadLine());
							switch (triOp4)
							{
								case 0:
									break;
								case 1:
									Console.WriteLine(triangle.Area());
									break;
								case 2:
									Console.WriteLine(triangle.Perimeter());
									break;
								default:
									Console.WriteLine("Неверная команда.");
									break;
							}
						} while (triOp4 != 0);

						break;
					default:
						Console.WriteLine("Введено неверное значение...");
						break;
				}
				Console.Clear();

			} while (Operation != 0);
		}


	}
}