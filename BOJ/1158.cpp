#include <stdio.h>
#include <vector>

using namespace std;

vector <int> l;

int main()
{
	int n, m, p;
	scanf("%d %d",&n, &m);
	p = m - 1;
	for (int i = 0; i < n; i++)
	{
		l.push_back(i + 1);
	}

	printf("<");
	while (1)
	{
		if (l.size() == 1)
		{
			printf("%d", l[p]);
			break;
		}
		else
			printf("%d, ", l[p]);
		l.erase(l.begin() + p);
		p += m - 1;
		while (p >= l.size())
			p -= l.size();
	}
	printf(">");
}