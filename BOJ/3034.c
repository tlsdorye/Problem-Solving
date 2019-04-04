#include <stdio.h>

int main()
{
	int n, w, h, i;
	scanf("%d %d %d",&n,&w,&h);
	for (i = 0; i < n; i++)
	{
		int a[100];
		scanf("%d", a+i);
		if (a[i]*a[i] <= h*h + w*w )printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}