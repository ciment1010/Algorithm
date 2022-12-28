/*
각 영역에서 거리를 확장
*/

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[101][101];
int vis[101][101];  // Labeling에서 사용
int dist[101][101]; // 거리 구하기에서 사용
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

    // 영역을 Labeling(섬의 개수를 구하면서 각 영역을 구분)
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

    // 섬의 영역을 큐에 넣음
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

    // 각 섬을 중심으로 뻗어나가면서 거리를 구함
    // (x,y)가 n번 섬으로부터 얼마만큼 멀리 있는가를 구함
    // 따라서 최소 다리 길이 : dist[cur.X][cur.Y] + dist[nx][ny]
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