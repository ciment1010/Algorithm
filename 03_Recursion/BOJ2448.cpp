#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int MAX = 1024 * 3 + 2;
char board[MAX][MAX*2-1];

void star(int x, int y){
    board[x][y] = '*';
    board[x+1][y-1] = '*';
    board[x+1][y+1] = '*';

    for(int i = y -2; i <= y + 2; i++) board[x+2][i] = '*';
}

void solve(int x, int y, int n){
    if(n == 3){
        star(x,y); return;
    }

    int z = n / 2;
    solve(x    , y    , z);
    solve(x + z, y - z, z);
    solve(x + z, y + z, z);
}

int main(void){
    fastio;
    int n; cin >> n;
    solve(0, n - 1, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * n - 1; j++){
            if(board[i][j] == '*') cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}