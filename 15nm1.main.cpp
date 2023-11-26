#include <iostream>
#include <stdio.h>

using namespace std;

int k,c,a[100001];

int main()
{
    scanf("%d%d",&k,&c);
    for(int i=1;i<=c;i++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        int dif;
        if(m >= n)
        {
            dif = m-n;
            if(k-m+2>=dif)  a[i] = 1;
            else    a[i]=0;
        }
        else
        {
            dif = n-m;
            if(k-n+1>=dif)  a[i] = 1;
            else    a[i]=0;
        }
    }
    for(int i=1;i<=c;i++)
    {
        printf("%d\n",a[i]);
    }
}
