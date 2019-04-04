int main()
{
	int a[3];
	int i, j,k;
	for (i = 0; i < 1;)
	{
		scanf("%d %d %d", &a[0], &a[1], &a[2]);
		if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;
		int t;
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 2; k++)
			{
				if (a[k] > a[k + 1])
				{
					t = a[k + 1];
					a[k + 1] = a[k];
					a[k] = t;
				}
			}

		}

		if (a[2] >= a[1] + a[0]) printf("Invalid\n");
		else
		{
			if (a[0] == a[1] && a[1] == a[2]) printf("Equilateral\n");
			else if (a[0] == a[1] && a[0] != a[2]) printf("Isosceles\n");
			else if (a[1] == a[2] && a[1] != a[0]) printf("Isosceles\n");
			else if (a[0] != a[1] && a[1] != a[2] && a[2] != a[0]) printf("Scalene\n");
		}
	}

	return 0;
}