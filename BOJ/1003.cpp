#include <iostream>
using namespace std;

int fibo[41][2];

void makeFibo() {
	fibo[0][0] = 1;
	fibo[0][1] = 0;
	fibo[1][0] = 0;
	fibo[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		fibo[i][0] = fibo[i - 1][1];
		fibo[i][1] = fibo[i - 1][0] + fibo[i - 1][1];
	}
}

int main() {

	makeFibo();
	int n;
	cin >> n;
	while (n--) {
		int tmp;
		cin >> tmp;
		cout << fibo[tmp][0] << " " << fibo[tmp][1] << endl;
	}
}