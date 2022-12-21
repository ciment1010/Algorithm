#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
int dx[8] = {-2, -1, 1, 2, -2, -1,  1,  2};
int dy[8] = { 1,  2, 2, 1, -1, -2, -2, -1};

int main(){
    fastio;
    int N; cin >> N;
    while(N--){
        int L; cin >> L;
        int board[L][L]; fill(&board[0][0], &board[L-1][L], -1);
        
        queue<pair<int,int>> Q;
        int cur_x, cur_y, des_x, des_y;
        cin >> cur_x >> cur_y >> des_x >> des_y;

        board[cur_x][cur_y] = 0;
        Q.push({cur_x,cur_y});

        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            
            if(cur.X == des_x && cur.Y == des_y) break;

            for(int dir = 0; dir < 8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx < 0 || nx >= L || ny < 0 || ny >= L) continue;
                if(board[nx][ny] >= 0) continue;

                board[nx][ny] = board[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
        cout << board[des_x][des_y] << '\n';
    }
}