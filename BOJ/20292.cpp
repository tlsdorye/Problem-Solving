#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

string input, A, B, TO;
string READ = "READ", READ_ = "READ ";
string WRITE = "WRITE", WRITE_ = "WRITE ";
string _TO_ = " TO ", WAIT = "WAIT", EXIT ="EXIT";
map<string, string> memory_state;
vector<string> ans;

int main()
{
	while (1)
	{
		cin >> input;
		if (input == EXIT)
		{
			ans.push_back(input);
			break;
		}
		else if (input == READ)
		{
			cin >> A;
			if (memory_state[A] == WRITE)
			{
				memory_state.clear();
				memory_state[A] = READ;
				ans.push_back(WAIT);
				ans.push_back(READ_ + A);
			}
			else
			{
				memory_state[A] = READ;
				ans.push_back(READ_ + A);
			}
		}
		else
		{
			cin >> A >> TO >> B;
			if (memory_state[A] == WRITE)
			{
				memory_state.clear();
				memory_state[A] = READ;
				memory_state[B] = WRITE;
				ans.push_back(WAIT);
				ans.push_back(WRITE_ + A + _TO_ + B);
			}
			else
			{
				if (memory_state[B] == READ || memory_state[B] == WRITE)
				{
					memory_state.clear();
					memory_state[A] = READ;
					memory_state[B] = WRITE;
					ans.push_back(WAIT);
					ans.push_back(WRITE_ + A + _TO_ + B);
				}
				else
				{
					memory_state[A] = READ;
					memory_state[B] = WRITE;
					ans.push_back(WRITE_ + A + _TO_ + B);
				}
			}
		}
	}
	for (string x : ans) cout << x << "\n";
}