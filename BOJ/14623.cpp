#include <iostream>
#include <vector>
#include <string>
typedef long long ll;

using namespace std;

string a, b;

ll td(string s) {
	ll n = 0, e = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		n += (s[i] - '0')*e;
		e *= 2;
	}
	return n;
}

string dt(ll n) {
	string u = "";
	while (n) {
		if (n % 2) u = '1' + u;
		else u = '0' + u;
		n /= 2;
	}
	return u;
}

int main() {
	cin >> a >> b;
	ll c = td(a)*td(b);
	cout << dt(c);


	return 0;
}