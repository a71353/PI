#include <stdio.h>
#include <math.h>

double sum_progression_dbl(double x0, double r, int n)
{
	return n==0 ? 0 : x0 + sum_progression_dbl(x0 + r, r, n-1);
}

int yellow(int x, int y)
{
	return (x-1) + sum_progression_dbl((y-4), -2, (y/2)-1) + sum_progression_dbl((x-2), -2, (y/2)-1);
}

int blue(int x, int y)
{
	return (x*y) - yellow(x, y);
}

void test_mosaico()
{
	int x;
	int y;
	while(scanf("%d%d", &x, &y) != EOF)
	{
	    int z1 = yellow(x, y);
	    int z2 = blue(x, y);
	    printf("%d %d\n", z2, z1);
	}
}

int main(void)
{
	test_mosaico();
	return 0;
}