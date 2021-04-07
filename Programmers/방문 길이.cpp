#include <string>
#include <map>
#include <utility>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool Check(int x, int y)
{
	return -5 <= x && x <= 5 && -5 <= y && y <= 5;
}

int solution(string dirs)
{
	int answer = 0;
	int check[2][11][11] = { 0 };

	map<char, int> dir_to_idx;
	dir_to_idx.insert({'U', 0});
	dir_to_idx.insert({'D', 1});
	dir_to_idx.insert({'R', 2});
	dir_to_idx.insert({'L', 3});

	int curr_x = 0, curr_y = 0;
	for (int i = 0; i < dirs.size(); i++)
	{
		int next_dir = dir_to_idx[dirs[i]];
		int next_x = curr_x + dx[next_dir];
		int next_y = curr_y + dy[next_dir];


		if (!Check(next_x, next_y)) continue;
		switch (next_dir)
		{
		case 0:
			check[0][curr_x + 5][curr_y + 5] = 1;
			break;
		case 1:
			check[0][next_x + 5][next_y + 5] = 1;
			break;
		case 2:
			check[1][curr_x + 5][curr_y + 5] = 1;
			break;
		case 3:
			check[1][next_x + 5][next_y + 5] = 1;
			break;
		}
		curr_x = next_x, curr_y = next_y;
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 11; j++)
			for (int k = 0; k < 11; k++)
				if (check[i][j][k] == 1) answer++;
	return answer;
}