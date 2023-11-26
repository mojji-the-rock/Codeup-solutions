#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n,ans,col[10],in[20],de[20];

void dfs(int r)
{
    if(r>n)
    {
        ans++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!col[i] && !in[r+i] && !de[n+r-i+1])
        {
            col[i] = 1;
            in[r+i] = 1;
            de[n+r-i+1] = 1;

            dfs(r+1);

            col[i] = 0;
            in[r+i] = 0;
            de[n+r-i+1] = 0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    printf("%d",ans);
}
