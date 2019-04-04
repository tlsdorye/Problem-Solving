#include <stdio.h>
#define PI 3.14159265358979323846264338327950288

int main()
{
	double r;
	scanf("%lf", &r);
	printf("%.6f\n", r*r*PI);
	printf("%.6f", r*r * 2);
	return 0;
}