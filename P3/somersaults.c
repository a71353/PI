#include <stdio.h>

int somersaults(int n)
{
    int saults;
	if (n%2==0)
	{
        saults = 2 + somersaults(n-1);
	}
	if (n%4==3)
	{
         saults = 3 + somersaults(n-1);
	}
	if (n%4==1)
	{
         saults = 1 + somersaults(n-1);
	}
	if (n==0)
	{
	    saults = 0;
	}
	return saults;
}

void test_somersaults()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
	    int z = somersaults(n);
	    printf("%d\n", z);
	}
}

int main(void)
{
	test_somersaults();
	return 0;
}