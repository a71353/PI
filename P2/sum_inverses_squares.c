#include <stdio.h>
#include <math.h>

double sum_powers(int n,double x)
{
	return n == 0 ? 0 : pow(n,x) + sum_powers(n-1, x);
}

double sum_inverses_squares(int n)
{
	return n == 0 ? 0 : sum_powers(n,-2);         //-2 por causa do x, para ser elevado a (-2)
}

void test_sum_inverses_squares()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		double z = sum_inverses_squares(n);
		printf("%lf\n", z);
	}
}

int main(void)
{
	test_sum_inverses_squares();
	return 0;
}
