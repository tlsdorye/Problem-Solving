#include <stdio.h>
#include <stdlib.h>
int main()
{
	int t;
	int i,j;
	int Y=0,K=0;
	scanf("%d",&t);
	int* a = (int*)malloc(sizeof(int)*t);
	for(i=0;i<t;i++)
	{
		int b[18];
		for(j=0;j<18;j++) scanf("%d",b+j);
		for(j=0;j<18;j++)
		{
			if(j%2==0) Y=Y+b[j];
			else if(j%2==1)K=K+b[j];
		}
		if(K>Y)printf("Korea\n");
		if(K<Y)printf("Yonsei\n");
		if(K==Y)printf("Draw\n");
	}
	
	return 0;
}