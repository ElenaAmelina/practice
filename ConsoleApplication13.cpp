#include "stdafx.h"
#include <stdio.h>
#include <math.h>
int main(void)
{
	int A, C, xa, ya, xb, yb, m, a, c;
	float k1, B, b;
	printf("Input A,B,C :\n");
	scanf("%i%f%i", &A, &B, &C);
	printf("Input xa,ya,xb,yb : ");
	scanf("%i%i%i%i", &xa, &ya, &xb, &yb);
	m = -C / B;
	k1 = -A / B;
	printf("k1= %f\n", k1);
	if (k1>0 && k1 != 1)
	{
		printf("y1=%fx+%i\n", k1, m);
	}
	if (k1 == 1)
	{
		printf("y1=%i\n", m);
	}
	else
	{
		printf("y1=%fx-%i\n", k1, m);
	}

	a = ya - yb;
	b = xa - xb;
	c = a * xa + b * ya;

	return 0;
}