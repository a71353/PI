#include <stdio.h>
#include <assert.h>

int doubles_get(int *a)
{
	int result = 0;
	int x;
	while (scanf("%d", &x) != EOF)
		a[result++] = x;
	return result;
}

int ints_all_equal(const int *a,int n)
{
	int result=0;
	for(int i = 0; i < n; i++)
		{
			if(a[i]==a[0])
			{
				result++;
			}
		}
	if(result==n)
	{
		return 1;
	}
    else
    {
    	return 0;
    }
}

void test()
{
	int a[1000];
	int w = doubles_get(a);
	int z = ints_all_equal(a, w);
	printf("%d\n", z);
}

int main()
{
	test();
	return 0;
}