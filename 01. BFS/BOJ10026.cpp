#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
char board[102][102];
int vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N;

void BFS(){
    queue<pair<int,int>> Q;
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(vis[i][j] == 1) continue;
            ans++;
            Q.push({i,j}); vis[i][j] = 1;

            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(vis[nx][ny] == 1 || board[cur.X][cur.Y] != board[nx][ny]) continue;

                    vis[nx][ny] = 1; Q.push({nx,ny});
                }
            }
            
        }
    }
    cout << ans;
}


int main(){
    fastio;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    BFS();
    cout << ' ';

    fill(&vis[0][0], &vis[101][102], 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] == 'G') board[i][j] = 'R';
        }
    }

    BFS();
}