#include <stdio.h>
#include <assert.h>

int doubles_get(int *a)
{
	int result = 0;
	int x;
	while (scanf("%d", &x) != EOF)
		a[result++] = x;
	return result;
}

int max(const int *a, int n)
{
	assert(n>0);
	int result = a[0];
	for(int i = 0; i < n; i++)
	{
		if(a[i] > result)
		{
            result = a[i];
        }
    }
    return result;
}

int ints_remove(const int *a, int n, int x, int *b)
{
  int result = 0;
  for (int i = 0; i < n; i++)
  {
      if (a[i] != x)
      {
          b[result++] = a[i];
      }
  }
  return result;
}

int ints_second_max(int *a, int n)
{
	assert(a[0] != a[1]);
	int b[n];
	int x = ints_remove(a, n, max(a, n), b);
	return max(b, x);
}

void test()
{
	int a[1000];
	int w = doubles_get(a);
	printf("%d\n", ints_second_max(a, w));
}

int main(void)
{
	test();
	return 0;
}