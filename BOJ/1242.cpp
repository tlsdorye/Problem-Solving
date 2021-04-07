#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K, M;

int main() {
	cin >> N >> K >> M;

	int ANS = 1;
	int nK = K % N ? K % N : N;
	while (nK != M) {
		M = (M + N - nK) % N--;
		nK = K % N ? K % N : N;
		ANS++;
	}
	cout << ANS;
}