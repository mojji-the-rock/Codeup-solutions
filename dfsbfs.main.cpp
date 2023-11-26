#include <iostream>
#include <stdio.h>
using namespace std;
/*int f(int a)            ///factorial
{
    if(a<=1)    return 1;
    return a*f(a-1);
}*/
int n,cnt;
int r[1000],h[2000],c[2000];    ///r(row)(열 같으면 |방향에서 겹침)
                                ///h(합)(합이 n이면 /방향 대각선에서 겹침)
                                ///c(차)(차가 1이면 \방향 대각선에서 겹침)
void f(int l)
{
    if(l>n)                                     ///마지막 행에 퀸을 놓으면
    {
        cnt++;                                  ///답 한개 추가
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(r[i]==0 && h[l+i]==0 && c[l-i+n]==0) ///퀸끼리 공격하지 않는 위치일 때
        {
            r[i] = h[l+i] = c[l-i+n] = 1;       ///i행에 놓았으므로 i행을 퀸 불가 위치로 지정
                                                ///(l,i)에 놓았으므로 합이 l+i인 대각선을 퀸 불가 위치로 지정
                                                ///(l,i)에 놓았으므로 차가 l-i+n인 대각선을 퀸 불가 위치로 지정
            f(l+1);                             ///다음 행으로 넘어감
            r[i] = h[l+i] = c[l-i+n] = 0;       ///
        }
    }
}
int main()
{
    ///recursive function-------------------------------------------------------------------------------------------------
    ///int n;
    ///scanf("%d",&n);
    ///printf("%d",f(n));

    ///n-queen problem
    scanf("%d",&n);
    f(1);
    printf("%d",cnt);
}
