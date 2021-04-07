#include <iostream>
using namespace std;

int A, B;

int main()
{
	cin >> A >> B;
	int ANS = 0;
	while (A < B) {
		ANS++;
		if (B % 2 == 0) B /= 2;
		else if (B % 10 == 1) B /= 10;
		else {
			ANS = -1;
			break;
		}
	}
	if (A != B) ANS = -1;
	if (ANS != -1) ANS++;
	cout << ANS;
}