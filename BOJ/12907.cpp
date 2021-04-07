#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int  N, X, MAX = -1;
int D[41];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X;
		D[X]++;
		MAX = max(MAX, X);
	}

	int ANS = 1;
	bool flag = false;
	for (int i = 0; i <= MAX; i++) {
		if (D[i] == 0) {
			ANS = 0;
			break;
		}
		else if (D[i] == 1) flag = true;
		else if (D[i] == 2) {
			if (flag) {
				ANS = 0;
				break;
			}
			else ANS *= 2;
		}
		else {
			ANS = 0;
			break;
		}
	}
	if (flag) ANS *= 2;
	cout << ANS;
}