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

int cabaz(int *a, int n)
{
	int x = a[0];
	int result = 0;
	for(int i = 1; i < n; i++)
	{
		result += (a[i] / x);
	}
	return result;
}

void test_cabaz()
{
	int a[1000];
	int x = ints_get(a);
	int z = cabaz(a, x);
	printf("%d\n", z);
}

int main(void)
{
	test_cabaz();
	return 0;
}