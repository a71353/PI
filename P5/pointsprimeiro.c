#include <stdio.h>
#include <math.h>

int pontosbase1(int x, int y)
{
	if(x>y)
	{
	    return 3;
	}
	if(x==y)
	{
	    return 1;
	}
	if(x<y)
	{
	    return 0;
	}
}

int pontosbase2(int x, int y)
{
	if(y>x)
	{
	    return 3;
	}
	if(y==x)
	{
	    return 1;
	}
	if(y<x)
	{
	    return 0;
	}
}

int pontosmarc1(int x, int y)
{
    if(x>=3)
	{
	    return 1;
	}
	else
    {
        return 0;
    }
}

int pontosmarc2(int x, int y)
{
    if(y>=3)
	{
	    return 1;
	}
	else
    {
        return 0;
    }
}

int pontosdif1(int x, int y)
{
    if(x-y>=2)
	{
	    return 1;
	}
	else
    {
        return 0;
    }
}

int pontosdif2(int x, int y)
{
    if(y-x>=2)
	{
	    return 1;
	}
	else
    {
        return 0;
    }
}

int pontoscalc1(int x, int y)
{
	return pontosbase1(x,y) + pontosmarc1(x,y) + pontosdif1(x,y);
}

int pontoscalc2(int x, int y)
{
	return pontosbase2(x,y) + pontosmarc2(x,y) + pontosdif2(x,y);
}

int points1(int x, int y)
{
    if(pontoscalc1(x,y)<=4)
    {
        return pontoscalc1(x,y);
    }
    else
    {
        return 4;
    }
}

int points2(int x, int y)
{
    if(pontoscalc2(x,y)<=4)
    {
        return pontoscalc2(x,y);
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
