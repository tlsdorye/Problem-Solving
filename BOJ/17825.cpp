#include <iostream>
#include <algorithm>
#define N 10
using namespace std;

int dice[10], ans;

class Node
{
public:
	int point = 0;
	bool visit = false;
	Node* l = NULL, *r = NULL;
	Node() {};
	Node(int x)
	{
		this->point = x;
	}
};

Node* start_node = new Node(), *end_node = new Node();

class player
{
public:
	int score = 0;
	Node* curr = NULL;
	player(Node* start) 
	{
		curr = start;
	};
};


player players[4] = { player(start_node), player(start_node), player(start_node), player(start_node) };

void MakeMap()
{
	Node* head = start_node, *next;
	Node* _10, *_20, *_30, *_40, *_25 = new Node(25);
	start_node = head;
	for (int i = 1; i <= 20; i++)
	{
		next = new Node(i * 2);
		if (i == 5) _10 = next;
		else if (i == 10) _20 = next;
		else if (i == 15) _30 = next;
		else if (i == 20) _40 = next;
		head->l = next;
		head = next;
	}
	head->l = end_node;

	head = _10;
	next = new Node(13), head->r = next, head = next;
	next = new Node(16), head->l = next, head = next;
	next = new Node(19), head->l = next, head = next;
	next = _25, head->l = next, head = next;
	next = new Node(30), head->l = next, head = next;
	next = new Node(35), head->l = next, head = next;
	head->l = _40;

	head = _20;
	next = new Node(22), head->r = next, head = next;
	next = new Node(24), head->l = next, head = next;
	head->l = _25;

	head = _30;
	next = new Node(28), head->r = next, head = next;
	next = new Node(27), head->l = next, head = next;
	next = new Node(26), head->l = next, head = next;
	head->l = _25;
}

void Solve(int idx)
{
	if (idx >= 10)
	{
		int sum = 0;
		for (int i = 0; i < 4; i++) sum += players[i].score;
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (players[i].curr->l == NULL) continue;
		int move = dice[idx];
		Node* prev = players[i].curr;
		Node* next = players[i].curr;
		for (int j = 0; j < move; j++)
		{
			if (j == 0 && next->r != NULL) next = next->r;
			else if(next->l != NULL) next = next->l;
		}

		if (next != end_node && next->visit) continue;
		prev->visit = false;
		players[i].curr = next;
		players[i].score += next->point;
		next->visit = true;

		Solve(idx + 1);

		prev->visit = true;
		next->visit = false;
		players[i].curr = prev;
		players[i].score -= next->point;
	}
}


int main()
{
	MakeMap();
	//freopen("input.txt", "r", stdin);

	for (int i = 0; i < N; i++)
		scanf("%d", &dice[i]);
	Solve(0);
	cout << ans;

}