#include <iostream>
#include <cmath>
#include "rational.h"
using namespace std;

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
	intPart = 0;
	sign = 1;
}

Rational::Rational(int n, int d, int i, int s)
{
	intPart = i;
	numerator = n;
	denominator = d;
	sign = s;
	GetMixedView();
}

int Rational::getSign() const { return this->sign; }
int Rational::getIntPart() const { return this->intPart; }
int Rational::getNumerator() const { return this->numerator; }
int Rational::getDenominator() const { return this->denominator; }

Rational Rational::FromDoubleToRational(double num)
{
	double eps = 0.01;

	for (int i = 1;; i++) {
		double tem = num / (1.0 / i);
		if (fabs(tem - round(tem)) < eps) {
			return Rational(round(tem), i, 0, 0);
			break;
		}
	}
}

Rational::operator double()
{
	double res = sign * (intPart * denominator + numerator);
	return res / denominator;
}


ostream& operator << (ostream& out, const Rational& a)
{
	if (a.getSign() < 0)
	{
		out << "-";
	}
	if (a.getIntPart() != 0)
	{
		out << a.getIntPart() << " ";
	}
	if (a.getNumerator() != 0)
	{
		out << a.getNumerator() << "/" << a.getDenominator();
	}
	if (a.getIntPart() == 0 && a.getNumerator() == 0)
	{
		out << "0";
	}
	else
	{
		out << " ";
	}
	return out;
}


Rational Rational::operator + (Rational a)
{
	Rational res;
	res.numerator = sign * (intPart * denominator + numerator) * a.denominator + a.sign * (a.intPart * a.denominator + a.numerator) * denominator;
	res.denominator = denominator * a.denominator;
	if (res.numerator < 0)
	{
		res.numerator *= -1; res.sign = -1;
	}
	res.GetMixedView();
	return res;
}


Rational Rational::operator - (Rational a)
{
	Rational res;
	res.numerator = sign * (intPart * denominator + numerator) * a.denominator - a.sign * (a.intPart * a.denominator + a.numerator) * denominator;
	res.denominator = denominator * a.denominator;
	if (res.numerator < 0)
	{
		res.numerator *= -1; res.sign = -1;
	}
	res.GetMixedView();
	return res;
}

Rational Rational::operator * (Rational a)
{
	Rational res;
	res.numerator = (sign * (intPart * denominator + numerator)) * (a.sign * (a.intPart * a.denominator + a.numerator));
	res.denominator = denominator * a.denominator;
	if (res.numerator < 0)
	{
		res.numerator *= -1; res.sign = -1;
	}
	res.GetMixedView();
	return res;
}


void Rational::GetMixedView()
{
	GetIntPart();
	Cancellation();
}

void Rational::GetIntPart()
{
	if (numerator >= denominator)
	{
		intPart += (numerator / denominator);
		numerator %= denominator;
	}
}

void Rational::Cancellation()
{
	if (numerator != 0)
	{
		int m = denominator,
			n = numerator,
			ost = m % n;
		while (ost != 0)
		{
			m = n; n = ost;
			ost = m % n;
		}
		int nod = n;
		if (nod != 1)
		{
			numerator /= nod; denominator /= nod;
		}
	}
}