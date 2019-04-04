#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int id, color, size, sum = 0;
} Ball;

Ball b[200000];
int N, s[200002], total;

bool cmp1(Ball a, Ball b){	return a.size<b.size;	}
bool cmp2(Ball a, Ball b){	return a.id<b.id;	}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i<N; i++)	{
		scanf("%d%d", &b[i].color, &b[i].size);
		b[i].id = i;	}
	sort(b, b + N, cmp1);
	for (int i = 0, j = 0; i<N; i = j)	{
		for (j = i; j < N && b[i].size == b[j].size; j++);
		for (int k = i; k < j; k++) b[k].sum = total - s[b[k].color];
		for (int k = i; k < j; k++) s[b[k].color] += b[k].size;
		for (int k = i; k < j; k++) total += b[k].size;	}
	sort(b, b + N, cmp2);
	for (int i = 0; i<N; i++) printf("%d\n", b[i].sum);
	return 0;
}