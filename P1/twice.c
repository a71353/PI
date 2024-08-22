#include <stdio.h>

int succ(int x)
{
  return x+1;
}

int pred(int x)
{
  return x-1;
}

int is_zero(int x)
{
  return x == 0;
}

int twice(int x)
{
  return is_zero(x) ? x : x * 2;
}

int main(void)
{
  int x;
  scanf("%d", &x);
  int z = twice(x);
  printf("%d\n", z);
  return 0;
}
