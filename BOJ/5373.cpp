#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <utility>
using namespace std;
int T, N;

enum Name
{
	U, D, F, B, L, R
};

typedef pair<Name, char> block_info;

class Block
{
public:
	vector<block_info> info;
	Block() {};
	Block(block_info a, block_info b)
	{
		info.push_back(a);
		info.push_back(b);
	}
	Block(block_info a, block_info b, block_info c)
	{
		info.push_back(a);
		info.push_back(b);
		info.push_back(c);
	}
};

vector<Block*> cube;

class Side
{
public:
	Name name;
	deque<int> blocks;
	vector<Side*> side;
	Side() {};
	void setSide(Name name, Side* up, Side* left, Side* down, Side* right)
	{
		this->name = name;
		side.push_back(up);
		side.push_back(left);
		side.push_back(down);
		side.push_back(right);
	}

	void clear()
	{
		blocks.clear();
		side.clear();
	}

	void move(char dr)
	{
		if (dr == '-')
		{

			for (int i = 0; i < blocks.size(); i++)
				for (int j = 0; j < cube[blocks[i]]->info.size(); j++)
				{
					if (cube[blocks[i]]->info[j].first == side[0]->name) cube[blocks[i]]->info[j].first = side[1]->name;
					else if (cube[blocks[i]]->info[j].first == side[1]->name) cube[blocks[i]]->info[j].first = side[2]->name;
					else if (cube[blocks[i]]->info[j].first == side[2]->name) cube[blocks[i]]->info[j].first = side[3]->name;
					else if (cube[blocks[i]]->info[j].first == side[3]->name) cube[blocks[i]]->info[j].first = side[0]->name;
				}

			Block *one = cube[blocks[6]], *two = cube[blocks[7]];
			for (int i = 5; i >= 0; i--) cube[blocks[i + 2]] = cube[blocks[i]];
			cube[blocks[0]] = one, cube[blocks[1]] = two;
		}
		else if (dr == '+')
		{
			for (int i = 0; i < blocks.size(); i++)
				for (int j = 0; j < cube[blocks[i]]->info.size(); j++)
				{
					if (cube[blocks[i]]->info[j].first == side[0]->name) cube[blocks[i]]->info[j].first = side[3]->name;
					else if (cube[blocks[i]]->info[j].first == side[1]->name) cube[blocks[i]]->info[j].first = side[0]->name;
					else if (cube[blocks[i]]->info[j].first == side[2]->name) cube[blocks[i]]->info[j].first = side[1]->name;
					else if (cube[blocks[i]]->info[j].first == side[3]->name) cube[blocks[i]]->info[j].first = side[2]->name;
				}

			Block *one = cube[blocks[0]], *two = cube[blocks[1]];
			for (int i = 0; i <= 5; i++) cube[blocks[i]] = cube[blocks[i + 2]];
			cube[blocks[6]] = one, cube[blocks[7]] = two;
		}
	}
};

Side *UP = new Side(), *DOWN = new Side();
Side *FRONT = new Side(), *BACK = new Side();
Side *LEFT = new Side(), *RIGHT = new Side();

