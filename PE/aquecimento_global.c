#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

#include "our_doubles.h"

/*int doubles_get_two(double *a, double *b)
{
  int result = 0;
  double x, y;
  while (scanf("%lf%lf", &x, &y) != EOF)
  {
    a[result] = x;
    b[result] = y;
    result++;
  }
  return result;
}*/

void ints_println_2(const int *a, int *b, int n)
{
  if (n > 0)
  {
    for (int i = 0; i < n; i++)
      printf("%d %d\n", a[i], b[i]);
  }
  else printf("-1\n");
}

int min30(double *a, int n)
{
  int result = 0;

  for (int i = 0; i < n; i++)
    if(a[i] >= 30) 
      result++;
    else return result >= 4? result : 0;
  return result >= 4? result : 0;
}

int max40(double *a, int n)
{
  int result = 0;
  for (int i = 0; i < n; ++i)
    if(a[i] >= 40) 
      result++;
  return result > 1?1:0;
}

int aquecimento_global(double *a, double *b, int n, int *c, int *d)
{
  int result = 0;
  int r = 0;
    for (int i = 0; i < n; i+= r+1)
  {
    r = min30(a+i,n-i);

    if(r > 0 && max40(b+i, r))
    {
      c[result] = i;
      d[result++] = r;
    }
  }

  return result;
}

void test_aquecimento_global(void)
{
  double a[40000];
  double b[40000];
  int c[40000];
  int d[40000];
  int x = doubles_get_two(a, b);
  int y = aquecimento_global(a, b, x, c, d);
  ints_println_2(c, d, y);
}

int main()
{
test_aquecimento_global();
return 0;
}