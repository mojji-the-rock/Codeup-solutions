#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int S[102][102],n,cnt,Size[101];
bool visited[101][101];
queue<int> Q;
void dfs(int x,int y)                                  ///dfs 버전
{
    Size[cnt]++;                                       ///재귀 할 때마다 cnt번째 굴 크기 추가
    int dx[] = {1,0,-1,0};                             ///방향벡터 설정
    int dy[] = {0,1,0,-1};
    for(int i=0; i<4; i++)                             ///동서남북 탐색
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(S[nx][ny]&&!visited[nx][ny])                ///동서남북 중 굴이고 방문한적 없으면
        {
            visited[nx][ny]=1;                         ///방문 흔적 남김
            dfs(nx,ny);                                ///재귀
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)                             ///미니맵 입력 받음
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&S[i][j]);
        }
    }
    for(int i=1; i<=n; i++)                             ///두더지 굴 탐색
    {
        for(int j=1; j<=n; j++)
        {
            if(S[i][j] && !visited[i][j])               ///S[i][j]가 굴이고 방문한 적 없으면
            {
                visited[i][j] = 1;                      ///방문 흔적 남김
                cnt++;                                  ///굴 개수 추가
                //dfs(i,j);                             ///dfs탐색 버전
                Q.push(i);Q.push(j);
                while(!Q.empty())
                {
                    int x = Q.front();
                    Q.pop();
                    int y = Q.front();
                    Q.pop();
                    Size[cnt]++;
                    int dx[] = {1,0,-1,0};                             ///방향벡터 설정
                    int dy[] = {0,1,0,-1};
                    for(int i=0; i<4; i++)                             ///동서남북 탐색
                    {
                        int nx = x+dx[i];
                        int ny = y+dy[i];
                        if(S[nx][ny]&&!visited[nx][ny])                ///동서남북 중 굴이고 방문한적 없으면
                        {
                            visited[nx][ny]=1;                         ///방문 흔적 남김
                            Q.push(nx);Q.push(ny);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",cnt);
    sort(Size,Size+cnt);
    for(int i=1; i<=cnt; i++)
        printf("%d ",Size[i]);

}
