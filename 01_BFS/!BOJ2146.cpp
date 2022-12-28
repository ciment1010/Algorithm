/*
�� �������� �Ÿ��� Ȯ��
*/

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[101][101];
int vis[101][101];  // Labeling���� ���
int dist[101][101]; // �Ÿ� ���ϱ⿡�� ���
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    // ������ Labeling(���� ������ ���ϸ鼭 �� ������ ����)
    int label = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] == 1 || board[i][j] == 0)
                continue;

            queue<pair<int,int>> Q;
            Q.push({i,j});
            board[i][j] = label; vis[i][j] = 1;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();

                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if(board[nx][ny] == 0 || vis[nx][ny] == 1)
                        continue;
                    
                    Q.push({nx,ny});
                    board[nx][ny] = label; vis[nx][ny] = 1;
                }
            }
            label++;
        }
    }

    // ���� ������ ť�� ����
    fill(&dist[0][0], &dist[n-1][n], -1);
    queue<pair<int,int>> Q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] != 0){
                dist[i][j] = 0;
                Q.push({i,j});
            }
        }
    }

    // �� ���� �߽����� ������鼭 �Ÿ��� ����
    // (x,y)�� n�� �����κ��� �󸶸�ŭ �ָ� �ִ°��� ����
    // ���� �ּ� �ٸ� ���� : dist[cur.X][cur.Y] + dist[nx][ny]
    int ans = 999999;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if(board[nx][ny] == board[cur.X][cur.Y])
                continue;
            if(board[nx][ny] != 0){
                ans = min(ans, dist[cur.X][cur.Y] + dist[nx][ny]);
            }
            else{
                board[nx][ny] = board[cur.X][cur.Y];
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
    }
    cout << ans;
}