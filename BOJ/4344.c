#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, j, k;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int c = 0;
		int check = 0;
		scanf("%d", &c);
		float average = 0;
		int sum = 0;

		int stud[1000] = { 0 };
		for (k = 0; k < c; k++)
		{
			scanf("%d", stud + k);
			sum += stud[k];
		}
		average = (float)sum / c;
		for (k = 0; k < c; k++)
		{
			if (stud[k] > average) check++;
		}
		float aaa = (float)check / c * 100000;
		aaa = floor(aaa + 0.5);
		aaa = aaa / 1000;
		printf("%.3f%%\n", aaa);
	}
	return 0;
}