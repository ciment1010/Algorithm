#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int R, C; cin >> R >> C;
    string board[R];
    int board1[R][C], board2[R][C];
    fill(&board1[0][0], &board1[R - 1][C], -1);
    fill(&board2[0][0], &board2[R - 1][C], -1);
    for(int i = 0; i < R; i++) cin >> board[i];

    queue<pair<int,int>> Q1, Q2;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(board[i][j] == 'F'){
                Q1.push({i,j}); board1[i][j] = 0;
            }
            if(board[i][j] == 'J'){
                Q2.push({i,j}); board2[i][j] = 0;
            }
        }
    }

    while(!Q1.empty()){
        pair<int,int> cur = Q1.front(); Q1.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(board1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            board1[nx][ny] = board1[cur.X][cur.Y] + 1;
            Q1.push({nx,ny});
        }
    }

    while(!Q2.empty()){
        pair<int,int> cur = Q2.front(); Q2.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C){
                cout << board2[cur.X][cur.Y] + 1;
                return 0;
            }
            if(board2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(board1[nx][ny] != -1 && board1[nx][ny] <= board2[cur.X][cur.Y] + 1) continue;
            board2[nx][ny] = board2[cur.X][cur.Y] + 1;
            Q2.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";
}