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

    int n, m; cin >> n >> m;
    int board[n][m], vis[n][m];
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            board[i][j] = s[j] - '0';
        }
    }
    fill(&vis[0][0], &vis[n-1][m], 0);

    queue<pair<int,int>> Q;

    vis[0][0] = 0;
    Q.push({0,0}); 
    
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || !board[nx][ny]) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1; 
            Q.push({nx,ny});
        }
    }
    cout << vis[n-1][m-1]  + 1<< '\n';
}