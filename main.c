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
int main()
{
	double f;
	double x;
	double a = 0;
	double b = 1;
	double eps = 0.0001;

	x = dichmeth(a, b, eps);
	printf("root of the equation: %f\n", x);



	system("pause");
	return 0;
}