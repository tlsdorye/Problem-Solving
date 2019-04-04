#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

int main() {
	int d[9], sum =0;
	for (int i = 0; i < 9; i++) cin >> d[i], sum+=d[i];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) 
			if (i != j) {
				if (sum - d[i] - d[j] == 100) {
					d[i] = -1, d[j] = -1;
					break;
				}
			}
	for (int i = 0; i < 9; i++)
		if (d[i] != -1) cout << d[i] << endl;

}