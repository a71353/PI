#include <stdio.h>
#include <math.h>

#define pal 8*po
#define co 24*po
#define va 40*po
#define br 80*po
#define pe 12*po
#define pas 60*po
#define to 72*po
#define po 0.0254

double medida(int a, int b, int c, int d, int e, int f, int g, int h)
{
	return (a*pal) + (b*pe) + (c*pas) + (d*to) + (e*co) + (f*va) + (g*br) + (h*po);
}

void test_medida()
{
	int a, b, c, d, e, f, g, h;
	while(scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h) != EOF)
	{
	    double z = medida(a, b, c, d, e, f, g, h);
	    printf("%.4lf\n", z);
	}
}

int main(void)
{
	test_medida();
	return 0;
}
