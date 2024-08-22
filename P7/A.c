#include <stdio.h>
#include <assert.h>

int doubles_get(int *a)
{
	int result = 0;
	int x;
	while (scanf("%d", &x) != EOF)
		{
			a[result++] = x;
		}
	return result;
}

int even_values_minus_odd_values(const int *a, int n)
{
	int sumpar = 0;
	int sumimpar = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0)
		{
			sumpar += a[i];
		}
		else
		{
			sumimpar += a[i];
		}
	}
	return sumpar-sumimpar;
}

void test()
{
	int a[1000];
	int w = doubles_get(a);
	int z = even_values_minus_odd_values(a, w);
	printf("%d\n", z);
}

int main()
{
	test();
	return 0;
}