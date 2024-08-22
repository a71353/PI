#include <stdio.h> 
#include <math.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "our_strings.h"
#include "our_ints.h"

/*char *str_dup(char *s)
{
  char *result = (char *) malloc(strlen(s) + 1);
  strcpy(result, s);
  return result;
}*/

int ints_init(int x, int n, int *a)
{
  int result = 0;
  for (int i = 0; i < n; i++)
    a[result++] = x;
  return result;
}

/*int ints_count(int *a, int n, int x)
{
  int result = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == x)
      result++;
  return result;
}*/

typedef struct {
  char *departure;
  char *destination;
} Flight;

Flight flight(char *departure, char *destination)
{
  Flight result;
  result.departure = departure;
  result.destination = destination;
  return result;
}

int flights_read(FILE *f, Flight *a)
{
  int result = 0;
  char departure[1000];
  char destination[1000];
  while(fscanf(f, "%s%s", departure, destination) != EOF)
    a[result++] = flight(str_dup(departure), str_dup(destination));
  return result;
}

int ints_append(const int *a, int n, const int *b, int m, int *c)
{
  for (int i = 0; i < n; i++)
    c[a[i]] += 1;
  for(int j = 0; j < m; j++)
    c[b[j]] += 1;
  return 0;
}

int voos_partida(Flight *a, int n, char *departure, int *b)
{
  int result = 0;
  for(int i=0; i<n; i++)
    if(strcmp(a[i].departure, departure) == 0)
      b[result++] = i;
  return result;
}

int voos_destinos(Flight *a, int n, char *destination, int *b)
{
  int result = 0;
  for(int i=0; i<n; i++)
    if(strcmp(a[i].destination, destination) == 0)
      b[result++] = i;
  return result;
}

int voos_destinos_2(Flight *a, int n, int *b, int m, int *c)
{
  int result = 0;
  for(int j=0; j<m; j++)
    for(int i=0; i<n; i++)
    if(strcmp(a[i].departure, a[b[j]].destination) == 0)
      c[result++] = i;
  return result;
}

void test_voos(char *filename)
{
	FILE *f = fopen(filename, "r");
  assert(f != NULL);
  Flight flights[1000];
  int x = flights_read(f, flights);
  char line[1000];
  char line2[1000];
  while(scanf("%s %s", line, line2) != EOF)
  {
    int b[x];
    int c[x];  
    int d[x]; 
    int m = voos_partida(flights, x, line, b);
    int n = voos_destinos(flights, x, line2, c);
    int o = voos_destinos_2(flights, x, b, m, d);
    int e[1000];
    int f[1000];
    ints_init(0, 1000, e);
    ints_init(0, 1000, f);
    ints_append(c, n, b, m, e);
    ints_append(c, n, d, o, f);
    int k = ints_count(e, 1000, 2); 
    int l = ints_count(f, 1000, 2); 
    printf("%d %d\n", k, l);
  }
}

int main(int argc, char **argv)
{
  test_voos(argv[2]);
  return 0;
}