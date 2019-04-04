#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int N, A = 300, B = 60, C = 10;
int a = 0, b = 0, c = 0;

void solve()
{
	while (N >= A) a++, N -= A;
	while (N >= B) b++, N -= B;
	while (N >= C) c++, N -= C;
}

int main()
{
	cin >> N;
	solve();
	if (N != 0) cout << "-1";
	else printf("%d %d %d", a, b, c);
}
