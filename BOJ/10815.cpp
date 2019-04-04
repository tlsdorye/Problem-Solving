#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

vector<bool> d(10001, false);

int main()
{
	set<int> S;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		S.insert(x);
	}
	cin >> n;
	set<int>::iterator it;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		it = S.find(x);
		if (S.end() != it) printf("1 ");
		else printf("0 ");
	}
}