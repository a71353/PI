#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#include "our_strings.h"

#define MAX_LINES 10000
#define MAX_LINE_LENGTH 10000
#define MAX_WORDS 10000
#define INT_MAX 10000

/*char *str_dup(const char *s)
{
	char *result = (char *) malloc(strlen(s) + 1);
	strcpy(result, s);
	return result;
}*/

/*int str_readline(FILE *f, char *s)
{
	int result = EOF;
	char *p = fgets(s, INT_MAX, f);
	if (p != NULL)
	{
		result = (int) strlen(s);
		if (result > 0 && s[result-1] == '\n')
		s[--result] = '\0';
	}
	return result;
}*/

/*int strings_read(FILE *f, char **a)
{
	int result = 0;
	char line[MAX_LINE_LENGTH];
	while (str_readline(f, line) != EOF)
		a[result++] = str_dup(line);
	return result;
}*/

/*int strings_get(char **a)
{
	return strings_read(stdin, a);
}*/

/*int strings_copy(char **a, int n, char **b)
{
  if (n < 0)
    n = 0;
  memmove(b, a, n * sizeof(char *)); 
  return n;
}*/

int strings_merge(char **a, int n, char **b, int m, char **c)
{
  int result = 0;
  int i = 0;
  int j = 0;
  while (i < n && j < m)
    if (strcmp(a[i], b[j]) <= 0)
      c[result++] = a[i++];
    else
      c[result++] = b[j++];
  result += strings_copy(a + i, n - i, c+result);
  result += strings_copy(b + j, m - j, c+result);
  return result;
}

int strings_count_while_great_and_equal(char **a, int n, char *x)
{
    int result = 0;
    while (result < n && strcmp(x, a[result]) == 0)
    {
        result++;
    }
    return result;
}

int ceia_de_natal(char **a, int n, char **b, int x)
{
  int result = 0;
  int i = 0;
  while ( i < n)
  {
      int z = strings_count_while_great_and_equal(a + i , n - i, a[i]);
      if( z >= x )
      b[result++] = a[i];
      i += z;
  }
  return result;
}

void strings_msort(char **a, int n, char **b)
{
    if (n > 1)
    {
        int m = n / 2;
        strings_msort(a, m, b);
        strings_msort(a+m, n-m, b);
        strings_merge(a, m, a+m, n-m, b);
        strings_copy(b, n, a);
    }
}

void test_ceia_de_natal(char *filename)
{
	char *a[100000];
	char *b[100000];
	char *c[100000];
	FILE *f = fopen(filename, "r" );
	int n = 0;
	scanf("%d", &n);
	int x = strings_get(a);
	strings_msort(a, x, b);
	int z = ceia_de_natal(b, x, c, n);
	printf("%d\n", z);
	for(int i = 0; i < z; i++)
    {
        printf("%s\n", c[i]);
    }
}

int main(int argc, char **argv)
{ 
  	test_ceia_de_natal(argv[2]);
 	  return 0;
}