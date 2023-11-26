#include <iostream>
#include <stdio.h>

using namespace std;

int a[11],b[11],T;

int main()
{
    int M=0;
    for(int i=1;i<=10;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
    }
    for(int i=1;i<=10;i++)
    {
        T+=(b[i]-a[i]);
        if(T>=M)    M=T;
    }
    printf("%d",M);
}
