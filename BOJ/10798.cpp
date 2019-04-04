#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	vector<string> v(5, "");
	for (int i = 0; i < 5; i++) cin >> v[i];
	queue<string> que;
	for (int i = 0; i < 5; i++) que.push(v[i]);
	while (!que.empty())
	{
		string u = que.front();
		que.pop();
		cout << u[0];
		u.erase(0, 1);
		if (u != "") que.push(u);
	}
}