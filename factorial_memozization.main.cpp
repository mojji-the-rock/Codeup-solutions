#include <iostream>
#include <stdio.h>

using namespace std;
int f(int a)
{
    if(a<=1) return 1;
    return a*f(a-1);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",f(n));
}
