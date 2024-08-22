#include <stdio.h>

#include "our_ints.h"

/*int ints_get(int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF)
  {
  		a[result++] = x;
  }
  return result;
}*/

int min(int x, int y)
{
	return x <= y ? x : y;
}

int hat_trick(int *a, int n)
{
	int result = 0;
	for (int i = 0; i<n; i++)
	{
		if (a[i] >= 3)
		result++;
	}
	return result;
}

int quantidade(int *a, int n, int x, int *b)
{
	int result = 0;
	for (int i = 0; i < n; i += x)
	{
		int y = min(n-i, x);
		b[result++] = hat_trick(a+i, y);
	}
	return result;
}

/*void ints_println_basic(const int *a, int n)
{
	if (n > 0)
	{
		printf("%d", a[0]);
		for (int i = 1; i < n; i++) 
		printf(" %d", a[i]);
	}
	printf("\n");
}*/


void test_hat_trick()
{
	int a[1000];
	int b[1000];
	int x;
	scanf("%d", &x);
	int y = ints_get(a);
	int z = quantidade(a, y, x, b);
	ints_println_basic(b, z);
}

int main(void)
{
	test_hat_trick();
	return 0;
}