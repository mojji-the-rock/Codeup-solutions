#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n,a[10001],l,ac;

int check(int x)
{
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i] <= x)
            sum+=a[i];
        else
            sum+=x;
    }
    return (sum<=ac);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        l+=a[i];
    }
    sort(a+1,a+1+n);
    scanf("%d",&ac);
    if(l<=ac)                       ///지방 예산 합이 전체 예산 이하
    {
        printf("%d",a[n]);
    }
    else                            ///반대 경우
    {
        l/=n;           ///평균값 l 구함
        while(1)
        {
            check(l);
            if(check(l) == 1)
            {
                if(check(l+1) == 0)     break;
                l++;
            }
            else
            {
                if(check(l-1) == 1)
                {
                    l--;
                    break;
                }
                l--;
            }
        }
        printf("%d",l);
    }
}
