// Lab_05_2.cpp
// < Кузів Назар >
// Лабораторна робота № 5.2
// Функції, що містять арифметичний вираз
// Варіант 6

#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>

using namespace std;

void S(const double x, const double eps, int &n, double &s);
void A(const double x, const int n, double &a);

int main()
{
	SetConsoleOutputCP(1251);
	double xp, xk, x, dx, eps, s = 0;
	int n;


	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(28) << "Ряд Тейлора" << setw(15) << "|" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << "   |"
		<< setw(9) << "log(1 - x)" << "  |"
		<< setw(7) << "s" << "    |"
		<< setw(5) << "n" << "    |"
		<< endl;
	cout << "-------------------------------------------------" << endl;

	x = xp;
	while (x <= xk && x >= -1 && x < 1)
	{
		

		S(x, eps, n, s);

		

		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(4) << log(1 - x) << " |"
			<< setw(10) << setprecision(4) << s << " |"
			<< setw(5) << n << "    |"
			<< endl;
		x += dx;
	}
	cout << "-------------------------------------------------" << endl;
	return 0;
}

void S(const double x, const double eps, int &n, double &s)
{
	n = 1;
	double a = x;
	s = a;
	do {
		n++;
		A(x, n, a);
		s += a;
		
	} while (abs(a) >= eps);
	s *= -1;
}

void A(const double x, const int n, double &a)
{
	double R = x * (n - 1.) / n;
	a *= R;
}