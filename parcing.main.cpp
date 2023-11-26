#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
string a;
int main()
{
    cin>>a;
    for(int i=0;i<=a.size()-1;i++)
    {
        if(a.at(i) == ',')  a.at(i) = ' ';
        else if(a.at(i) == ';') a.at(i) = '\n';
        else if(a.at(i) == ' ')
        {
            for(int j=i;j<=a.size()-2;j++)
            {
                a.at(j) = a.at(j+1);
            }
        }
    }
    cout<<a;
}
