#include <stdio.h>
#include <math.h>

double velocidade(double x, int y)
{
	return y == 0 ? 0 : (1 / (x * pow(0.9, y-1))) + velocidade(x,y-1);
}

void test_velocidade()
{
	double x;
	int y;
	while(scanf("%lf%d", &x, &y) != EOF)
	{
	    double z = velocidade(x, y);
	    printf("%lf\n", z);
	}
}

int main(void)
{
	test_velocidade();
	return 0;
}
