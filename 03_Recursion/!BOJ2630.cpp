/*
분할 정복을 활용한 재귀
*/

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int board[130][130];
int ans[2];

bool check(int x, int y, int z){
    for(int i = x; i < z + x; i++)
        for(int j = y; j < z + y; j++)
            if(board[x][y] != board[i][j])
                return false;
    return true;    
}

void solve(int x, int y, int z){
    if(check(x, y, z)){
        ans[board[x][y]]++;
        return;
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            solve(x + i * z / 2, y + j * z / 2, z / 2);
}

int main(void){
    fastio;

    int n; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    solve(0, 0, n);
    for(int i = 0; i < 2; i++) cout << ans[i] << '\n';
}