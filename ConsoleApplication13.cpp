#include "stdafx.h"
#include <stdio.h>
#include <math.h>
/*
/Функция, которая преобразовывает координаты точек в коэффициенты общего уравнения, а также уравнение из общего вида к каноническому
/Возвращает k2-коэффициент при х
*/
float coordinates(float xa, int ya, float xb, int yb);
/*
/Функция, которая преобразовывает уравнение из общего вида к каноническому
/Возвращает k-коэффициент при х
*/
float coefficients(int A, float B, float C);
int main(void) {
	int a, ya, yb, A, xa, xb, f, C;
	float  B, k, l, k1, k2, n, m1, m2, x, y;
	printf("What you will enter data:\n1-coordinates of 2 lines\n2-coefficients of 2 lines\n3-coordinates of 1 line and coefficients of 1 line?\n");
	scanf_s("%i", &a);
	if (a < 1 || a>3) {
		printf("Error\n");
		return 0;
	}
	if (a == 1) {
		printf("Input xa,ya,xb,yb : ");
		scanf_s("%i%i%i%i", &xa, &ya, &xb, &yb);
		k1 = coordinates(xa, ya, xb, yb);
		m1 = k1 * (-((ya - yb) * xa + (xb - xa) * ya)) / (ya - yb);
		printf("Input xa,ya,xb,yb : ");
		scanf_s("%i%i%i%i", &xa, &ya, &xb, &yb);
		k2 = coordinates(xa, ya, xb, yb);
		m2 = k2 * (-((ya - yb) * xa + (xb - xa) * ya)) / (ya - yb);
	}
	if (a == 2) {
		printf("Input A,B,C :\n");
		scanf_s("%i%f%i", &A, &B, &C);
		k1 = coefficients(A, B, C);
		m1 = k1 * C / A;
		printf("Input A,B,C :\n");
		scanf_s("%i%f%i", &A, &B, &C);
		k2 = coefficients(A, B, C);
		m2 = k2 * C / A;
	}
	if (a == 3) {
		printf("Input A,B,C :\n");
		scanf_s("%i%f%i", &A, &B, &C);
		k1 = coefficients(A, B, C);
		m1 = k1 * C / A;
		printf("Input xa,ya,xb,yb : ");
		scanf_s("%i%i%i%i", &xa, &ya, &xb, &yb);
		k2 = coordinates(xa, ya, xb, yb);
		m2 = k2 * (-((ya - yb) * xa + (xb - xa) * ya)) / (ya - yb);
	}
	n = (k1 - k2) / (1 + k1 * k2);
	l = -atan(n);
	l = l * 180 / 3.14;
	printf("Angle between straight lines = %f\n", l);
	x = (m2 - m1) / (k1 - k2);
	printf("x = %.3f\n", x);
	y = x * k1 + m1;
	printf("y = %.3f\n", y);
	return 0;
}
float coordinates(float xa, int ya, float xb, int yb) {
	int A;
	float B, C, k2;
	A = ya - yb;
	B = xb - xa;
	C = -(A * xa + B * ya);
	k2 = coefficients(A, B, C);
	return k2;
}
float coefficients(int A, float B, float C) {
	float m, k;
	m = -C / B;
	k = -A / B;
	printf("k = %.5f\n", k);
	if (m > 0 && k != 1) {
		printf("y = %.5fx+%.2f\n", k, m);
	}
	if (m == 0) {
		printf("y = %.5f\n", k);
	}
	if (k == 0) {
		printf("y = %.2f\n", m);
	}
	if (m < 0 && k != 1) {
		printf("y = %.5fx%.2f\n", k, m);
	}
	if (k == 1 && m>0) {
		printf("y = x+%.2f\n", m);
	}
	if (k == 1 && m<0) {
		printf("y = x%.2f\n", m);
	}
	return k;
}