void init()
{
	UP->clear();
	DOWN->clear();
	FRONT->clear();
	BACK->clear();
	LEFT->clear();
	RIGHT->clear();

	UP->setSide(U, BACK, LEFT, FRONT, RIGHT);
	DOWN->setSide(D, FRONT, LEFT, BACK, RIGHT);
	FRONT->setSide(F, UP, LEFT, DOWN, RIGHT);
	BACK->setSide(B, DOWN, LEFT, UP, RIGHT);
	LEFT->setSide(L, UP, BACK, DOWN, FRONT);
	RIGHT->setSide(R, UP, FRONT, DOWN, BACK);

	while (!cube.empty())
	{
		Block* curr = cube.back();
		cube.pop_back();
		delete curr;
	}

	cube.push_back(new Block({ U, 'w' }, { B, 'o' }, { L, 'g' }));		// 0
	cube.push_back(new Block({ U, 'w' }, { L, 'g' }));					// 1
	cube.push_back(new Block({ U, 'w' }, { L, 'g' }, { F, 'r' }));		// 2
	cube.push_back(new Block({ U, 'w' }, { F, 'r' }));					// 3
	cube.push_back(new Block({ U, 'w' }, { F, 'r' }, { R, 'b' }));		// 4
	cube.push_back(new Block({ U, 'w' }, { R, 'b' }));					// 5
	cube.push_back(new Block({ U, 'w' }, { R, 'b' }, { B, 'o' }));		// 6
	cube.push_back(new Block({ U, 'w' }, { B, 'o' }));					// 7

	cube.push_back(new Block({ B, 'o' }, { L, 'g' }));					// 8
	cube.push_back(new Block({ L, 'g' }, { F, 'r' }));					// 9
	cube.push_back(new Block({ F, 'r' }, { R, 'b' }));					// 10
	cube.push_back(new Block({ R, 'b' }, { B, 'o' }));					// 11

	cube.push_back(new Block({ D, 'y' }, { B, 'o' }, { L, 'g' }));		// 12
	cube.push_back(new Block({ D, 'y' }, { L, 'g' }));					// 13
	cube.push_back(new Block({ D, 'y' }, { L, 'g' }, { F, 'r' }));		// 14
	cube.push_back(new Block({ D, 'y' }, { F, 'r' }));					// 15
	cube.push_back(new Block({ D, 'y' }, { F, 'r' }, { R, 'b' }));		// 16
	cube.push_back(new Block({ D, 'y' }, { R, 'b' }));					// 17
	cube.push_back(new Block({ D, 'y' }, { R, 'b' }, { B, 'o' }));		// 18
	cube.push_back(new Block({ D, 'y' }, { B, 'o' }));					// 19

	UP->blocks.push_back(0);
	UP->blocks.push_back(1);
	UP->blocks.push_back(2);
	UP->blocks.push_back(3);
	UP->blocks.push_back(4);
	UP->blocks.push_back(5);
	UP->blocks.push_back(6);
	UP->blocks.push_back(7);

	DOWN->blocks.push_back(14);
	DOWN->blocks.push_back(13);
	DOWN->blocks.push_back(12);
	DOWN->blocks.push_back(19);
	DOWN->blocks.push_back(18);
	DOWN->blocks.push_back(17);
	DOWN->blocks.push_back(16);
	DOWN->blocks.push_back(15);

	FRONT->blocks.push_back(2);
	FRONT->blocks.push_back(9);
	FRONT->blocks.push_back(14);
	FRONT->blocks.push_back(15);
	FRONT->blocks.push_back(16);
	FRONT->blocks.push_back(10);
	FRONT->blocks.push_back(4);
	FRONT->blocks.push_back(3);

	BACK->blocks.push_back(12);
	BACK->blocks.push_back(8);
	BACK->blocks.push_back(0);
	BACK->blocks.push_back(7);
	BACK->blocks.push_back(6);
	BACK->blocks.push_back(11);
	BACK->blocks.push_back(18);
	BACK->blocks.push_back(19);

	LEFT->blocks.push_back(0);
	LEFT->blocks.push_back(8);
	LEFT->blocks.push_back(12);
	LEFT->blocks.push_back(13);
	LEFT->blocks.push_back(14);
	LEFT->blocks.push_back(9);
	LEFT->blocks.push_back(2);
	LEFT->blocks.push_back(1);

	RIGHT->blocks.push_back(4);
	RIGHT->blocks.push_back(10);
	RIGHT->blocks.push_back(16);
	RIGHT->blocks.push_back(17);
	RIGHT->blocks.push_back(18);
	RIGHT->blocks.push_back(11);
	RIGHT->blocks.push_back(6);
	RIGHT->blocks.push_back(5);
}

void findCube(int idx)
{
	for (int i = 0; i < cube[idx]->info.size(); i++)
		if (cube[idx]->info[i].first == U) printf("%c", cube[idx]->info[i].second);
}

void print()
{
	findCube(0);
	findCube(7);
	findCube(6);
	printf("\n");
	findCube(1);
	printf("w");
	findCube(5);
	printf("\n");
	findCube(2);
	findCube(3);
	findCube(4);
	printf("\n");
}

int main()
{
	cin >> T;
	while (T--)
	{
		init();
		cin >> N;
		string cubing;
		for (int i = 0; i < N; i++)
		{
			cin >> cubing;
			if (cubing[0] == 'U') UP->move(cubing[1]);
			else if (cubing[0] == 'D') DOWN->move(cubing[1]);
			else if (cubing[0] == 'F') FRONT->move(cubing[1]);
			else if (cubing[0] == 'B') BACK->move(cubing[1]);
			else if (cubing[0] == 'L') LEFT->move(cubing[1]);
			else if (cubing[0] == 'R') RIGHT->move(cubing[1]);
		}
		print();
	}
}