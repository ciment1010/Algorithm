#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
int board[100001];

int main(){
    int n, k; cin >> n >> k;
    fill(board, board+100001, -1);
    board[n] = 0;
    queue<int> Q; Q.push(n);
    while(board[k] == -1){
        int cur = Q.front(); Q.pop();
        for(int dir : {cur-1, cur+1, 2*cur}){
            if(dir < 0 || dir > 100000) continue;
            if(board[dir] != -1) continue;
            board[dir] = board[cur] + 1;
            Q.push(dir);
        }
    }
    cout << board[k];
}