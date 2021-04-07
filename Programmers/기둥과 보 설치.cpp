#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isAddPillar(int x, int y);
void addPillar(int x, int y);
bool isAddBeam(int x, int y);
void addBeam(int x, int y);
void removePillar(int x, int y);
void removeBeam(int x, int y);
void removeAnswerItem(int x, int y, int a);

vector<vector<int>> pillar_map, beam_map, answer;

vector<vector<int>> solution(int N, vector<vector<int>> build_frame) {
	N += 1;
	pillar_map.resize(N, vector<int>(N, 0));
	beam_map.resize(N, vector<int>(N, 0));

	for (vector<int> info : build_frame)
	{
		int x = info[0], y = info[1];
		int a = info[2], b = info[3];
		if (a == 0 && b == 0) removePillar(x, y);
		else if (a == 0 && b == 1) addPillar(x, y);
		else if (a == 1 && b == 0) removeBeam(x, y);
		else if (a == 1 && b == 1) addBeam(x, y);
		/*for (vector<int> temp : answer) printf("[%d %d %d], ", temp[0], temp[1], temp[2]);
		printf("\n");*/
	}
	sort(answer.begin(), answer.end());
	return answer;
}

bool isAddPillar(int x, int y)
{
	if (y == 0) return true;
	if (y - 1 >= 0 && pillar_map[x][y - 1] == 1) return true;
	if (beam_map[x][y] == 1) return true;
	if (x - 1 >= 0 && beam_map[x - 1][y] == 1) return true;
	return false;
}

void addPillar(int x, int y)
{
	if (isAddPillar(x, y))
	{
		pillar_map[x][y] = 1;
		answer.push_back({ x, y, 0 });
	}
}

bool isAddBeam(int x, int y)
{
	if (y - 1 >= 0 && pillar_map[x][y - 1] == 1) return true;
	if (y - 1 >= 0 && x + 1 < pillar_map.size() && pillar_map[x + 1][y - 1] == 1) return true;
	if ((x - 1 >= 0 && beam_map[x - 1][y] == 1) && (x + 1 < beam_map.size() && beam_map[x + 1][y] == 1)) return true;
	return false;
}

void addBeam(int x, int y)
{
	if (isAddBeam(x, y))
	{
		beam_map[x][y] = 1;
		answer.push_back({ x, y, 1 });
	}
}

void removePillar(int x, int y)
{
	pillar_map[x][y] = 0;
	removeAnswerItem(x, y, 0);
	for (vector<int> temp : answer)
	{
		if (temp[2] == 0 && isAddPillar(temp[0], temp[1])) continue;
		if (temp[2] == 1 && isAddBeam(temp[0], temp[1])) continue;
		else
		{
			pillar_map[x][y] = 1;
			answer.push_back({ x, y, 0 });
			return;
		}
	}
}

void removeBeam(int x, int y)
{
	beam_map[x][y] = 0;
	removeAnswerItem(x, y, 1);
	for (vector<int> temp : answer)
	{
		if (temp[2] == 0 && isAddPillar(temp[0], temp[1])) continue;
		if (temp[2] == 1 && isAddBeam(temp[0], temp[1])) continue;
		else
		{
			beam_map[x][y] = 1;
			answer.push_back({ x, y, 1 });
			return;
		}
	}
}

void removeAnswerItem(int x, int y, int a)
{
	for (int i = 0; i < answer.size(); i++)
		if (answer[i][0] == x && answer[i][1] == y && answer[i][2] == a)
		{
			answer.erase(answer.begin() + i);
			return;
		}
}