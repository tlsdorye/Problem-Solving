#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a, b;
}Bot;

int main() {
	int n, time = 0;
	scanf("%d", &n);
	Bot* bot = (Bot*)malloc(sizeof(Bot)*n);
	for (int i = 0; i < n; i++)	scanf("%d%d", &bot[i].a, &bot[i].b);
	for (int i = 0; i < n; i++) {
		while (1)
		{
			if (time % (bot[i].a + bot[i].b) >= bot[i].b) {
				time++;
				break;
			}
			else 	time += bot[i].b - time % (bot[i].a + bot[i].b);
		}
	}
	printf("%d", time);
	return 0;
}
