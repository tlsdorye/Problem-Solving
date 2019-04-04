#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int N, ans = 0;
int D[16][2];
int S[16]; // [i번째 날에 받을 수 있는 최대 금액][그 금액의 end date]
vector<vector<P>> V; // [date][start date / cash ]

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> D[i][0] >> D[i][1];

	V.resize(N + 10, vector<P>());
	for (int i = 1; i <= N; i++)
		V[D[i][0] + i - 1].push_back(make_pair(i, D[i][1]));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < V[i].size(); k++)
			{
				if (j < V[i][k].first && S[i] < S[j] + V[i][k].second)
					S[i] = S[j] + V[i][k].second;
			}
		}
		if (ans < S[i]) ans = S[i];
	}
	cout << ans;
}