#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int N;

int main()
{
	cin >> N;
	if (N == 1) return 0;
	else
	{
		int i = 2;
		while (N > 1)
		{
			if (N%i == 0)
			{
				printf("%d\n", i);
				N /= i;
				i = 2;
			}
			else i++;
		}
	}
}
