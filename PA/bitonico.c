#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

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

int bitonico(int *a, int n)
{   
  int result=0;
  for (int i = 1; i<n-1; i++)
      if ((a[i]<a[i-1] && a[i]<a[i+1]) || (a[i]>a[i-1] && a[i]>a[i+1]))
        result++;
  return result;
}


void test_bitonico()
{
    int a[10000];
    int n = ints_get(a);
    int z = bitonico(a,n);
    if(z>1)
      printf("desordenado\n");
    else
      printf("bitónico\n");
}

int main()
{
    test_bitonico();
    return 0;
}
