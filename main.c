#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double func(double x)
{
	double y;
	y = pow(x, 2);
	y = y * pow(2, x);
	y = y - 1;
	return y;
}
double dichmeth(double a, double b, double eps)
{
	double x;
	double f;

	x = (a + b) / 2;
	if (fabs(func(x)) <= eps) return x;
	else if (func(a) < 0)
	{
		if (func(x) > 0)
		{
			b = x;
			x = dichmeth(a, b, eps);
			return x;
		}
		else
		{
			a = x;
			x = dichmeth(a, b, eps);
			return x;
		}
	}
	else
	{
		if (func(x) < 0)
		{
			b = x;
			x = dichmeth(a, b, eps);
			return x;
		}
		else
		{
			a = x;
			x = dichmeth(a, b, eps);
			return x;
		}
	}
}
double func1(double x)
{
	double y = exp(x) / x;
	return y;
}
double integral(double a, double b, double eps, double s, int n)
{
	double sum;
	double h = (b - a) / n;
	double f = 0.;
	for (int i = 0; i < n; i++) f = func1(a + (h*i) + (h / 2));
	sum = h * f;
	if (abs(s - sum) <= eps) return sum;
	else
	{
		n += 5;
		sum = integral(a, b, eps, sum, n);
		return sum;
	}
}
int main()
{
	//for dichotomy: x^2 * 2^x - 1 (func())
	double f;
	double x;
	double a = 0.;
	double b = 1.;
	double eps = 0.0001;
	//for integral: (e^x)/x (func1())
	double s = 0.;	//square
	double a1 = 1.;
	double b1 = 7.;
	double eps1 = 0.0005;
	int n = 10;		//count of the pices

	x = dichmeth(a, b, eps);
	printf("root of the equation: %f\n", x);

	s = integral(a1, b1, eps1, s, n);
	printf("\nthe integral value: %f\n", s);

	system("pause");
	return 0;
}