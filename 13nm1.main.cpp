#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int m,n,l,s[100002],ans,k=1;    ///사대 s,동물 a

struct st
{
    int x,y;
};
st a[100002];

bool cmp(st &st1,st &st2)
{
    return st1.x<st2.x;
}

int main()
{
    scanf("%d%d%d",&m,&n,&l);   ///사대 수 m,동물 수 n,사정거리 l
    for(int i=1; i<=m; i++)
    {
        scanf("%d",&s[i]);
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i].x);
        scanf("%d",&a[i].y);
    }
    sort(s+1,s+1+m);
    sort(a+1,a+1+n,cmp);

    for(int i=1; i<=n; i++)
    {
        while(s[k+1] < a[i].x && k!=m)
        {
            k++;
        }
        if(k<m)
        {
            if(abs(s[k]-a[i].x) + a[i].y<=l || abs(s[k+1]-a[i].x) + a[i].y<=l)  ans++;
        }
        else
        {
            if(abs(s[k]-a[i].x) + a[i].y<=l) ans++;
        }
    }

    printf("%d",ans);
}
