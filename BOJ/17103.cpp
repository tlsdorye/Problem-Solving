#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;
int T, X;
bool arr[1000001];
vector<int> prime;

void get_prime() {
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (arr[i]) continue;
		for (int j = i * 2; j <= MAX; j += i)
			arr[j] = true;
	}
	prime.push_back(2);
	for (int i = 3; i <= MAX; i += 2)
		if (!arr[i]) prime.push_back(i);
}

int main() {
	get_prime();
	
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> X;

		int ANS = 0;
		for (int p : prime) {
			if (X / 2 < p) break;
			if (!arr[X - p]) ANS++;
		}

		printf("%d\n", ANS);
	}
}