#include <stdio.h>
#include <math.h>

int sumsquares(int x)
{
	return (((x+1) * x * (2*x + 1))/6);
}

int sub(int x, int y)
{
	return sumsquares(y) - sumsquares(x-1);
}

int main (void)
{
	int x;
	int y;
	scanf("%d%d", &x, &y);
	int z = sub(x, y);
	printf("%d\n", z);
	return 0;
}
