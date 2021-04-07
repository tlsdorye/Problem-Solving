#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	int index[26] = { 0 };
	for (int i = 0; i < skill.size(); i++) 
		index[(int)(skill[i] - 'A')] = i + 1;

	for (string skill_tree : skill_trees)
	{
		int order = 1;
		for (char skill : skill_tree)
		{
			if (index[(int)(skill - 'A')] == 0) continue;
			if (index[(int)(skill - 'A')] == order) order++;
			else
			{
				order = -1;
				break;
			}
		}
		if (order != -1) answer++;
	}

	return answer;
}