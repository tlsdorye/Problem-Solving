#include <stdio.h>
#include <math.h>

int main() {
	float H, V,c;
	float cos2a, tan1a, x, v = 0, w, t, q;
	scanf("%f%f", &H, &V);
	c = sqrt(H*H + V*V);
	cos2a = H / c;
	tan1a = sqrt((1 - cos2a) / (1 + cos2a));
	x = tan1a*H;
	w = sqrt(H*H + x*x);
	v = w / 2;
	t = H*x / w;
	q = H*V / w;
	printf("%.2lf  %.2lf", v, q-t);
	return 0;
}