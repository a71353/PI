#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

int ints_get(int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF)
    a[result++] = x;
  return result;
}

int *ints_new (int n)
{
  return (int *) malloc (n * sizeof(int));
}

int ints_copy(const int *a, int n, int *b)
{
  if (n < 0)
    n = 0;
  memmove(b, a, n * sizeof(int));  // Note: 3rd arg is unsigned.
  return n;
}

int ints_merge(const int *a, int n, const int *b, int m, int *c)
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
}

int ints_get_first(int *a, int n, int *b)
{
  int result = 0;
  int i=0;
    while(a[i]!=-1 && i<n)
    {
    b[result++]=a[i];
    i++;
    }
  return result;
}

int ints_get_second(int *a, int n,int *b, int*c)
{
  int result = 0;
  int i= ints_get_first(a,n,b)+1;
  while (i < n)
  {
    c[result++] = a[i];
    i++;
  }
  return result;
}

int spy(int *a, int n, int *b)
{
int result=0;
  for (int i=1;i<n;i++)
    if(a[i]==a[i-1])
        b[result++]= a[i];
return result;
}

void ints_println_basic(const int *a, int n)
{
  if (n > 0)
  {
    printf("%d\n", a[0]);
    for (int i = 1; i < n; i++)  // i = 1
      printf("%d\n", a[i]);
  }

}

void ints_msort_i(int *a, int n, int *b)
{
  if (n > 1)
  {
    int m = n / 2;
    ints_msort_i(a, m, b);
    ints_msort_i(a+m, n-m, b);
    ints_merge(a, m, a+m, n-m, b);
    ints_copy(b, n, a);
  }
}

void ints_msort(int *a, int n)
{
  int *b = ints_new(n);
  ints_msort_i(a, n, b);
}

void test_spy(void)
{
  int a[1000];
  int b[1000];
  int c[1000];
  int d[1000];
  int e[1000];
  int x = ints_get(a);
  int y = ints_get_first(a, x, b);
  int z = ints_get_second(a, x, b, c);
  int w =ints_merge(b, y, c, z, d);
  ints_msort(d, w);
  int k = spy(d, w, e);
  if (k==0)
    printf("%d\n", -1);
  else
  ints_println_basic(e, k);
}

int main(void)
{
test_spy();
return 0;
}