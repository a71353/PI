#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "our_doubles.h"
#include "our_ints.h"

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

double total_precipitacao1(const double *a, int n, double *c)
{
	double result = 0;
  	for (int i = 0; i < n; i++)
    	result += a[i];
  	return result;
}

double total_precipitacao2(const double *b, int m, double *c)
{
	double result = 0;
 	 for (int i = 0; i < m; i++)
    	result += b[i];
  	return result;
}

double precipitacao_maxima1(const double *a, int n, double *c)
{
	assert(n > 0);
  	double result = a[0];
  	for (int i = 1; i < n; i++)  // i = 1
    	if (result < a[i])
     	 result = a[i];
  	return result;
}

double precipitacao_maxima2(const double *b, int m, double *c)
{
	assert(m > 0);
	double result = b[0];
  	for (int i = 1; i < m; i++)  // i = 1
    	if (result < b[i])
      	result = b[i];
  	return result;
}

int dias_choveu1(const double *a, int n)
{
	int result = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] > 0)
			result++;
	return result;
}

int dias_choveu2(const double *b, int m)
{
	int result = 0;
	for (int i = 0; i < m; ++i)
		if (b[i] > 0)
			result++;
	return result;
}
  
int runs(const double *a, int n)
{
  int result = 0;
  while (result < n && a[result] > 0)
    result++;
  return result;
}

int dias_seguidos1(const double *a, int n, int *c)
{
	int result = 0;
	int i = 0;
	while (i < n)
	if (a[i] > 0)
	{
		int z = runs(a+i, n-i);
		c[result++] = z;
		i += z;
	}
	else
	i++;
	return result;
}

int dias_seguidos2(const double *b, int m, int *c)
{
	int result = 0;
	int i = 0;
	while (i < m)
	if (b[i] > 0)
	{
		int z = runs(b+i, m-i);
		c[result++] = z;
		i += z;
	}
	else
	i++;
return result;
}

void test_chuva(void)
{
	double a[1000];
	double b[1000];
	int x = doubles_get_two(a, b);
	double c[1000];
	double y1 = total_precipitacao1(a, x, c);
	double y2 = total_precipitacao2(b, x, c);
	printf("%0.1f %0.1f\n",y1, y2);
	double z1 = precipitacao_maxima1(a, x, c);
	double z2 = precipitacao_maxima2(b, x, c);
	printf("%0.1f %0.1f\n", z1, z2);
	int w1 = dias_choveu1(a, x);
	int w2 = dias_choveu2(b, x);
	printf("%d %d\n", w1, w2);
	int d[1000];
	int a1 = ints_max(d, dias_seguidos1(a, x, d));
	int a2 = ints_max(d, dias_seguidos2(b, x, d));
	printf("%d %d\n",a1, a2);
}

int main(void)
{
	test_chuva();
	return 0;
}

