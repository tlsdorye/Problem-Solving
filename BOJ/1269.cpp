#include <iostream>
#include <set>
using namespace std;

typedef long long int ll;
int N, M;

set<ll> S;


int main()
{
	cin >> N >> M;
	int x;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		S.insert(x);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> x;
		if (S.end() == S.find(x)) S.insert(x);
		else S.erase(x);
	}
	cout << S.size();
	return 0;
}