#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int A[7];

int main()
{
	int x, maxVal = 0, mdx, idx = 0;
	for (int i = 0; i < 3; i++)
	{
		cin >> x;
		A[x]++;
		if (maxVal < A[x])
		{
			maxVal = A[x];
			mdx = x;
		}
		idx = max(idx, x);
	}
	if (maxVal == 3) cout << 10000 + mdx * 1000;
	else if (maxVal == 2) cout << 1000 + mdx * 100;
	else cout << idx * 100;
}
