#include <iostream>
#include <stdio.h>

using namespace std;

int n,k,ans;
int a[6];

int f(int a)
{
    if(a == 0)  return 0;
    else return 1;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int s,b;
        scanf("%d%d",&s,&b);
        if(b == 1 || b==2)
        {
            a[1]++;
        }
        else if(b == 3 || b==4)
        {
            if(s == 0)  a[2]++;
            else    a[3]++;
        }
        else
        {
            if(s == 0)  a[4]++;
            else    a[5]++;
        }
    }
    for(int i=1;i<=5;i++)
    {
        ans+=a[i]/k+f(a[i]%k);
    }
    printf("%d",ans);
}
