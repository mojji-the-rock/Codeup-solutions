#include <iostream>
#include <stdio.h>

using namespace std;

int h,m,s,tim;

int main()
{
    scanf("%d%d%d%d",&h,&m,&s,&tim);
    s+=tim;
    m+=s/60;
    h+=m/60;
    printf("%d %d %d",h%24,m%60,s%60);
}
