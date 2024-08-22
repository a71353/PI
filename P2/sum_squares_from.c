#include <stdio.h>

double sum_squares_from(double x, int n)
{
	return n == 0 ? 0 : (x*x) + sum_squares_from(x+1, n-1);
}

void test_sum_squares_from()
{
	double x;
	int n;
	while(scanf("%lf%d", &x, &n) != EOF)
	{
	   double z = sum_squares_from(x, n);
	   printf("%lf\n", z);
	}
}

int main(void)
{
	test_sum_squares_from();
	return 0;
}