#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

class value
{
public:
	ll a, b, c, d;
	value() {};
	value(ll x, ll y, ll z, ll w)
	{
		a = x;
		b = y;
		c = z;
		d = w;
	}
};

bool comp(value x, value y)
{
	if (x.a < y.a) return true;
	else if (x.a > y.a) return false;
	else return x.b < y.b;
}

ll D[101], S[3000100], V[3];
vector<value> ans;

void solve(int d, int begin)
{
	if (d == 3)
	{
		ll ret = D[V[0]] + D[V[1]] + D[V[2]];
		if (S[ret] != 0)
		{
			ll v[3] = { V[0],V[1],V[2] };
			sort(v, v + 3);
			for (int i = 0; i < ans.size(); i++)
			{
				if (ans[i].a == S[ret] && ans[i].b == v[0] && ans[i].c == v[1] && ans[i].d == v[2])
					return;
			}
			ans.push_back(value(S[ret], v[0], v[1], v[2]));
		}
		return;
	}
	for (int i = begin; i <= 100; i++)
	{
		V[d] = i;
		solve(d + 1, begin + 1);
	}
}

int main()
{
	ll tri = 0;
	for (ll i = 1; i <= 100; i++)
	{
		tri = i * i * i;
		D[i] = tri;
		S[tri] = i;
	}
	solve(0, 2);
	sort(ans.begin(), ans.end(), comp);
	for (int i = 0; i < ans.size(); i++)
		printf("Cube = %lld, Triple = (%lld,%lld,%lld)\n", ans[i].a, ans[i].b, ans[i].c, ans[i].d);
}