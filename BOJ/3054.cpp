#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

char d[5][75];

void wendy(int i)
{
	d[0][i] = '*';
	d[1][i - 1] = d[1][i + 1] = '*';
	d[2][i - 2] = d[2][i + 2] = '*';
	d[3][i - 1] = d[3][i + 1] = '*';
	d[4][i] = '*';
}

void peter(int i)
{
	d[0][i] = '#';
	d[1][i - 1] = d[1][i + 1] = '#';
	d[2][i - 2] = d[2][i + 2] = '#';
	d[3][i - 1] = d[3][i + 1] = '#';
	d[4][i] = '#';
}

int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 75; j++) d[i][j] = '.';
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		d[2][2 + i * 4] = s[i];
		peter(2 + i * 4);
	}
	for (int i = 2; i < s.size(); i += 3)
		wendy(2 + i * 4);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < s.size() * 4 + 1; j++) cout << d[i][j];
		cout << "\n";
	}
}