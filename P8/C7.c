#include <stdio.h>
#include <assert.h>
#include "our_ints.h"

int ints_greater_than(const int *a, int n, int m, int *b)
{
  int result = 0;
  for(int i = 0; i < n; i++)
      if(a[i] > m)
            b[result++] = a[i];
    return result;
}

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

int ints_less_than(const int *a, int n, int m, int *b)
{
  int result = 0;
  for(int i = 0; i < n; i++)
      if(a[i] < m)
            b[result++] = a[i];
    return result;
}

void unit_test_ints_less_than(void)
{
  int a[6] = {1, 2, 3, 4, 5, 6};
  int b[6];
  int m1 = ints_less_than(a, 6, 2, b);
  assert(m1 == 1 && b[0] == 1);
  int m2 = ints_less_than(a, 6, 5, b);
  assert(m2 == 4 && b[0] == 1 && b[1] == 2 && b[2] == 3 && b[3] == 4);
  int m3 = ints_less_than(a, 6, 4, b);
  assert(m3 == 3 && b[0] == 1 && b[1] == 2 && b[2] == 3);
  int m4 = ints_less_than(a, 6, 3, b);
  assert(m4 == 2 && b[0] == 1 && b[1] == 2);
  int m5 = ints_less_than(a, 6, 6, b);
  assert(m5 == 5 && b[0] == 1 && b[1] == 2 && b[2] == 3 && b[3] == 4 && b[4] == 5); 
}

void test_ints_less_than()
{
  int a[1000];
  int b[1000];
  int m;
  int x = ints_get_until(-1, a);
  while(scanf("%d", &m) != EOF)
  {
      int z = ints_less_than(a, x, m, b);
      ints_println_special(b, z);
  }
}

int decimal_lenght_i(int x)
{
	return x < 10 ? x : x % 10 + decimal_lenght_i(x / 10);
}

int digits_sums(const int *a, int n, int *b)
{
	int result = 0;
	for (int i = 0; i < n; i++)
		b[result++] = decimal_lenght_i(a[i]);
	return result;
} 

void unit_test_digits_sums(void)
{
	int a1[4] = {1, 2, 3, 4};
	int b1[4];
	int m11 = digits_sums(a1, 4, b1);
	assert(m11 == 4 && b1[0] == 1 && b1[1] == 2 && b1[2] == 3 && b1[3] == 4);

	int a2[4] = {11, 22, 33, 44};
	int b2[4];
	int m21 = digits_sums(a2, 4, b2);
	assert(m21 == 4 && b2[0] == 2 && b2[1] == 4 && b2[2] == 6 && b2[3] == 8);
	int m22 = digits_sums(a2, 3, b2);
	assert(m22 == 3 && b2[0] == 2 && b2[1] == 4 && b2[2] == 6);

	int a3[4] = {111, 222, 333, 444};
	int b3[4];
	int m31 = digits_sums(a3, 4, b3);
	assert(m31 == 4 && b3[0] == 3 && b3[1] == 6 && b3[2] == 9 && b3[3] == 12);
	int m32 = digits_sums(a3, 3, b3);
	assert(m32 == 3 && b3[0] == 3 && b3[1] == 6 && b3[2] == 9);
}

void test_digits_sums()
{
	int a[1000];
	int b[1000];
	int x = ints_get_until(-1, a);
	int z = digits_sums(a, x, b);
	ints_println_special(b, z);
}

void unit_tests()
{
  unit_test_ints_greater_than();
  unit_test_ints_less_than();
  unit_test_digits_sums();
}

int main(int argc, char **argv)
{
  unit_tests();
  int x = 'A';
  if (argc > 1)
    x = *argv[1];
  if (x == 'A')
    test_ints_greater_than();
  else if (x == 'B')
    test_ints_less_than();
  else if (x == 'C')
	test_digits_sums();
  else if (x == 'U')
    printf("All unit tests PASSED.\n");
  return 0;
}