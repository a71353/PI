#include <stdio.h>

int sum_positive_integers(int x)
{
	return x==0 ? 0 : x + sum_positive_integers(x-1);
}

int sum_multiples(int r, int n)
{
	return n==0 ? 0 : r * sum_positive_integers(n-1); 
}

void test_sum_multiples()
{
	int r;
	int n;
	while(scanf("%d%d", &r, &n) != EOF)
	{
	    int z = sum_multiples(r,n);
	    printf("%d\n", z);
	}
}

int main (void)
{
	test_sum_multiples();
	return 0;
}
