#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX_N 300000

int n,s;
int sellprice[MAX_N+1]; //sellprice[1]���� ���, �׸� i�� ���������� ����� �� �ִ� ��ü �Ǹ� ����
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
                if(picture[k[i]].height + s > picture[i].height)    ///k[i]��° �׸� ���� + �ǸŰ��� ���� > i��° �׸� ����
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
