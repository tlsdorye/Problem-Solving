#include <iostream>
using namespace std;
typedef long long ll;

int H;

ll D[61] = { 1, 1 };


int main()
{
	cin >> H;
	for (int i = 2; i <= H; i++)
	{
		if (i % 2 == 1) D[i] = D[i - 1] * 2 - 1;
		else D[i] = D[i - 1] * 2 + 1;
	}
	cout << D[H];
}