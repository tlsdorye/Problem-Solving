#include <iostream>
#include <map>
#include <string>
using namespace std;

int N;
string input;
map<string, int> ext_to_num;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		auto it = input.find(".");
		ext_to_num[input.substr(it + 1)]++;
	}
	for (auto it : ext_to_num)
		cout << it.first << " " << it.second << "\n";
}