#include <stdio.h>
#include <assert.h>


int int_get(void)
{
  int result;
  scanf("%d", &result);
  return result;
}

int ints_get(int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF)
    a[result++] = x;
  return result;
}

int ints_sum(const int *a, int n)
{
  int result = 0;
  for (int i = 0; i < n; i++)
    result += a[i];
  return result;
}

int crescente(const int *a, int n)
{
	int result = 0;
	while(result < n-1 && a[result] < a[result+1])
		result++;
	return result;
}

int rampas(const int *a, int n, int *b)
{
	int result = 0;
	int i = 0;
	while (i < n-1)
	if (a[i] < a[i+1])
	{
		int z = crescente(a+i, n-i);
		b[result++] = z;
		i += z;
	}
	else
	i++;
return result;
}

int remover_rampas(const int *a, int n, int x, int *b)
{
  int result = 0;
  for (int i = 0; i < n; i++)
    if (a[i] >= x)
      b[result++] = a[i];
  return result;
}

int rampas_finais(const int *a, int n, int *b, int x, int *c)
{
	int m = rampas(a, n, b);
	int k = remover_rampas(b, m, x, c);
	return k;
}

void test_rampas(void)
{
	int x = int_get();
	int a[1000];
	int y = ints_get(a);
	int b[1000];
	int c[1000];
	int w1 = rampas_finais(a, y, b, x, c);
	int w2 = ints_sum(c, w1);
	printf("%d %d\n", w1, w2);
}

int main(void)
{
	test_rampas();
	return 0;
}