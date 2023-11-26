#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char s[100001];

int main()
{
    gets(s);
    int lv=0;
    for(int i=0;i<=strlen(s)-1;i++)
    {
        if(s[i] == '(') lv++;
        else lv--;
        printf("%d\n",lv);
    }
}
