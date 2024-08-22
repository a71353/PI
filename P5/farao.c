#include <stdio.h>

double sum_progression_dbl(double x0, double r, int n)
{
	return n==0 ? 0 : x0 + sum_progression_dbl(x0 + r, r, n-1);
}

double sum_squares_from(double x, int n)
{
	return n == 0 ? 0 : (x*x) + sum_squares_from(x+1, n-1);
}

int marmorec(int x)
{
	return sum_progression_dbl(4, 4, (x-1)) + 1;
}

int marmoreb(int x)
{
	return sum_squares_from(1, x-2);
}

int custo(int x, int y, int z)
{
    return y * marmoreb(x) + z * marmorec(x);
}

void test_custo()
{
	int x;
	int y;
	int z;
	while(scanf("%d%d%d", &x, &y, &z) != EOF)
	{
	    int z1 = custo(x, y, z);
	    printf("%d\n", z1);
	}
}

int main(void)
{
	test_custo();
	return 0;
}