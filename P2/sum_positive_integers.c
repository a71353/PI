#include <stdio.h>

int sum_positive_integers(int x)
{
	return x==0 ? 0 : x + sum_positive_integers(x-1);
}

void test_sum_positive_integers()
{
	int x;
	while(scanf("%d", &x) != EOF)
	{
		int z = sum_positive_integers(x);
		printf("%d\n", z);
	}
}
int main (void)
{
	test_sum_positive_integers();
	return 0;
}
