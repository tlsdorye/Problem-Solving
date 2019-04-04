#include <iostream>
#include <queue>
typedef long long ll;

using namespace std;

int prime[5000002];

void getChe(int num) {
	int i = 2;

	for (i = 2; i <= num; i++) {
		prime[i] = i;
	}

	for (i = 2; i <= num; i++) {
		if (prime[i] == 0) 
			continue;
		for (int j = i + i; j <= num; j += i) {
			prime[j] = 0;
		}
	}
	/*
		for (i = 2; i <= num; i++) {
		if (arr[i] != 0)
			cout << arr[i] << endl;
	}
	*/

}

int main(void) {
	getChe(5000002);

	priority_queue<int> D;
	priority_queue<int> G;

	int n, d, g, num_D = 0, num_G = 0, t1, t2;
	ll score_D = 0, score_G = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> g;
		if (prime[d] == 0) {
			if (num_G < 3) score_G += 1000;
			else {
				t1 = G.top(), G.pop();
				t2 = G.top(), G.pop();
				score_G += G.top();
				G.push(t1), G.push(t2);
			}
		}
		else if (prime[d] == -1) score_D -= 1000;
		else num_D++, D.push(d), prime[d] = -1;

		if (prime[g] == 0) {
			if (num_D < 3) score_D += 1000;
			else {
				t1 = D.top();
				D.pop();
				t2 = D.top();
				D.pop();
				score_D += D.top();
				D.push(t1), D.push(t2);
			}
		}
		else if (prime[g] == -1) score_G -= 1000;
		else num_G++, G.push(g), prime[g] = -1;
	}
	if (score_D > score_G) cout << "소수의 신 갓대웅";
	else if (score_D == score_G) cout << "우열을 가릴 수 없음";
	else cout << "소수 마스터 갓규성";
	return 0;
}
