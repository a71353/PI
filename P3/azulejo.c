#include <stdio.h>
#include <math.h>

int sum_positive_integers(int n)
{
	return n==0 ? 0 : n + sum_positive_integers(n-1);
}

int sum_multiples(int r, int n)
{
	return n==0 ? 0 : r * sum_positive_integers(n-1);
}

int sum_progression(int x0, int r, int n)
{
	return (n*x0) + sum_multiples(r, n);
}

int blue(int x, int y)
{
    if (x>=y)
    {
        return (((x-y) + 1 - (y%2))/2) * y + sum_progression(1, 4, round(y/2.0));
    }
	else
    {
        return 0;
    }
}

int yellow(int x, int y)
{
    if (x>=y)
    {
        return x*y - blue(x, y);
    }
	else
    {
        return 0;
    }
}

void test_azulejo()
{
	int x;
	int y;
	while(scanf("%d%d", &x, &y) != EOF)
	{
	    if (x>=y)
        {
           int z1 = blue(x, y);
	       int z2 = yellow(x, y);
           printf("%d %d\n", z1, z2);
        }
	    else
	    {
	        printf("A largura nao pode ser maior do que o comprimento.\n");
	    }
	}
}

int main(void)
{
    test_azulejo();
    return 0;
}