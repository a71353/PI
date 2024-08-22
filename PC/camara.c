#include <stdio.h>
#include <assert.h>

#include "our_doubles.h"
#include "our_ints.h"

/*int int_get(void)
{
  int result;
  scanf("%d", &result);
  return result;
}*/

/*int ints_get_until(int terminator, int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF && x != terminator)
    a[result++] = x;
  return result;
}*/

int camara(const int *a, int n, int x, int y)
{
	for (int i = 0; i < n; ++i)
		if (y >= a[i]  && y <= x+a[i])
			return i;
	return -1;
}

void test_camara(void)
{
	int x = int_get();
	int a[1000];
	int n = ints_get_until(-1, a);
	int y;
	while(scanf("%d", &y) != EOF)
	{
		int z = camara(a, n, x, y);
		if (z != -1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

int main(void)
{
	test_camara();
	return 0;
}
