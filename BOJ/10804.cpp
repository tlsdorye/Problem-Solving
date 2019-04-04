#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <utility>
#include <string>
#define MAX 200001
typedef long long ll;
using namespace std;

int d[21];

void solve(int a, int b)
{
	while (a < b)
		swap(d[a++], d[b--]);
}

int main()
{
	for (int i = 1; i <= 20; i++)
		d[i] = i;
	int a, b;
	for (int i = 0; i < 10; i++)
	{
		cin >> a >> b;
		solve(a, b);
	}
	for (int i = 1; i <= 20; i++)
		cout << d[i] << " ";
}