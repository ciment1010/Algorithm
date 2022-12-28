#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
char board[1001][1001];
int vis1[1001][1001], vis2[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int T, w, h;

int main(){
    fastio;
    cin >> T;
    while(T--){
        cin >> h >> w;
        queue<pair<int,int>> Q1, Q2;

        fill(&vis1[0][0], &vis1[w-1][h], -1);
        fill(&vis2[0][0], &vis2[w-1][h], -1);
        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                cin >> board[i][j];
                if(board[i][j] == '*'){
                    Q1.push({i,j});
                    vis1[i][j] = 0;
                }
                else if(board[i][j] == '@'){
                    Q2.push({i,j});
                    vis2[i][j] = 0;
                } 
            }
        }
        
        // 불이 지나가는 경로
        while(!Q1.empty()){
            pair<int,int> cur = Q1.front(); Q1.pop();

            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if(vis1[nx][ny] >= 0 || board[nx][ny] == '#') continue;

                vis1[nx][ny] = vis1[cur.X][cur.Y] + 1;
                Q1.push({nx,ny});
            }
        }

        // 수근이 지나가는 경로
        bool escape = false;
        while(!escape && !Q2.empty()){
            pair<int,int> cur = Q2.front(); Q2.pop();

            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx < 0 || nx >= w || ny < 0 || ny >= h){
                    cout << vis2[cur.X][cur.Y] + 1 << '\n';
                    escape = true; break;
                }
                if(vis2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                if(vis1[nx][ny] != -1 && vis1[nx][ny] <= vis2[cur.X][cur.Y] + 1) continue;

                vis2[nx][ny] = vis2[cur.X][cur.Y] + 1;
                Q2.push({nx,ny});
            }
        }
        if(!escape) cout << "IMPOSSIBLE\n";
    }
}