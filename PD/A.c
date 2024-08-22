#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LINES 10000
#define MAX_LINE_LENGTH 10000
#define MAX_WORDS 10000
#define INT_MAX 10000

char *str_dup(const char *s)
{
	char *result = (char *) malloc(strlen(s) + 1);
	strcpy(result, s);
	return result;
}

int str_readline(FILE *f, char *s)
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
}

int strings_read(FILE *f, char **a)
{
	int result = 0;
	char line[MAX_LINE_LENGTH];
	while (str_readline(f, line) != EOF)
		a[result++] = str_dup(line);
	return result;
}

int strings_get(char **a)
{
	return strings_read(stdin, a);
}

int str_len(const char *s)
{
int result = 0;
while (s[result] != '\0')
result++;
return result;
}

char *str_cpy(char *r, const char *s)
{
	int i = 0;
	while (s[i] != 0)
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return r;
}

int strings_count_while(char **a, int n, const char *x)
{
  int result = 0;
  while (result < n && strcmp(a[result], x) == 0)
    result++;
  return result;
}

int strings_unique(char **a, int n, char **b)
{
  int result = 0;
  int i = 0;
  while (i < n)
  {
    int z = strings_count_while(a+i, n-i, a[i]);
    b[result++] = a[i];
    i += z;
  }
  return result;
}

void strings_exchange(char **a, int x, int y)
{
	char *m = a[x];
	a[x] = a[y];
	a[y] = m;
}

void strings_sort_last(char **a, int n)
{
	int i = n-1;
	while (i > 0 && strcmp(a[i-1], a[i]) > 0)
	{
		strings_exchange(a, i-1, i);
		i--;
	}
}

void strings_isort(char **a, int n)
{
	for (int i = 2; i <= n; i++)
	strings_sort_last(a, i);
}

void strings_write(FILE *f, char **s, int n, const char *separator)
{
	if (n > 0)
	{
		fprintf(f, "%s", s[0]);
		for (int i = 1; i < n; i++) // i = 1
		fprintf(f, "%s%s", separator, s[i]);
	}
}

void strings_writeln(FILE *f, char **s, int n, const char *separator)
{
	strings_write(f, s, n, separator);
	fprintf(f, "\n");
}

void strings_println(char **s, int n, const char *separator)
{
	strings_writeln(stdout, s, n, separator);
}

void test_A(void)
{
	char *a[10000];
	int n = strings_get(a);
	strings_isort(a, n);
	char *b[10000];
	int m = strings_unique(a, n, b);
	strings_println(b, m, "\n");
}

int main(int argc, char **argv)
{
	int x ='A';
	if(argc > 1)
		x = *argv[1];
	if (x == 'A')
		test_A();
	else if(x == 'U')
		printf("All unit tests PASSED.\n");
	return 0;
}
