#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <utility>
#include <string>
#include <cmath>
#include <functional>
#define MAX 987654321
typedef long long ll;
using namespace std;

class node
{
public:
	char data;
	node* left = NULL;
	node* right = NULL;
};

class tree
{
public:

	vector<node*> d;

	void init(int n)
	{
		for (int i = 0; i < n; i++)
		{
			node* temp = new node;
			temp->data = 'A' + i;
			d.push_back(temp);
		}
	}

	void makeNode(char a, char b, char c)
	{
		if (b != '.') d[a - 'A']->left = d[b - 'A'];
		if (c != '.') d[a - 'A']->right = d[c - 'A'];
	}

	void preorder(node* p)
	{
		cout << p->data;
		if (p->left != NULL) preorder(p->left);
		if (p->right != NULL) preorder(p->right);
	}
	void inorder(node* p)
	{
		if (p->left != NULL) inorder(p->left);
		cout << p->data;
		if (p->right != NULL) inorder(p->right);
	}
	void postorder(node* p)
	{
		if (p->left != NULL) postorder(p->left);
		if (p->right != NULL) postorder(p->right);
		cout << p->data;
	}
};

int main()
{
	
	int n;
	cin >> n;
	tree t;
	t.init(n);
	char a, b, c;
	while (n--)
	{
		cin >> a >> b >> c;
		t.makeNode(a, b, c);
	}
	t.preorder(t.d[0]);
	cout << endl;
	t.inorder(t.d[0]);
	cout << endl;
	t.postorder(t.d[0]);
}