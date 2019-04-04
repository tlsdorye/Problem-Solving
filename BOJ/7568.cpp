#include <stdio.h>
#include <stdlib.h>

typedef struct  {
	int x;
	int y;
	int r;
}stu;


int main() {
	int n, check = 1;
	scanf("%d", &n);
	stu* a = (stu*)malloc(sizeof(stu)*n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i].x, &a[i].y);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i].x < a[j].x && a[i].y < a[j].y) check++;
		}
		a[i].r = check;
		check = 1;
	}
	for (int i = 0; i < n; i++) printf("%d ", a[i].r);
	return 0;
}