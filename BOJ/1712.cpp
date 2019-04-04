#include <iostream>
using namespace std;
typedef long long ll;

ll A, B, C;

int main()
{
	cin >> A >> B >> C;
	C -= B;
	if (C <= 0)
	{
		cout << -1;
		return 0;
	}
	cout << (A / C) + 1;
}