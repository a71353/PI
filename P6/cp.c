#include <stdio.h>
#include <math.h>

double round_two_decimals(double x)
{
	return ceil((x)*2)/2;
}

double ida(double x)
{
	return round_two_decimals(x * 0.087);
}

double idaevolta(double x)
{
	return round_two_decimals(ida(x) * 2 * 0.85);
}

void test_price()
{
	int x;
	while(scanf("%d", &x) != EOF)
	{
	   double z1 = ida(x);
	   double z2 = idaevolta(x);
	   printf("%.2lf %.2lf\n", z1, z2);
	}
}

int main (void)
{
	test_price();
	return 0;
}