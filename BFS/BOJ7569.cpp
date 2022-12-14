#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
// board, r, c, vis

int main(){
    fastio;

    int n, m, h; cin >> m >> n >> h;
    int board[h][n][m], vis[h][n][m];
    queue<tuple<int,int,int>> Q;
    fill(&vis[0][0][0], &vis[h-1][n-1][m], 0);
    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> board[k][i][j];
                if(board[k][i][j] == 1) Q.push({k,i,j});
                if(board[k][i][j] == 0) vis[k][i][j] = -1;
            }
        }
    }
    
    
    while(!Q.empty()){
        tuple<int,int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 6; dir++){
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            int nz = get<0>(cur) + dz[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(vis[nz][nx][ny] >= 0) continue;
            vis[nz][nx][ny] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1; 
            Q.push({nz,nx,ny});
        }
    }
    int ans = 0;
    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[k][i][j] == -1){
                    cout << -1;
                    return 0;
                }
                ans = max(ans, vis[k][i][j]);
            }
        }
    }
    cout << ans << '\n';
}