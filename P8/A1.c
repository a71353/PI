#include <stdio.h>
#include <assert.h>

#include "our_ints.h"


/*int ints_get_until(int terminator, int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF && x != terminator)
    a[result++] = x;
  return result;
}*/

int ints_greater_than(const int *a, int n, int m, int *b)
{
	int result = 0;
	for(int i = 0; i < n; i++)
	    if(a[i] > m)
            b[result++] = a[i];
    return result;
}

/*void ints_println_basic(const int *a, int n)
{
  if (n > 0)
  {
    printf("%d", a[0]);
    for (int i = 1; i < n; i++)  // i = 1
      printf(" %d", a[i]);
  }
  printf("\n");
}*/

/*void ints_println_special(const int *a, int n)
{
  if (n == 0)
    printf("*\n");
  else
    ints_println_basic(a, n);
}*/

void unit_test_ints_greater_than(void)
{
	int a[6] = {1, 2, 3, 4, 5, 6};
	int b[6];
	int m1 = ints_greater_than(a, 6, 4, b);
	assert(m1 == 2 && b[0] == 5 && b[1] == 6);
	int m2 = ints_greater_than(a, 6, 3, b);
	assert(m2 == 3 && b[0] == 4 && b[1] == 5 && b[2] == 6);
	int m3 = ints_greater_than(a, 6, 2, b);
	assert(m3 == 4 && b[0] == 3 && b[1] == 4 && b[2] == 5 && b[3] == 6);
	int m4 = ints_greater_than(a, 6, 1, b);
	assert(m4 == 5 && b[0] == 2 && b[1] == 3 && b[2] == 4 && b[3] == 5 && b[4] == 6);
}

void test_ints_greater_than()
{
	int a[1000];
	int b[1000];
	int m;
	int x = ints_get_until(-1, a);
	while(scanf("%d", &m) != EOF)
	{
	    int z = ints_greater_than(a, x, m, b);
	    ints_println_special(b, z);
	}
}

void unit_tests()
{
	unit_test_ints_greater_than();
}

int main(int argc, char **argv)
{
	unit_tests();
	int x = 'A';
	if (argc > 1)
		x = *argv[1];
	if (x == 'A')
		test_ints_greater_than();
	else if (x == 'U')
		printf("All unit tests PASSED.\n");
	return 0;
}
