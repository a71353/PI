#include <stdio.h>

#include "our_ints.h"

/*int ints_get(int *a)
{
  int result = 0;
  int x;
  while (scanf("%d", &x) != EOF)
  {
  		a[result++] = x;
  }
  return result;
}*/

int temp_min(int *a, int n)
{   
  int result=0;
  for (int i=0; i<n; i++)
    if (a[i]<=0)
      result++;
  return result;
}

int dezembro(int *a, int n, int *b)
{
  int result = 0;
  int x = n / 31;
  for(int i=0; i<n; i+=31)
  {
    if(temp_min(a+i, 31) >= 3 )
      b[result++] = x;
    x--;
  }
  return result;
}

void test_dezembro()
{
  int a[3100];
  int b[3100];
  int x = ints_get(a);
  int z = dezembro(a, x, b);
  if (z == 0)
  {
    printf("0\n");
  }
  else
    printf("%d %d\n", z, b[z-1]);
}

int main()
{
    test_dezembro();
    return 0;
}