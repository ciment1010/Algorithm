#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, l, ans;
int board[101][101];

void Rotate(){
    int tmp[101][101];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp[i][j] = board[n - 1 - j][i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[i][j] = tmp[i][j];
}

bool is_possible(int r){
    int idx = 0, cnt = 1;
    while(idx < n - 1){
        if(abs(board[r][idx+1] - board[r][idx]) > 1) return false;
        if(board[r][idx] < board[r][idx+1]){
            if(cnt < l) return false;
            idx++; cnt = 1;
        }
        else if(board[r][idx] > board[r][idx+1]){
            if(idx + l >= n) return false;
            for(int i = idx + 1; i < idx + l; i++)
                if(board[r][i] != board[r][i+1]) return false;
            idx += l; cnt = 0;
        }
        else{ idx++; cnt++; }
    }
    return true;
}

int main(){
    fastio;

    cin >> n >> l;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n;  j++)
            cin >> board[i][j];

    // 1. 행 기준
    for(int i = 0; i < n; i++)
        if(is_possible(i)) ans++;

    // 2. 열 기준
    Rotate();
    for(int i = 0; i < n; i++)
        if(is_possible(i)) ans++;
    cout << ans;
}