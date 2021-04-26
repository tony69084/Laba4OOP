#include <iostream>
#include <cmath>
#include "Rational.h"
using namespace std;
Rational y1(const Rational& x);
double y2(double x);
int main()
{
	setlocale(LC_ALL, "RUS");
	Rational a1;
	Rational a2(2);
	Rational a3(1, 2);
	Rational a4;
	cout << "Результаты выполнения конструкторов:" << endl;
	cout << "Числитель a1 = " << a1.GetNominator() << "    " << "Знаменятель а1 = " << a1.GetDenominator() << endl;
	cout << "Числитель a2 = " << a2.GetNominator() << "    " << "Знаменатель а2 = " << a2.GetDenominator() << endl;
	cout << "Числитель a3 = " << a3.GetNominator() << "    " << "Знаменятель а3 = " << a3.GetDenominator() << endl;
	cout << "\nВариант индивидуального задания:\n" << "y(x) = 2.2*x^2 + x - 1" << endl;
	cout << "Введите значение х:" << endl; cin >> a4;
	cout << "Числитель = " << a4.GetNominator() << "    " << "Знаменатель = " << a4.GetDenominator() << endl;
	cout << "Результат вычислений: " << y1(a4) << endl;
	cout << "Значение выражение у(1) = " << y2(1) << endl;
}
double y2(double x)
{
	return  2.2 * (x * x) + x - 1;
}
Rational y1(const Rational& x)
{
	return ((x * x) * 22 / 10) + x - 1;
}
