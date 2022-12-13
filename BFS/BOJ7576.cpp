#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// board, r, c, vis

int main(){
    fastio;

    int n, m; cin >> m >> n;
    int board[n][m], vis[n][m];
    queue<pair<int,int>> Q;
    fill(&vis[0][0], &vis[n-1][m], 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) Q.push({i,j});
            if(board[i][j] == 0) vis[i][j] = -1;
        }
    }
    
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] >= 0) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1; 
            Q.push({nx,ny});
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] == -1){
                cout << -1;
                return 0;
            }
            ans = max(ans, vis[i][j]);
        }
    }
    cout << ans << '\n';
}