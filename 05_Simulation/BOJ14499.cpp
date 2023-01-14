#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, x, y, k, dir;
int board[21][21];
int dice[6];
int tmp[6];

void Roll(int dir){
    for(int i = 0; i < 6; i++) tmp[i] = dice[i];
    if(dir == 1){ // 悼率
        if(y == m-1) return;
        y++;
        tmp[0] = dice[2];
        tmp[2] = dice[5];
        tmp[3] = dice[0];
        tmp[5] = dice[3];
    }
    else if(dir == 2){ // 辑率
        if(y == 0) return;
        y--;
        tmp[0] = dice[3];
        tmp[2] = dice[0];
        tmp[3] = dice[5];
        tmp[5] = dice[2];
    }
    else if(dir == 3){ // 合率
        if(x == 0) return;
        x--;
        tmp[0] = dice[1];
        tmp[1] = dice[5];
        tmp[4] = dice[0];
        tmp[5] = dice[4];
    }
    else{ // 巢率
        if(x == n - 1) return;
        x++;
        tmp[0] = dice[4];
        tmp[1] = dice[0];
        tmp[4] = dice[5];
        tmp[5] = dice[1];
    }
    for(int i = 0; i < 6; i++) dice[i] = tmp[i];

    if(board[x][y] == 0) board[x][y] = dice[0];
    else{ dice[0] = board[x][y]; board[x][y] = 0; }
    cout << dice[5] << '\n';
}

int main(){
    fastio;

    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    while(k--){
        cin >> dir;
        Roll(dir);
    }
}