#include <iostream>
#include <stdio.h>

using namespace std;

int a,b,c,n;
int sw=0;

int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&n);
    for(int i=0;i<=n/a;i++)
    {
        for(int j=0;j<=n/b;j++)
        {
            for(int k=0;k<=n/c;k++)
            {
                if(i*a+j*b+k*c == n)
                {
                    sw=1;
                }
            }
        }
    }
    printf("%d",sw);
}
