#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, x, y, d, ans;
int board[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    fastio;

    cin >> n >> m >> x >> y >> d;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    while(true){
        if(board[x][y] == 0) ans++;
        board[x][y] = -1;
        bool possible = false;
        for(int i = 0; i < 4; i++){
            d = (d + 3) % 4;
            if(board[x+dx[d]][y+dy[d]] == 0){
                x += dx[d]; y += dy[d];
                possible = true;
                break;
            }
        }
        if(possible) continue;
        if(board[x-dx[d]][y-dy[d]] == 1) break;
        x -= dx[d]; y -= dy[d];
    }
    cout << ans;
}