#include <iostream>
#include <stdio.h>

using namespace std;
int l[2001],r[2001],dp[2001][2001],n;
void solve()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]); ///왼쪽카드만 버렸을 때와 양쪽 카드를 모두 버렸을 때 중에서 최댓값
            if(r[j] < l[i]) ///왼쪽카드보다 오른쪽카드에 적힌 수가 더 클때
            {
                dp[i][j] = max(dp[i][j], dp[i][j-1]+r[j]); ///오른쪽카드를 버렸을 때와 버리지 않을 때의 최댓값
            }
        }
    }
    printf("%d", dp[n][n]);
}
int main()
{
    scanf("%d",&n);
    for(int i=n;i>=1;i--)   scanf("%d",&l[i]);
    for(int i=n;i>=1;i--)   scanf("%d",&r[i]);
    solve();
}
