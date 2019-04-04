#include <stdio.h>
int main()
{
	int n, s, m;
	int i, k;
	int v[101] = {0};
	scanf("%d %d %d",&n,&s,&m);
	for(i=0;i<n;i++)
	{	scanf("%d",v+i);	}
	int ex[1001] = {0};
	ex[s]=1;
	int ey[1001] = {0};
for(i=0;i<n;i++)
	{
		for(k=0;k<1001;k++)
		{
			if(ex[k]==1 && k+v[i]<=m)
			{
				ey[k+v[i]]=1;
			}
			if(ex[k]==1 && k-v[i]>=0)
			{
				ey[k-v[i]]=1;
			}
		}
		for(k=0;k<1001;k++)
		{
			ex[k]=ey[k];
			ey[k]=0;
		}
	}
	for(i=1000;i>=0;i--)
	{
		if(ex[i]==1)
		{
			printf("%d",i);
			return 0;
		}
	}
    printf("-1");
	return 0;
}