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
	cout << "���������� ���������� �������������:" << endl;
	cout << "��������� a1 = " << a1.GetNominator() << "    " << "����������� �1 = " << a1.GetDenominator() << endl;
	cout << "��������� a2 = " << a2.GetNominator() << "    " << "����������� �2 = " << a2.GetDenominator() << endl;
	cout << "��������� a3 = " << a3.GetNominator() << "    " << "����������� �3 = " << a3.GetDenominator() << endl;
	cout << "\n������� ��������������� �������:\n" << "y(x) = 2.2*x^2 + x - 1" << endl;
	cout << "������� �������� �:" << endl; cin >> a4;
	cout << "��������� = " << a4.GetNominator() << "    " << "����������� = " << a4.GetDenominator() << endl;
	cout << "��������� ����������: " << y1(a4) << endl;
	cout << "�������� ��������� �(1) = " << y2(1) << endl;
}
double y2(double x)
{
	return  2.2 * (x * x) + x - 1;
}
Rational y1(const Rational& x)
{
	return ((x * x) * 22 / 10) + x - 1;
}
