#include <stdio.h>

#include "our_doubles.h"

/*int doubles_get(double *a)
{
  int result = 0;
  double x;
  while (scanf("%lf", &x) != EOF)
  {
  		a[result++] = x;
  }
  return result;
}*/

double door(double *a, int n)
{
	int result = 0;
	for(int i = 0; i < n; i+=2)
	{
		if(a[i] > a[i+1])
		{
			result++;
		}
	}
	return result;
}

double window(double *a, int n)
{
	int result = 0;
	for(int i = 0; i < n; i+=2)
	{
		if(a[i] <= a[i+1])
		{
			result++;
		}
	}
	return result;
}

void test_deteta()
{
	double a[1000];
	double x = doubles_get(a);
	int z1 = door(a, x);
	int z2 = window(a, x);
	printf("%d %d\n", z1, z2);
}

int main(void)
{
	test_deteta();
	return 0;
}

