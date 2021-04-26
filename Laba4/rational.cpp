#include <iostream>
#include <cmath>
#include "Rational.h"
using namespace std;
Rational::Rational() //конструктор по умолчанию
{
	nominator = 0;
	denominator = 1;
}
Rational::Rational(int nominator) //конструктор с параметром nominator
{
	this->nominator = nominator;
	denominator = 1;
}
Rational::Rational(int nominator, int denominator) //конструктор для обоих параметров
{
	this->nominator = nominator;
	this->denominator = denominator;
}
int Rational::GetNominator() const
{
	return nominator;
}
int Rational::GetDenominator() const
{
	return denominator;
}
void Rational::drob() //процедура сокращения
{
	if (nominator != 0)
	{
		int m = denominator, n = nominator, ost = m % n;
		while (ost != 0)
		{
			m = n;
			n = ost;
			ost = m % n;
		}
		int NOD = n;
		if (NOD != 1)
		{
			nominator /= NOD;
			denominator /= NOD;
		}
	}
}
ostream& operator<<(ostream& out, const Rational& Rational) //операция вывода
{
	out << Rational.nominator << "/" << Rational.denominator;
	return out;
}
istream& operator>>(istream& in, Rational& Rational) //операция ввода
{
	in >> Rational.nominator >> Rational.denominator;
	return in;
}
Rational operator+(Rational a, Rational b) //перегрузка операции +
{
	return Rational(a.GetNominator() * b.GetDenominator() + b.GetNominator() * a.GetDenominator(), a.GetDenominator() * b.GetDenominator());
}
Rational operator-(Rational a, Rational b) //перегрузка операции -
{
	return Rational(a.GetNominator() * b.GetDenominator() - b.GetNominator() * a.GetDenominator(), a.GetDenominator() * b.GetDenominator());
};
Rational operator*(Rational a, Rational b) //перегрузка операции *
{
	return Rational(a.GetNominator() * b.GetNominator(), a.GetDenominator() * b.GetDenominator());
}
Rational operator/(Rational a, Rational b) //перегрузка операции /
{
	return Rational(a.GetNominator() * b.GetDenominator(), a.GetDenominator() * b.GetNominator());
}
