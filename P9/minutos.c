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

/*int ints_find(const int *a, int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			return 0;
		}
	}
 	return 1;
}*/

int golos(int *a, int n, int *b)
{
    int result=0;
    for(int i=0;i<n;i+=2)
    {
      if (a[i]<90 && ints_find(b, result, a[i]))
        b[result++]=a[i];
    }
    return result;
}

int minutes(int *a, int n, int *b)
{
	return 90 - golos(a, n, b);
}

void test_minutes()
{
	int a[1000];
	int b[1000];
	int x = ints_get(a);
	int z = minutes(a, x, b);
	printf("%d\n", z);
}

int main(void)
{
	test_minutes();
	return 0;
}