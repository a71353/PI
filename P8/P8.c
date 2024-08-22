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

/*int ints_get_until(int terminator, int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF && x != terminator)
    a[result++] = x;
  return result;
}*/

int ints_less_than(const int *a, int n, int m, int *b)
{
	int result = 0;
	for(int i = 0; i < n; i++)
	    if(a[i] < m)
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

/*int ints_get_until(int terminator, int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF && x != terminator)
    a[result++] = x;
  return result;
}*/

int decimal_lenght_i(int x)
{
	return x < 10 ? x : x % 10 + decimal_lenght_i(x / 10);
}

int digits_sums(const int *a, int n, int *b)
{
	int result = 0;
	for (int i = 0; i < n; ++i)
		b[result++] = decimal_lenght_i(a[i]);
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

/*int ints_get_until(int terminator, int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF && x != terminator)
    a[result++] = x;
  return result;
}*/

int ints_append(const int *a, int n, const int *b, int m, int *c)
{
	int result = 0;
	for(int i = 0; i < n; i++)
            c[result++] = a[i];
    for(int i = 0; i < n; i++)
            c[result++] = b[i];
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

void unit_test_ints_append(void)
{
	int a1[2] = {1, 2};
	int b1[2] = {3, 4};
	int c1[4];
	int k11 = ints_append(a1, 2, b1, 2, c1);
	assert(k11 == 4 && c1[0] == 1 && c1[1] == 2 && c1[2] == 3 && c1[3] == 4);
	int k12 = ints_append(a1, 1, b1, 1, c1);
	assert(k12 == 2 && c1[0] == 1 && c1[1] == 3);

	int a2[3] = {1, 2, 3};
	int b2[3] = {4, 5, 6};
	int c2[6];
	int k21 = ints_append(a2, 3, b2, 3, c2);
	assert(k21 == 6 && c2[0] == 1 && c2[1] == 2 && c2[2] == 3 && c2[3] == 4 && c2[4] == 5 && c2[5] == 6);
	int k22 = ints_append(a2, 1, b2, 1, c2);
	assert(k22 == 2 && c2[0] == 1 && c2[1] == 4);
}

void test_ints_append()
{
	int a[1000];
	int b[1000];
	int c[1000];
	int x = ints_get_until(-1, a);
	int y = ints_get_until(-1, b);
	int z1 = ints_append(a, x, b, y, c);
	int z2 = ints_append(b, y, a, x, c);
	ints_println_special(c, z1);
	ints_println_special(c, z2);
}

/*int ints_get_until(int terminator, int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF && x != terminator)
    a[result++] = x;
  return result;
}*/

int ints_take(const int *a, int n, int m, int *b)
{
    int result = 0;
    for (int i = 0; i < n && i < m; i++)
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

void unit_test_ints_take(void)
{
	int a1[6] = {1, 2, 3, 4, 5, 6};
	int b1[6];
	int m11 = ints_take(a1, 6, 2, b1);
	assert(m11 = 2 && b1[0] == 1 && b1[1] == 2);
	int m12 = ints_take(a1, 6, 3, b1);
	assert(m12 = 3 && b1[0] == 1 && b1[1] == 2 && b1[2] == 3);

	int a2[4] = {1, 2, 3, 4};
	int b2[4];
	int m21 = ints_take(a2, 4, 2, b2);
	assert(m21 = 2 && b2[0] == 1 && b2[1] == 2);
	int m22 = ints_take(a2, 4, 1, b2);
	assert(m22 = 1 && b2[0] == 1);
}

void test_ints_take()
{
	int a[1000];
	int b[1000];
  int m;
	int x = ints_get_until(-1, a);
  while(scanf("%d", &m) != EOF)
  {
	    int z = ints_take(a, x, m, b);
	    ints_println_special(b, z);
  }
}

/*int ints_get_until(int terminator, int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF && x != terminator)
    a[result++] = x;
  return result;
}*/

int ints_drop(const int *a, int n, int m, int *b)
{
  int result = 0;
  if ( m <= 0)
      m = 0;
  for (int i = m; i < n; ++i)
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

void unit_test_ints_drop(void)
{
	int a1[6] = {1, 2, 3, 4, 5, 6};
	int b1[6];
	int m11 = ints_drop(a1, 6, 5, b1);
	assert(m11 = 1 && b1[0] == 6);
	int m12 = ints_drop(a1, 6, 4, b1);
	assert(m12 = 2 && b1[0] == 5 && b1[1] == 6);
	int m13 = ints_drop(a1, 6, 3, b1);
	assert(m13 = 3 && b1[0] == 4 && b1[1] == 5 && b1[2] == 6);

	int a2[4] = {1, 2, 3, 4};
	int b2[4];
	int m21 = ints_drop(a2, 4, 2, b2);
	assert(m21 = 2 && b2[0] == 3 && b2[1] == 4);
}

void test_ints_drop()
{
	int a[1000];
	int b[1000];
  int m;
	int x = ints_get_until(-1, a);
  while(scanf("%d", &m) != EOF)
  {
	    int z = ints_drop(a, x, m, b);
	    ints_println_special(b, z);
  }
}

/*int ints_get_until(int terminator, int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF && x != terminator)
    a[result++] = x;
  return result;
}*/

int ints_ascending(const int *a, int n, int *b)
{
  int result = 0;
  b[result++] = a[0];
  for (int i = 1; i < n; i++)
  {
      if(b[result-1] <= a[i])
      b[result++] = a[i];
  }
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

void unit_test_ints_ascending(void)
{
	int a1[4] = {1, 2, 3, 4};
	int b1[4];
	int m11 = ints_ascending(a1, 4, b1);
	assert(m11 = 4 && b1[0] == 1 &&  b1[1] == 2 && b1[2] == 3 && b1[3] == 4);
	int m12 = ints_ascending(a1, 3, b1);
	assert(m12 = 3 && b1[0] == 1 && b1[1] == 2 && b1[2] == 3);
	int m13 = ints_ascending(a1, 2, b1);
	assert(m13 = 2 && b1[0] == 1 && b1[1] == 2);
	int m14 = ints_ascending(a1, 1, b1);
	assert(m14 = 1 && b1[0] == 1);
}

void test_ints_ascending()
{
	int a[1000];
	int b[1000];
	int x = ints_get_until(-1, a);
	int z = ints_ascending(a, x, b);
	ints_println_special(b, z);
}

/*int ints_get_until(int terminator, int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF && x != terminator)
    a[result++] = x;
  return result;
}*/

int ints_accumulate(const int *a, int n, int *b)
{
  int result = 0;
  b[result++] = 0;
  for (int i = 1; i < n+1; i++)
      b[result++] = a[i-1] + b[i-1];
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

void unit_test_ints_accumulate(void)
{
	int a1[5] = {1, 2, 3, 4, 5};
	int b1[6];
	int m11 = ints_accumulate(a1, 5, b1);
	assert(m11 = 6 && b1[0] == 0 && b1[1] == 1 && b1[2] == 3 && b1[3] == 6 && b1[4] == 10 && b1[5] == 15);
	int m12 = ints_accumulate(a1, 4, b1);
	assert(m12 = 5 && b1[0] == 0 && b1[1] == 1 && b1[2] == 3 && b1[3] == 6 && b1[4] == 10);
	int m13 = ints_accumulate(a1, 3, b1);
	assert(m13 = 4 && b1[0] == 0 && b1[1] == 1 && b1[2] == 3 && b1[3] == 6);
    int m14 = ints_accumulate(a1, 2, b1);
	assert(m14 = 3 && b1[0] == 0 && b1[1] == 1 && b1[2] == 3 && b1[3] == 6);
}

void test_ints_accumulate()
{
	int a[1000];
	int b[1000];
	int x = ints_get_until(-1, a);
	int z = ints_accumulate(a, x, b);
	ints_println_special(b, z);
}

/*int ints_get_until(int terminator, int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF && x != terminator)
    a[result++] = x;
  return result;
}*/

int ints_unaccumulate(const int *a, int n, int *b)
{
  int result = 0;
  for (int i = 0; i < n-1; ++i)
      b[result++] = a[i+1] - a[i];
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

void unit_test_ints_unaccumulate(void)
{
	int a1[7] = {0, 5, 6, 10, 11, 14, 18};
	int b1[6];
	int m11 = ints_unaccumulate(a1, 7, b1);
	assert(m11 = 6 && b1[0] == 5 && b1[1] == 1 && b1[2] == 4 && b1[3] == 1 && b1[4] == 3 && b1[5] == 4);
	int m12 = ints_unaccumulate(a1, 4, b1);
	assert(m12 = 3 && b1[0] == 5 && b1[1] == 1 && b1[2] == 4);
	int m13 = ints_unaccumulate(a1, 3, b1);
	assert(m13 = 2 && b1[0] == 5 && b1[1] == 1);

	int a2[4] = {0, 1, 1, 1};
	int b2[3];
	int m21 = ints_unaccumulate(a2, 4, b2);
	assert(m21 = 3 && b2[0] == 1 && b2[1] == 0 && b2[2] == 0);

}

void test_ints_unaccumulate()
{
	int a[1000];
	int b[1000];
	int x = ints_get_until(-1, a);
	int z = ints_unaccumulate(a, x, b);
	ints_println_special(b, z);
}

/*int ints_get_until(int terminator, int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF && x != terminator)
    a[result++] = x;
  return result;
}*/

int ints_find_triple(const int *a, int n, int *b)
{
  int result = 0;
  for (int i = 0; i < n-2; ++i)
  {
      if (a[i] == a[i+1] && a[i+1] == a[i+2])
      {
          b[result++] = ints_find(a, n, a[i]);
          return i;
      }
      else
      {
          return -1;
      }
  }
  return 1;
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

void unit_test_ints_find_triple(void)
{
	int a1[12] = {6, 2, 8, 5, 9, 9, 9, 1, 9, 2, 2, 2};
	int b1[12];
	int m11 = ints_find_triple(a1, 12, b1);
	assert(m11 = 1 && b1[0] == 4); 
}

void test_ints_find_triple()
{
	int a[1000];
	int b[1000];
	int x = ints_get_until(-1, a);
	int z = ints_find_triple(a, x, b);
	ints_println_special(b, z);
}

void unit_tests(void)
{
	unit_test_ints_greater_than();
	unit_test_ints_less_than();
	unit_test_digits_sums();
	unit_test_ints_append();
	unit_test_ints_take();
	unit_test_ints_drop();
	unit_test_ints_ascending();
	unit_test_ints_accumulate();
	unit_test_ints_unaccumulate();
	unit_test_ints_find_triple();
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
	else if (x == 'D')
		test_ints_append();
	else if (x == 'E')
		test_ints_take();
	else if (x == 'F')
		test_ints_drop();
	else if (x == 'G')
		test_ints_ascending();
	else if (x == 'H')
		test_ints_accumulate();
	else  if (x == 'I')
		test_ints_unaccumulate();
	else if ( x == 'J')
		test_ints_find_triple();
	else if (x == 'U')
		printf("All unit tests PASSED.\n");
	return 0;
}