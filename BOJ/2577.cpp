#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	a *= b*c;
	int d[10] = { 0 };
	while (a != 0)
	{
		d[a % 10]++;
		a /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << d[i] << "\n";
	return 0;
}