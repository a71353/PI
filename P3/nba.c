#include <stdio.h>
#include <math.h>

double round(double x)
{
	return floor(x+0.5);
}

double round_cent(double x)
{
	return (round(x)*100)/100;
}

double nba(double x, double y)
{
	return round_cent(x*12*2.54 + y*2.54) /100;
}

void test_nba()
{
	double x;
	double y;
	while(scanf("%lf%lf", &x, &y) != EOF)
	{
	    double z = nba(x,y);
	    printf("%lf\n", z);
	}
}

int main(void)
{
	test_nba();
	return 0;
}