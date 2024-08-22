#include <stdio.h> 
#include <math.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "our_ints.h"

#define MAX_LINE_LENGTH 100000
#define INT_MIN 2

/*int *ints_new (int n)
{
  return (int *) malloc (n * sizeof(int));
}*/

/*int ints_get(int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF)
    a[result++] = x;
  return result;
}*/

/*int ints_max(int *a, int n)
{
  int result = INT_MIN;
  for (int i = 0; i < n; i++)
    if (result < a[i])
      result = a[i];
  return result;
}*/

/*int ints_copy(int *a, int n, int *b)
{
  if (n < 0)
    n = 0;
  memmove(b, a, n * sizeof(int));  
  return n;
}*/

/*int ints_merge(int *a, int n, int *b, int m, int *c)
{
  int result = 0;
  int i = 0;
  int j = 0;
  while (i < n && j < m)
    if (a[i] <= b[j])
      c[result++] = a[i++];
    else
      c[result++] = b[j++];
  result += ints_copy(a + i, n - i, c+result);
  result += ints_copy(b + j, m - j, c+result);
  return result;
}*/

/*void ints_msort_i(int *a, int n, int *b)
{
  if (n > 1)
  {
    int m = n / 2;
    ints_msort_i(a, m, b);
    ints_msort_i(a+m, n-m, b);
    ints_merge(a, m, a+m, n-m, b);
    ints_copy(b, n, a);
  }
}*/

/*void ints_msort(int *a, int n)
{
  int *b = ints_new(n);
  ints_msort_i(a, n, b);
}*/

int ints_find_free_space(int *a, int n)
{
  int result = 0;
  for (int i = 1; i < n; i++)
    if (a[i] == a[i-1] + 1)
      result++;
  return result;
}

int ints_find_distance_max(int *a, int n, int x)
{
  for (int i = 1; i < n; i++)
    if (a[i] - a[i-1] == x)
      return a[i-1];
  return -1;
}

int distance(int *a, int n, int *b)
{
  int result = 0;
  for(int i=1; i<n; i++)
      b[result++] = a[i] - a[i-1];
  return result;
}

void test_pizza(void)
{
  int a[200000];
  int n = ints_get(a);
  ints_msort(a, n);
  int b[200000];
  int m = distance(a, n, b);
  int k = ints_max(b, m); 
  int z = ints_find_distance_max(a, n, k); 
  int w = z + k/2;
  if(ints_find_free_space(a, n) == n-1) 
    printf("-1\n");
  else
    printf("%d\n", w);
}

int main(void)
{
  test_pizza();
  return 0;
}