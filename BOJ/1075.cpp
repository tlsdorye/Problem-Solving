#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

ll N, F;

int main()
{
	cin >> N >> F;
	N /= 100;
	N *= 100;
	for(int i=0;i<=9;i++)
		for (int j = 0; j <= 9; j++)
		{
			ll temp = N + 10 * i + j;
			if (temp % F == 0)
			{
				cout << i << j;
				return 0;
			}
		}
}
