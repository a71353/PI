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

double meta(double *a, int n, double *b)
{
    int result = 0;
    for (int i=0;i<n;i++)
    {
        if(a[i]==0)
            b[result++] = 0;
        else if (a[i]>=600.0 && a[i]>1.2*a[i-1] && a[i]>=a[i+1])
            b[result++] = a[i];
        else
            b[result++] = 0;
    }
    return result;
}

void doubles_println_basic(const double *a, int n)
{
  if (n > 0)
  {
    printf("%.1lf", a[0]);
    for (int i = 1; i < n; i++)  
      printf(" %.1lf", a[i]);
  }
  printf("\n");
}

void test_meta(void)
{
    double a[1000];
    double b[1000];
    int x = doubles_get(a);
    int z = meta(a, x, b);
    doubles_println_basic(b, z);
}

int main(void)
{
	test_meta();
	return 0;
}