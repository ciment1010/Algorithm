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
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    fill(&vis[0][0], &vis[n-1][m], 0);

    queue<pair<int,int>> Q;
    int count = 0, max_area = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!board[i][j] || vis[i][j]) continue;

            vis[i][j] = 1;
            Q.push({i,j}); 
            int area = 1;
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || !board[nx][ny]) continue;
                    vis[nx][ny] = 1, area++;
                    Q.push({nx,ny});
                }
            }
            count++;
            max_area = max(max_area, area);
        }
    }
    cout << count << '\n' << max_area << '\n';
}