#include <bits/stdc++.h>
#define fastio cin.tie(0) -> sync_with_stdio
using namespace std;

#define X first
#define Y second
int board[101][101];
int vis[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int max_h, max_c, N;

int main(){
    fastio;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            max_h = max(max_h, board[i][j]);
        }
    }

    while(max_h--){
        int count = 0;
        fill(&vis[0][0], &vis[100][101], 0);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(vis[i][j] == 1 || board[i][j] <= max_h) continue;

                count++;
                queue<pair<int,int>> Q;
                Q.push({i,j}); vis[i][j] = 1;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if(vis[nx][ny] == 1 || board[nx][ny] <= max_h) continue;

                        Q.push({nx,ny}); vis[nx][ny] = 1;
                    }
                }
            }
        }
        max_c = max(max_c, count);
    }
    cout << max_c;
}