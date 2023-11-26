#include <iostream>
#include <stdio.h>

int k,g[14],S,ans;
int test_case[2600001];
using namespace std;

void f(int a,int idx)
{
    if(idx == k+1)
    {
        if(a>0) test_case[a] = 1;
        return;
    }
    else
    {
        printf("%d\n",idx);
        for(int i=-1;i<=1;i++)  f(a+i*g[idx],idx+1);
    }
}

int main()
{
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&g[i]);
        S+=g[i];
    }
    f(0,0);
    for(int i=1;i<=S;i++)
    {
        printf("\ntest_case[%d] = %d",i,test_case[i]);
        if(!test_case[i])   ans++;
    }
    printf("\nans = %d",ans);
}
