#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
int board[301][301];
int after[301][301];
int vis[301][301];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N, M;

void melt(int x, int y){
    int sea = 0;
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(board[nx][ny] == 0) sea++;
    }
    
    if(board[x][y] >= sea) after[x][y] = board[x][y] - sea;
    else after[x][y] = 0;
}

int bfs(){
    int ans = 0;
    fill(&vis[0][0], &vis[300][301], 0);
    for(int i = 1; i < N - 1; i++){
        for(int j = 1; j < M - 1; j++){
            if(vis[i][j] == 1 || board[i][j] == 0) continue;
            ans++;
            queue<pair<int,int>> Q; Q.push({i,j}); vis[i][j] = 1;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();

                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
                    Q.push({nx,ny}); vis[nx][ny] = 1;
                }
            }
        }
    }
    return ans;
}

int main(){
    fastio;

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];

    int count = 0;
    while(1){
        int area = bfs();
        if(area >= 2){
            cout << count; return 0;
        }
        else if(area == 0){
            cout << 0; return 0;
        }
        count++;
        for(int i = 1; i < N - 1; i++){
            for(int j = 1; j < M - 1 ; j++){
                melt(i,j);
            }
        }
        for(int i = 0; i < N; i++)
            copy(begin(after[i]), end(after[i]), begin(board[i]));
    }
}