#include "rational.h"

using namespace std;

double y2(double x2);

int main()
{

	Rational n1(1, 2, 0, 0);
	double x;

	cout << "y(x) = 2.2*x^2 + x + 1\nVvedite x: " << endl;
	cin >> x;

	Rational res = n1.FromDoubleToRational(y2(x));
	cout << "y(" << x << ") = " << res << endl;


	system("pause");
	return 0;
}

double y2(double x2)
{
	return 2.2*pow(x2,2)+x2-1;
}