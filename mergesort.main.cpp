#include <iostream>
#include <stdio.h>

using namespace std;
int a[8] = {0,4,2,7,9,2,5,4};
int b[8];
void me(int ls,int le,int rs, int re)
{
    int lidx = ls, ridx = rs,idx=ls;
    while(lidx<=le && ridx<=re)
    {
        if(a[lidx]<a[ridx])
            b[idx++] = a[lidx++];
        else
            b[idx++] = a[ridx++];
    }
    if(idx>le)
    {
        for(int i=ridx; i<=re; i++) b[idx++] = a[i];
    }
    if(ridx>re)
    {
        for(int i=lidx; i<=le; i++) b[idx++] = a[i];
    }
    for(int i=ls; i<=re; i++)   a[i] = b[i];
}
void f(int s,int e)
{
    if(s == e)
        return;
    int m = (s+e)/2;
    f(s,m);
    f(m+1,e);
    me(s,m,m+1,e);
}
int main()
{
    f(0,7);
    for(int i=0; i<8; i++)
        printf("%d ",a[i]);
}
