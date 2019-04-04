#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <utility>
#include <string>
#define MAX 200001
typedef long long ll;
using namespace std;

class person
{
public:
	string name;
	int date, month, year;
	person() {};
	person(string s, int a, int b, int c)
	{
		name = s;
		date = a;
		month = b;
		year = c;
	}
};

bool comp(person& p, person& q)
{
	if (p.year <q.year) return 1;
	else if (p.year > q.year) return 0;
	else
	{
		if (p.month < q.month) return 1;
		else if (p.month > q.month) return 0;
		else
		{
			if (p.date < q.date) return 1;
			else return 0;
		}
	}
}

int main()
{
	string s;
	int a, b, c, n;
	cin >> n;
	vector<person> P(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s >> a >> b >> c;
		P[i].name = s;
		P[i].date = a;
		P[i].month = b;
		P[i].year = c;
	}
	sort(P.begin(), P.end(),comp);
	cout << P[n - 1].name << endl << P[0].name;
}