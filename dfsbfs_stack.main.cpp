#include <iostream>
#include <stdio.h>
#include <stack>       ///container adapter
using namespace std;
char a[5000];
stack <int> S;
int main()
{
    /*S.push(3);
    S.top();    ///꺼내지 않고 보기만 함
    S.pop();    ///보지 않고 꺼내기만 함
    S.size();
    S.empty();  ///stack이 비었으면 1이 return
                ///stack이 안 비었으면 0이 return*/
    ///후위 표기법
    /// 1+2(중위 표기법)
    /// 12+(후위 표기법)
    /// 123*+ <-> 1+2*3 (전위 <-> 후위)
    gets(a);
    int i=0;
    while(a[i]!='\0')
    {
        if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
        {
            int y = S.top(); S.pop();
            int x = S.top(); S.pop();
            if(a[i] == '+')
            {
                S.push(x+y);
            }
            if(a[i] == '-')
            {
                S.push(x-y);
            }
            if(a[i] == '*')
            {
                S.push(x*y);
            }
            if(a[i] == '/')
            {
                S.push(x/y);
            }
            i++;
        }
        else if(a[i]==' ') i++;
        else
        {
            int sum=0;
            while(a[i]!=' ')
            {
                sum*=10;
                sum+=a[i]-'0';
                i++;
            }
            S.push(sum);
        }
    }
    printf("%d ",S.top());
}
