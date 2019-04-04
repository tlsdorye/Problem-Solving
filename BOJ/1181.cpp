#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
typedef pair<int, int> P;
set<string> S;
vector<string> V;
int N;

bool comp(string &s, string &u)
{
	if (s.size() < u.size()) return true;
	else if (s.size() > u.size()) return false;
	else
	{
		if (s < u) return true;
		else return false;
	}
	return false;
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		S.insert(s);
	}

	for (auto it : S)
		V.push_back(it);
	sort(V.begin(), V.end(), comp);
	
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << endl;
}