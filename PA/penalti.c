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

/*int ints_count_while(const int *a, int n, int x)
{
	int result = 0;
	while (result < n && a[result] == x)
	{
		result++;
	}
	return result;
}*/

/*int ints_groups(const int *a, int n, int *b)
{
	int result = 0;
	int i = 0;
	while (i < n)
	{
		int z = ints_count_while(a+i, n-i, a[i]);
		b[result++] = z;
		i += z;
	}
	return result;
}*/

/*void ints_println_basic(const int *a, int n)
{
  if (n > 0)
  {
    printf("%d", a[0]);
    for (int i = 1; i < n; i++) 
      printf(" %d", a[i]);
  }
  printf("\n");
}*/

void conjunto(int *a, int *b, int n)
{
   for(int i=0;i<n;i++)
   {
    if(a[i]>0)
      b[i]=-1;
    else if(a[i]<0)
      b[i]=1;
    else if(a[i]==0)
      b[i]=b[i-1];
   }
}

void test_penalti(void)
{
	int a[1000];
	int b[1000];
	int c[1000];
	int x = ints_get(a);
	conjunto(a, b, x);
    int z = ints_groups(b, x, c);
	ints_println_basic(c, z);
}

int main()
{
	test_penalti();
	return 0;
}