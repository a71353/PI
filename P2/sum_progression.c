#include <stdio.h>

int sum_positive_integers(int n)
{
	return n==0 ? 0 : n + sum_positive_integers(n-1);
}

int sum_multiples(int r, int n)
{
	return n==0 ? 0 : r * sum_positive_integers(n-1);   //n-1 para o primeiro número ser 0, s for n, o primeiro número é o próprio número
}

int sum_progression(int x0, int r, int n)
{
	return (n*x0) + sum_multiples(r, n);
}

void test_sum_progression()
{
	int x0;
	int r;
	int n;
	while(scanf("%d%d%d", &x0, &r, &n) != EOF)
	{
	    int z = sum_progression(x0,r,n);
	    printf("%d\n", z);
	}
}

int main (void)
{
	test_sum_progression();
	return 0;
}


//http://www.matematicadidatica.com.br/ProgressaoAritmetica.aspx
