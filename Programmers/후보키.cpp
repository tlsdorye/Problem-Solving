#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

set<set<int>> unique_keys;

void SearchUniqueKeys(vector<vector<string>> &relation, int col_size, int depth, vector<int> &keys)
{
	if (depth >= col_size) return;
	for (int i = depth; i < col_size; i++)
	{
		keys.push_back(i);
		set<vector<string>> check_unique;
		int j = 0;
		for (; j < relation.size(); j++)
		{
			vector<string> row;
			for (int k = 0; k < keys.size(); k++) row.push_back(relation[j][keys[k]]);
			if (check_unique.find(row) == check_unique.end()) check_unique.insert(row);
			else break;
		}
		if (j == relation.size()) unique_keys.insert(set<int>(keys.begin(), keys.end()));
		else SearchUniqueKeys(relation, col_size, i + 1, keys);
		keys.pop_back();
	}
}

void MakeMinimality()
{
	set<set<int>>::iterator x = unique_keys.begin();
	while (x != unique_keys.end())
	{
		bool flag = true;
		for (set<set<int>>::iterator y = x; y != unique_keys.end(); y++)
		{
			if (x == y) continue;
			if (includes(x->begin(), x->end(), y->begin(), y->end()))
			{
				unique_keys.erase(x);
				flag = false;
				break;
			}
			else if (includes(y->begin(), y->end(), x->begin(), x->end()))
			{
				set<set<int>>::iterator temp = y;
				y++;
				unique_keys.erase(temp);
			}
		}
		if (flag) x++;
		else x = unique_keys.begin();
	}
}

int solution(vector<vector<string>> relation) 
{
	int answer = 0;
	int col = relation[0].size();
	vector<int> keys;
	SearchUniqueKeys(relation, relation[0].size(), 0, keys);
	MakeMinimality();
	answer = unique_keys.size();
	return answer;
}