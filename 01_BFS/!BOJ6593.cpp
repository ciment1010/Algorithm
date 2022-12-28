/*
3차원 배열 초기화

fill(&vis[0][0][0], vis[M-1][M-1][M], 0)
*/

#include <bits/stdc++.h>
#define fastio cin.tie(0) -> sync_with_stdio
using namespace std;

char board[31][31][31];
int vis[31][31][31];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int L, R, C;

int main(){
    fastio;
    
    while(1){
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) return 0;

        queue<tuple<int,int,int>> Q;
        fill(&vis[0][0][0], &vis[30][30][31], -1);
        for(int i = 0; i < L; i++){
            for(int j = 0; j < R; j++){
                for(int k = 0; k < C; k++){
                    cin >> board[i][j][k];
                    if(board[i][j][k] == 'S'){
                        Q.push({i,j,k}); vis[i][j][k] = 0;
                    }
                }
            }
        }

        bool escape = false;
        while(!escape && !Q.empty()){
            tuple<int,int,int> cur = Q.front(); Q.pop();
            int curZ, curX, curY;
            tie(curZ, curX, curY) = cur;

            for(int dir = 0; dir < 6; dir++){
                int nz = curZ + dz[dir];
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                
                if(nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C)
                    continue;
                if(vis[nz][nx][ny] > -1 || board[nz][nx][ny] == '#') continue;
                if(board[nz][nx][ny] == 'E'){
                    cout << "Escaped in " << vis[curZ][curX][curY] + 1 << " minute(s).\n";
                    escape = true; break;
                }

                Q.push({nz,nx,ny});
                vis[nz][nx][ny] = vis[curZ][curX][curY] + 1;
            }
        }
        if(!escape) cout << "Trapped!\n";
    }
}