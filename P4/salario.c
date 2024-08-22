#include <stdio.h>
#include <math.h>

double round_two_decimals(double x)
{
	return round(x*100)/100;
}

int minutes(int h)
{
	return h * 60;
}

int minwork(int h, int m)
{
	return minutes(h) + m - 1080;   //1080=18h
}

double salario(double s, int h, int m)
{
	if (minwork(h, m) <= 120)
	{
	    return (s/60) * minwork(h, m);
	}

	else
	{
	    return (s/60) * 120 + (minwork(h, m) - 120) * (s/60) * 1.5;
	}
}

double calcsalario(double s, int h, int m)
{
	return round_two_decimals(salario(s, h, m));
}

void test_salario()
{
	double s;
	int h;
	int m;
	while(scanf("%lf%d%d", &s, &h, &m) != EOF)
	{
		double z = calcsalario(s, h, m);
		printf("%lf\n", z);
	}
}

int main(void)
{
	test_salario();
	return 0;
}
