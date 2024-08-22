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


int ints_max(const int *a, int n)
{
  assert(n > 0);
  int result = a[0];
  for (int i = 1; i < n; i++)  // i = 1
    if (result < a[i])
      result = a[i];
  return result;
}

int ints_indices(const int *a, int n, int x, int *b)
{
  int result = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == x)
      b[result++] = i;
  return result;
}

void ints_println_basic(const int *a, int n)
{
  if (n > 0)
  {
    printf("%d", a[0]);
    for (int i = 1; i < n; i++)  // i = 1
      printf(" %d", a[i]);
  }
  printf("\n");
}


int ints_argsmax(const int *a, int n, int x, int *b)
{
	assert(n > 0);
	return ints_indices(a, n, ints_max(a, n), b);
}

void test()
{
	int a[1000];
	int b[1000];
	int w = doubles_get(a);
	int y = ints_max(a, w);
	int z = ints_argsmax(a, w, y, b);
	ints_println_basic(b, z);
}


int main(void)
{
	test();
	return 0;
}