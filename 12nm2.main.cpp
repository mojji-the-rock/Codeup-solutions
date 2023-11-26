#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX_N 300000

int n,s;
int sellprice[MAX_N+1]; //sellprice[1]부터 사용, 그림 i를 마지막으로 골랐을 때 최대 전체 판매 가격
int M[MAX_N+1]; //max(0~sellprice[i])
int k[MAX_N+1];
struct pic
{
    int height, cost;
}picture [MAX_N+1];
bool cmp(pic &p1,pic &p2)
{
    return p1.height<p2.height;
}
void solve()
{
    sort(picture+1,picture+1+n,cmp);
    for(int i=1; i<=n; i++)
    {
        k[i] = k[i-1];
        while(1)
        {
            if(k[i] >= 0)
            {
                if(picture[k[i]].height + s > picture[i].height)    ///k[i]번째 그림 높이 + 판매가능 높이 > i번째 그림 높이
                {
                    k[i]--;
                    break;
                }
            }
            if(k[i] == i-1)
                break;
            k[i]++;
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(k[i] >= 0)   sellprice[i] = picture[i].cost + M[k[i]];
        M[i] = max(M[i-1],sellprice[i]);
    }
    printf("%d", M[n]);
}
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d", &picture[i].height, &picture[i].cost);
    }
    solve();
}
