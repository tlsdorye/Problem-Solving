#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int n, sum = 0;
	while (t--)
	{
		scanf("%1d", &n);
		sum += n;
	}
	cout << sum;
}