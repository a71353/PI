#include <stdio.h>
#include <math.h>

int regras1(int x, int y)
{
    int pontos = 0;
	if(x>y)
	{
	    pontos = 3;
	}
	if(x==y)
	{
	    pontos = 1;
	}
	if(x<y)
	{
	    pontos = 0;
	}
	if (x>=3)
    {
        pontos++;
    }
    if (x-y>=2)
    {
        pontos++;
    }
    return pontos;
}

int regras2(int x, int y)
{
    int pontos = 0;
	if(y>x)
	{
	    pontos = 3;
	}
	if(y==x)
	{
	    pontos = 1;
	}
	if(y<x)
	{
	    pontos = 0;
	}
	if (y>=3)
    {
        pontos++;
    }
    if (y-x>=2)
    {
        pontos++;
    }
    return pontos;
}

int points1(int x, int y)
{
    if(regras1(x,y)<=4)
    {
        return regras1(x,y);
    }
    else
    {
        return 4;
    }
}

int points2(int x, int y)
{
    if(regras2(x,y)<=4)
    {
        return regras2(x,y);
    }
    else
    {
        return 4;
    }
}

void test_pontos()
{
	int x;
	int y;
	while(scanf("%d%d", &x, &y) != EOF)
	{
	    int z1 = points1(x, y);
	    int z2 = points2(x, y);
	    printf("%d %d\n", z1, z2);
	}
}

int main(void)
{
	test_pontos();
	return 0;
}