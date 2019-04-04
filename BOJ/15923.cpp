#include <iostream>
using namespace std;

int N;
int ans = 0;

int main()
{
	cin >> N;
	int x = 0, y = 0, a = -50, b = -50, fx, fy;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		if (a == -50 && b == -50)
		{
			fx = a = x;
			fy = b = y;
			continue;
		}
		else
		{
			if (x != a)
			{
				if (x < a) ans += (a - x);
				else ans += (x - a);
				a = x;
			}
			else
			{
				if (y < b) ans += (b - y);
				else ans += (y - b);
				b = y;
			}
		}
	}

	if (x != fx)
	{
		if (x < fx) ans += (fx - x);
		else ans += (x - fx);
	}
	else
	{
		if (y < fy) ans += (fy - y);
		else ans += (y - fy);
	}

	printf("%d", ans);
	return 0;
}