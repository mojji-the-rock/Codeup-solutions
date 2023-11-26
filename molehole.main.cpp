#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int S[102][102],n,cnt,Size[101];
bool visited[101][101];
queue<int> Q;
void dfs(int x,int y)                                  ///dfs ����
{
    Size[cnt]++;                                       ///��� �� ������ cnt��° �� ũ�� �߰�
    int dx[] = {1,0,-1,0};                             ///���⺤�� ����
    int dy[] = {0,1,0,-1};
    for(int i=0; i<4; i++)                             ///�������� Ž��
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(S[nx][ny]&&!visited[nx][ny])                ///�������� �� ���̰� �湮���� ������
        {
            visited[nx][ny]=1;                         ///�湮 ���� ����
            dfs(nx,ny);                                ///���
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)                             ///�̴ϸ� �Է� ����
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&S[i][j]);
        }
    }
    for(int i=1; i<=n; i++)                             ///�δ��� �� Ž��
    {
        for(int j=1; j<=n; j++)
        {
            if(S[i][j] && !visited[i][j])               ///S[i][j]�� ���̰� �湮�� �� ������
            {
                visited[i][j] = 1;                      ///�湮 ���� ����
                cnt++;                                  ///�� ���� �߰�
                //dfs(i,j);                             ///dfsŽ�� ����
                Q.push(i);Q.push(j);
                while(!Q.empty())
                {
                    int x = Q.front();
                    Q.pop();
                    int y = Q.front();
                    Q.pop();
                    Size[cnt]++;
                    int dx[] = {1,0,-1,0};                             ///���⺤�� ����
                    int dy[] = {0,1,0,-1};
                    for(int i=0; i<4; i++)                             ///�������� Ž��
                    {
                        int nx = x+dx[i];
                        int ny = y+dy[i];
                        if(S[nx][ny]&&!visited[nx][ny])                ///�������� �� ���̰� �湮���� ������
                        {
                            visited[nx][ny]=1;                         ///�湮 ���� ����
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
