#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second

int T, M, N, K;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    fastio;
    cin >> T;
    
    while(T--){
        cin >> M >> N >> K;
        int arr[M][N], vis[M][N];
        fill(&arr[0][0], &arr[M-1][N], 0);
        fill(&vis[0][0], &vis[M-1][N], 0);
        
        while(K--){
            int x, y; cin >> x >> y;
            arr[x][y] = 1;
        }

        int ans = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(arr[i][j] == 0 || vis[i][j] == 1) continue;
                ans++;
                queue<pair<int,int>> Q;
                Q.push({i,j}); vis[i][j] = 1;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                        if(arr[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                        
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                        
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}