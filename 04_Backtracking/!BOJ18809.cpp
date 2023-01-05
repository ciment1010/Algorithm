#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second

int n,m,g,r;
int board[52][52];
// 배양액이 가능한 공간의 {x,y}좌표 저장
vector<pair<int,int> > can;
int cansz;
// next_permutation에 이용. can:7, g:1, r:4 -> {0,0,1,2,2,2,2}
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int E = 0;
const int G = 1;
const int R = 2;
const int F = 3;

int brute[10];

int func(){
    int cnt = 0;
    pair<int,int> state[52][52]; // {arrival time, color}

    queue<pair<int,int>> Q;
    for(int i = 0; i < cansz; i++){
        if(brute[i] == G || brute[i] == R){
            state[can[i].X][can[i].Y] = {0, brute[i]};
            Q.push(can[i]);
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        int curtime = state[cur.X][cur.Y].X;
        int curcolor = state[cur.X][cur.Y].Y;
        if(state[cur.X][cur.Y].Y == F) continue;
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 0) continue;
            if(state[nx][ny].Y == E){
                state[nx][ny] = {curtime + 1, curcolor};
                Q.push({nx,ny});
            }
            else if(state[nx][ny].Y == R){
                if(curcolor == G && state[nx][ny].X == curtime + 1){
                    cnt++;
                    state[nx][ny].Y = F;
                }
            }
            else if(state[nx][ny].Y == G){
                if(curcolor == R && state[nx][ny].X == curtime + 1){
                    cnt++;
                    state[nx][ny].Y = F;
                }
            }
        }
    }
    return cnt;
}


int main(){
    fastio;

    cin >> n >> m >> g >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 2)
                can.push_back({i,j});
        }
    }
    cansz = can.size();
    fill(brute + cansz - g - r, brute + cansz - r, G);
    fill(brute + cansz - r, brute + cansz, R);
    int mx = 0;
    do{
        mx = max(mx, func());
    }while(next_permutation(brute, brute + cansz));
    cout << mx << '\n';
}