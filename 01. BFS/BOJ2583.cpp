#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
int m, n, k;
int board[101][101];
int vis[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    fastio;
    cin >> m >> n >> k;
    while(k--){
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for(int i = ly; i < ry; i++)
            for(int j = lx; j < rx; j++)
                board[i][j] = 1;
    }

    vector<int> ans;
    int count = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 1 || vis[i][j] == 1) continue;
            queue<pair<int,int>> Q;
            Q.push({i,j}); vis[i][j] = 1;
            int area = 1;
            count++;
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] == 1 || vis[nx][ny] == 1) continue;

                    area++; Q.push({nx,ny}); vis[nx][ny] = 1;
                }
            }
            ans.push_back(area);
        }
    }
    sort(ans.begin(), ans.end());
    cout << count << '\n';
    for(auto i : ans) cout << i << ' ';
}