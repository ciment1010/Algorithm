#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
int board[64][64];

bool check(int x, int y, int n){
    for(int i = x; i < x+n; i++)
        for(int j = y; j < y+n; j++)
            if(board[x][y] != board[i][j]) return 0;
    return 1;
}

void solve(int x, int y, int n){
    if(check(x, y, n)){
        cout << board[x][y];
        return;
    }
    int z = n / 2;
    cout << '(';
    solve(x    , y    , z);
    solve(x    , y + z, z);
    solve(x + z, y    , z);
    solve(x + z, y + z, z);
    cout << ')';
}

int main(void){
    fastio;

    cin >> N;
    char c;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    solve(0, 0, N);
    return 0;
}