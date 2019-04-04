#include <stdio.h>
#include <math.h>

int main(void)
{
	float x1, y1, r1;
	float x2, y2, r2;
	float x, y, d;
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int ans;
		scanf("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);
		x = x1 - x2;
		y = y1 - y2;
		d = sqrt(x*x + y*y);
		if (r1 + r2 > d&&d != 0)
		{
			if (r1 > d + r2 || r2 > d + r1) ans = 0;
			else if (r1 == d + r2 || r2 == d + r1) ans = 1;
			else if (r1 < d + r2 || r2 < d + r1) ans = 2;
		}
		else if (r1 + r2 == d&&d != 0) ans = 1;
		else if (r1 + r2 < d&&d != 0) ans = 0;
		else if (d == 0)
		{
			if (r1 == r2) ans = -1;
			else ans = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}