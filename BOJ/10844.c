#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int S[100][10] = {{0,1,1,1,1,1,1,1,1,1},0 };
	int i,k;
	int sum = 0;
	for(i=1;i<n;i++)
	{
		for(k=0;k<10;k++)
		{
			if(k==0)
			{	S[i][k]=S[i-1][k+1];
			    if(S[i][k]>=1000000000) 
				{	S[i][k] = S[i][k]-1000000000;	}
			}
				
			else if(1<=k && k<=8)
			{	S[i][k]=S[i-1][k-1]+S[i-1][k+1];
			     if(S[i][k]>=1000000000) 
				{	S[i][k] = S[i][k]-1000000000;	}
			}
			else
			{	S[i][k]=S[i-1][k-1];
			     if(S[i][k]>=1000000000) 
				{	S[i][k] = S[i][k]-1000000000;	}
			}

		}
	}

	for(i=0;i<10;i++)
	{
		sum = sum +S[n-1][i];
		if(sum>=1000000000)
		{
			sum=sum-1000000000;
		}
	}
	printf("%d",sum);
	
	return 0;
}