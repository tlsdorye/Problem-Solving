#include <stdio.h>

int n, m, ans = 0;
int e[51], d[51];

void erase(int size)
{
	for (int i = 1; i < size; i++)	d[i - 1] = d[i];
}

void operate(int size)
{
	int temp;
	for (int i = 0; i < size-1; i++)
	{
		temp = d[i];
		d[i] = d[i + 1];
		d[i + 1] = temp;
	}
}


int main()
{
	
	scanf("%d %d",&n, &m);
	int size = n;
	for (int i = 0; i < n; i++)	d[i] = i + 1;
	for (int i = 0; i < m; i++)	scanf("%d", e + i);
	int i = 0, count = 0;
	while (1)
	{
		if (e[i] != d[0])
		{
			count++;
			operate(size);
		}
		else
		{
			if (count > size / 2) ans += size - count;
			else	ans += count;
			count = 0;
			erase(size);
			size--;
			i++;
		}
		if (i == m) break;
	}
	printf("%d", ans);

	return 0;
}