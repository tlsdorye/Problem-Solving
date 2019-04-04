#include <stdio.h>
#include <algorithm>

using namespace std;

char s[6200][6200];
int n;

void print_star(int x, int y, int t)
{
	int p[3][2];
	if (t == 3)
	{
		s[y][x] = '*';
		s[y + 1][x - 1] = '*';
		s[y + 1][x + 1] = '*';
		for (int i = 0; i < 5; i++)s[y + 2][x - 2 + i] = '*';
		return;
	}
	else
	{
		p[0][0] = x;
		p[0][1] = y;
		p[1][0] = x - t / 2;
		p[1][1] = y + t / 2;
		p[2][0] = x + t / 2;
		p[2][1] = y + t / 2;
		print_star(p[0][0], p[0][1], t / 2);
		print_star(p[1][0], p[1][1], t / 2);
		print_star(p[2][0], p[2][1], t / 2);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i<6200; i++) fill(s[i], s[i] + 6199, ' ');
	print_star(n, 0, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= 2 * n; j++)
		{
			if (i == n - 1 && j == 2 * n);
			else printf("%c", s[i][j]);
		}
		printf("\n");
	}
	return 0;
}