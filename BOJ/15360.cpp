
#include <iostream>
using namespace std;


int main()
{
	int n, m, k, a, b, sum = 0, div, tmp;

	cin >> n >> m >> k;

	div = 2 * k + 1;

	cin >> a;
	tmp = a - k - 1;
	if (tmp > 0)
	{
		sum += (tmp) / div;
		if (tmp % div != 0)
			sum++;
		//cout << "AA" << sum << endl;

	}

	for (int i = 1; i < m; i++)
	{
		cin >> b;
		tmp = b - a - 2 * k - 1;
		if (tmp > 0)
		{
			//cout << "BB" << tmp << endl;
			sum += (tmp) / div;
			if (tmp % div != 0)
				sum++;
			//cout << "AA" << sum << endl;

		}
		a = b;
	}
	tmp = n - b - k;
	//cout << tmp << endl;
	if (tmp > 0)
	{
		sum += (tmp) / div;
		if (tmp % div != 0)
			sum++;
		//cout << "AA" << sum << endl;


	}

	cout << sum;

	return 0;
}