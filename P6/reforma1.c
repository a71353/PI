#include <stdio.h>
#include <math.h>

double round_two_decimals(double x)
{
    return round(x*100)/100;
}

int meses(int x, int y)
{
    return x * 12 + y;
}

int trabalho(int x, int y)
{
    return meses(x,y) + 480;
}

int reforma(int x, int y)
{
    if (trabalho(x,y) <= 796)
    {
       return 796;
    }
    if (trabalho(x,y) > 796)
    {
        return trabalho(x,y) < 840 ? trabalho(x,y) : 840;
    }
    return 0;
}

double idadeanos(int x, int y)
{
    return floor(reforma(x,y) / 12);
}

double idademeses(int x, int y)
{
    return ((round_two_decimals(reforma(x,y)) / 12) - idadeanos(x,y)) * 12;
}

void test_idadereforma()
{
    int x;
    int y;
    while(scanf("%d%d", &x, &y) != EOF)
    {
        int z1 = idadeanos(x,y);
        double z2 = idademeses(x,y);
        printf("%d %.0lf\n", z1, z2);
    }
}

int main(void)
{
    test_idadereforma();
    return 0;
}
