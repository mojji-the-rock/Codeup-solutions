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
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]); ///����ī�常 ������ ���� ���� ī�带 ��� ������ �� �߿��� �ִ�
            if(r[j] < l[i]) ///����ī�庸�� ������ī�忡 ���� ���� �� Ŭ��
            {
                dp[i][j] = max(dp[i][j], dp[i][j-1]+r[j]); ///������ī�带 ������ ���� ������ ���� ���� �ִ�
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
