#include <stdio.h>
#include <queue>
#include <vector>
#define MAX 9999999
using namespace std;
int dis[20001];
struct st
{
    int s,e,w;
};
st arr[101];    ///연결 상태 나타내는 구조체 배열
char a,b,x,y;
int n,m;
int main()
{
    scanf("%d%d\n",&n,&m);
    for(int i=1; i<=n; i++)
        dis[i]=MAX;
    for(int i=1; i<=m; i++)
    {
        scanf("%c %c %d\n",&a,&b,&arr[i].w);
        arr[i].s=a-'A'+1;
        arr[i].e=b-'A'+1;
    }
    scanf("%c %c",&x,&y);   ///시작점 x, 도착점 y
    dis[x-'A'+1]=0;
    for(int i=1; i<=n; i++)
        printf("%d ",dis[i]);
        printf("\n");
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(dis[arr[j].e]>dis[arr[j].s]+arr[j].w)
                dis[arr[j].e]=dis[arr[j].s]+arr[j].w;
        }
        for(int i=1; i<=n; i++)
            printf("%d ",dis[i]);
            printf("\n");
        for(int j=1; j<=m; j++)
        {
            if(dis[arr[j].e]>dis[arr[j].s]+arr[j].w)
            {
                printf("not solve");
                return 0;
            }
        }
    }
    printf("%d",dis[y-'A'+1]);
}
