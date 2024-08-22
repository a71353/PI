#include <stdio.h>
#include <math.h>

#define TAX 0.00315

double round_unidades(double x)
{
	return floor(x);
}

double desconto(double x, int y)
{
	double valor;
	if(y==0)
	{
	    valor = 0;
	}
	if(y==1)
	{
	    valor = x * TAX * 0.1;
	}

	if(y==2)
	{
	    valor = x * TAX * 0.15;
	}

	if(y>=3)
	{
	    valor = x * TAX * 0.2;
	}
	return valor;
}

double imi(double x, int y)
{
	if(desconto(x, y)<=80)
	{
	    return round_unidades(x * TAX - desconto(x, y));
	}

	else
	{
	    return round_unidades((x * TAX) - 80);
	}
}

void test_imi()
{
	double x;
	int y;
	while(scanf("%lf%d", &x, &y) != EOF)
	{
	    double z = imi(x, y);
	    printf("%.0lf\n", z);
	}
}

int main(void)
{
	test_imi();
	return 0;
}