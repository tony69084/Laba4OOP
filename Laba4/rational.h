#include <iostream>
#include <cmath>
class Rational
{
private:
	int nominator;
	int denominator;
	void drob();
public:
	Rational();
	Rational(int);
	Rational(int, int);
	int GetNominator() const;
	int GetDenominator() const;
	friend std::ostream& operator<<(std::ostream& out, const Rational& Rational);
	friend std::istream& operator>>(std::istream& in, Rational& Rational);
	friend Rational operator+(Rational a, Rational b);
	friend Rational operator-(Rational a, Rational b);
	friend Rational operator*(Rational a, Rational b);
	friend Rational operator/(Rational a, Rational b);
};
