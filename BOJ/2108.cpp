#include <iostream>
#include <algorithm>
using namespace std;

int N;
int S[500010], D[10000];
double sum = 0;

int main()
{
	cin >> N;
	int m = -5000, n = 5000;
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
		sum += S[i];
		D[S[i] + 4000]++;
		m = max(m, S[i]);
		n = min(n, S[i]);
	}
	
	sort(S, S + N);
	int _max = 0, idx = 0, _min = 9000;
	for (int i = 8000; i >= 0; i--)
		if (_max <= D[i]) _max = D[i], idx = i;

	for (int i = 0; i <= 8000; i++)
		if (_max == D[i] && idx != i)
		{
			idx = i;
			break;
		}


	printf("%.0lf\n", sum / N);
	printf("%d\n", S[N / 2]);
	printf("%d\n", idx-4000);
	printf("%d\n", m - n);
}