#include <stdio.h>
#include <math.h>

double sum_powers(int n, int x)
{
	return n==0 ? 0 : pow(n,x) + sum_powers(n-1, x);
}

double sum_inverses(int n)
{
	return n==0 ? 0 : sum_powers(n,-1);
}    

void test_sum_inverses()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		double z = sum_inverses(n);
		printf("%f\n", z);
	}
}

int main(void)
{
	test_sum_inverses();
	return 0;
}
