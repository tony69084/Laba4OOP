#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cmath>
#include <iostream>

using namespace std;

class Rational
{
private:

	int sign;
	int intPart;
	int numerator;
	int denominator;
	void GetMixedView();
	void Cancellation();
	void GetIntPart();

public:

	Rational();
	Rational(int n, int d, int i, int s);
	int getSign() const;
	int getIntPart() const;
	int getNumerator() const;
	int getDenominator() const;
	Rational FromDoubleToRational(double num);

	Rational operator + (Rational);
	Rational operator - (Rational);
	Rational operator * (Rational);

	operator double();
	friend ostream& operator<<(ostream& out, const Rational& a);
};