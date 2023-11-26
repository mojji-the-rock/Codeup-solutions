#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#define MAX 0x7fffffff
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > Q;
vector<pair<int,int> > v[20001];
int dis[20001],n,m;
char s,e;

int main()
{
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;i++)   dis[i]=MAX;
    for(int i=1;i<=m;i++)
    {
        char a,b;
        int c;
        scanf("%c %c %d\n",&a,&b,&c);
        v[a-'A'+1].push_back(make_pair(c,b-'A'+1));
        v[b-'A'+1].push_back({c,a-'A'+1});  ///make_pair을 {}로 바꿔쓸 수 있다.
    }
    scanf("%c %c",&s,&e);
    dis[s-'A'+1]=0;
    Q.push({0,s-'A'+1});
    while(!Q.empty())
    {
        pair<int,int> t=Q.top();Q.pop();
        int node = t.second;
        for(int i=0;i<v[node].size();i++)
        {
            if(dis[v[node][i].second] > dis[node]+v[node][i].first)
            {
                dis[v[node][i].second] = dis[node]+v[node][i].first;
                Q.push({dis[v[node][i].second],v[node][i].second});
            }
        }
    }
    if(dis[e-'A'+1] == MAX) printf("-1");
    else    printf("%d",dis[e-'A'+1]);
}
