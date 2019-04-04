#include <iostream>
using namespace std;
typedef long long ll;

ll N, x, S, p, m;


int main()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> x;
			if (x >= 4611686018427387904)
			{
				x -= 4611686018427387904;
				p++;
			}
			else if (x <= -4611686018427387904)
			{
				x += 4611686018427387904;
				m--;
			}
			S += x;
			if (S >= 4611686018427387904)
			{
				S -= 4611686018427387904;
				p++;
			}
			else if (S <= -4611686018427387904)
			{
				S += 4611686018427387904;
				m--;
			}
		}
		if (p + m > 0) cout << "+\n";
		else if (p + m < 0) cout << "-\n";
		else
		{
			if (S > 0) cout << "+\n";
			else if (S < 0) cout << "-\n";
			else cout << "0\n";
		}
		x = p = m = S = 0;
	}
}