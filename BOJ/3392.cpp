#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define SIZE_MAX 30000
using namespace std;


class Tuple
{
public:
	int x, y1, y2;
	bool type;
	Tuple(int x, int y1, int y2, bool type)
	{
		this->x = x;
		this->y1 = y1;
		this->y2 = y2;
		this->type = type;
	}
};

class Node
{
public:
	int val, cnt;
	int s, e;
	Node *left, *right;
	Node(int s, int e)
	{
		val = cnt = 0;
		this->s = s;
		this->e = e;
		if (s != e)
		{
			left = new Node(s, (s + e) / 2);
			right = new Node((s + e) / 2 + 1, e);
		}
	}

	void update(int l, int r, int diff)
	{
		if (r < s || e < l) return;
		if (l <= s && e <= r) cnt += diff;
		else
		{
			left->update(l, r, diff);
			right->update(l, r, diff);
		}
		if (cnt > 0) val = (e - s + 1);
		else
		{
			if (s == e) val = 0;
			else val = left->val + right->val;
		}
	}
};


bool sortByX(Tuple &u, Tuple &v)
{
	return u.x < v.x;
}

int N, ans;
vector<Tuple> V;


int main()
{
	cin >> N;
	int x1, y1, x2, y2;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		V.push_back(Tuple(x1, y1 + 1, y2, true));
		V.push_back(Tuple(x2, y1 + 1, y2, false));
	}
	sort(V.begin(), V.end(), sortByX);

	Node node(1, SIZE_MAX);
	int dx = 0;
	Tuple curr = V[0];
	node.update(curr.y1, curr.y2, 1);
	for (int i = 1; i < V.size(); i++)
	{
		Tuple next = V[i];
		dx = next.x - curr.x;
		ans += (dx * node.val);
		if (next.type) node.update(next.y1, next.y2, 1);
		else node.update(next.y1, next.y2, -1);
		curr = next;
	}
	cout << ans;

}