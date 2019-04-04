#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> D;
int N, M;

int main()
{
	cin >> N >> M;
	string n;
	for (int i = 1; i <= N; i++)
	{
		char str[230];
		n = to_string(i);
		scanf("%s", str);
		string s = string(str);
		D[n] = s;
		D[s] = n;
	}
	for (int i = 0; i < M; i++)
	{
		char str[230];
		scanf("%s", str);
		string s = string(str);
		auto it = D.find(s);
		
		printf("%s\n", it->second.c_str());
	}
	return 0;
}