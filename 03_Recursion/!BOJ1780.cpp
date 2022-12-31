/*
분할 정복을 활용한 재귀
*/

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int board[2188][2188];
int ans[3];

bool check(int n, int a, int b){
    for(int i = a; i < a + n; i++)
        for(int j = b; j < b + n; j++)
            if(board[a][b] != board[i][j])
                return false;
    return true;
}

void rec(int n, int a, int b){
    if(check(n, a, b)){
        ans[board[a][b] + 1] += 1;
        return;
    }

    int nxt = n / 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            rec(nxt, a + nxt * i, b + nxt * j);
}

int main(void){
    fastio;

    int n; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    rec(n, 0, 0);
    for(int i = 0; i < 3; i++) cout << ans[i] << '\n';
}