#include <iostream>
#include <stdio.h>
#include <stack>       ///container adapter
using namespace std;
char a[5000];
stack <int> S;
int main()
{
    /*S.push(3);
    S.top();    ///������ �ʰ� ���⸸ ��
    S.pop();    ///���� �ʰ� �����⸸ ��
    S.size();
    S.empty();  ///stack�� ������� 1�� return
                ///stack�� �� ������� 0�� return*/
    ///���� ǥ���
    /// 1+2(���� ǥ���)
    /// 12+(���� ǥ���)
    /// 123*+ <-> 1+2*3 (���� <-> ����)
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
