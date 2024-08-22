#include <stdio.h>

/*#include "our_doubles.h"*/

int doubles_get(double *a)
{
  int result = 0;
  double x;
  while (scanf("%lf", &x) != EOF)
  {
  		a[result++] = x;
  }
  return result;
}

double gasolina(double*a, int n)
{   
    int result=0;
    int i = n;
    while(a[i] <= a[i-1])
    {
        if(a[i] < a[i-1])
        {
            result++;
        }
        i--;
    }
    return result;
}


void test_gasolina()
{
	double a[1000];
	int x = doubles_get(a);
	int z = gasolina(a, x);
	printf("%d", z);
}

int main(void)
{
    test_gasolina();
    return 0;
}
