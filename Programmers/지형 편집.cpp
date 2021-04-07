#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

long long solution(vector<vector<int> > land, int P, int Q)
{
	ll x = 1000000000, y = 300 * 300 * 101;
	ll answer = x*y;
	ll total = 0, prev = 0, aa = -1;
	int N = land.size();

	vector<ll> D(N*N, 0);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			D[i*N + j] = land[i][j];
			total += land[i][j];
		}
	sort(D.begin(), D.end());


	for (int i = 0; i < D.size(); i++)
	{
		if (aa != D[i])
		{
			ll p = D[i] * i - prev;
			ll q = total - prev - (D.size() - i)*D[i];
			answer = min(answer, p*P + q*Q);
		}
		prev += D[i];
	}
	return answer;
}