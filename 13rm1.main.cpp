#include <iostream>
#include <stdio.h>

using namespace std;

int ten[10],n;
char twe[12] = {'A','B','C','D','E','F','G','H','I','J','K','L'};

int main()
{
    scanf("%d",&n);
    for(int i=0;i<10;i++)   ten[i] = i;
    printf("%c%d",twe[(n+8)%12],ten[(n+6)%10]);
}
