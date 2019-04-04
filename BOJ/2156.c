#include <stdio.h>

int max(int a,int b){if(a>b)return a;else return b;}
int max3(int a,int b, int c){return max(max(a,b),c);}


int main()
{
    int a;
    scanf("%d",&a);

    int b[10001]={0};
    int c[10001]={0};
    int d,e,f;
    int i;
    for(i=0;i<a;i++) scanf("%d",b+i);

    for(i=0;i<a;i++)
    {
        if(i==0) c[i]=b[i];
        else if(i==1) c[i]=b[i]+b[i-1];
        else if(i==2)
        {
            if(b[i]+b[i-2]>=b[i]+b[i-1] && b[i]+b[i-2]>=b[i-1]+b[i-2])      c[i]=b[i]+b[i-2];
            else if(b[i]+b[i-1]>=b[i]+b[i-2] && b[i]+b[i-1]>=b[i-1]+b[i-2]) c[i]=b[i]+b[i-1];
            else if(b[i-1]+b[i-2]>=b[i]+b[i-1] && b[i-1]+b[i-2]>=b[i]+b[i-2])   c[i]=b[i-1]+b[i-2];         }
        else
        {
            d=c[i-1];
            e=c[i-2]+b[i];
            f=c[i-3]+b[i-1]+b[i];
            c[i]=max3(d,e,f);
       }
    }
    printf("%d",c[a-1]);


    return 0;
}