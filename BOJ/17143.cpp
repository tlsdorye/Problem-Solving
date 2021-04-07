#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;
typedef pair<int, int> P;

int R, C, M, ANS;
int map[102][102];

class Shark
{
public:
	int x, y, s, d, z;

	Shark(int x, int y, int s, int d, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		if (d == 1 && x == 1) this->d = 2;
		else if (d == 2 && x == R) this->d = 1;
		else if (d == 3 && y == C) this->d = 4;
		else if (d == 4 && y == 1) this->d = 3;
		else this->d = d;
		if (this->d <= 2) s %= (R - 1) * 2;
		else s %= (C - 1) * 2;
		this->s = s;
	}

	void move()
	{
		bool flag = false;
		if (d == 1)
		{
			x -= s;
			if (x < 1) x = 2 - x, flag = !flag;
			if (x > R) x = (2 * R - x), flag = !flag;
			if (x == 1 || x == R) flag = !flag;
			if (flag) d = 2;
		}
		else if (d == 2)
		{
			x += s;
			if (x > R) x = (2 * R - x), flag = !flag;
			if (x < 1) x = 2 - x, flag = !flag;
			if (x == 1 || x == R) flag = !flag;
			if (flag) d = 1;
		}
		else if (d == 3)
		{
			y += s;
			if (y > C) y = (2 * C - y), flag = !flag;
			if (y < 1) y = 2 - y, flag = !flag;
			if (y == 1 || y == C) flag = !flag;
			if (flag) d = 4;
		}
		else if (d == 4)
		{
			y -= s;
			if (y < 1) y = 2 - y, flag = !flag;
			if (y > C) y = (2 * C - y), flag = !flag;
			if (y == 1 || y == C) flag = !flag;
			if (flag) d = 3;
		}
	}
};

vector<Shark> sharks;

bool comp(Shark& x, Shark& y)
{
	return x.z > y.z;
}

void Fishing(int c)
{
	for (int i = 1; i <= R; i++)
	{
		if (map[i][c] != 0) {
			ANS += sharks[map[i][c] - 1].z;
			sharks.erase(sharks.begin() + map[i][c] - 1);
			map[i][c] = -1;
			break;
		}
	}
	memset(map, 0, sizeof(map));
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> R >> C >> M;
	int x, y, s, d, z;
	for (int i = 1; i <= M; i++)
	{
		cin >> x >> y >> s >> d >> z;
		sharks.push_back(Shark(x, y, s, d, z));
	}

	sort(sharks.begin(), sharks.end(), comp);
	for (int j = 0; j < sharks.size(); j++)
	{
		Shark s = sharks[j];
		map[s.x][s.y] = j + 1;
	}

	for (int i = 1; i <= C; i++)
	{
		// 낚시
		Fishing(i);
		// 상어이동
		for (Shark& s : sharks) s.move();
		// 없어질 상어 계산
		for (int j = 0; j < sharks.size(); j++)
		{
			Shark s = sharks[j];
			if (map[s.x][s.y] == 0) map[s.x][s.y] = (j + 1);
			else sharks.erase(sharks.begin() + j--);
		}
	}
	cout << ANS;
}