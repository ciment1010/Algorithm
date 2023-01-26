#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
int n, k, x, y, l, t, ans;
char c;
int board[101][101];
queue<pair<int,char>> Switch;
deque<pair<int,int>> Snake;
// 상, 우, 하, 좌
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    fastio;

    cin >> n >> k;
    while(k--){
        cin >> x >> y;
        board[x-1][y-1] = 2;
    }
    cin >> l;
    while(l--){
        cin >> t >> c;
        Switch.push({t,c});
    }

    Snake.push_back({0,0});
    int dir = 1; // 우측
    while(true){
        dir %= 4;

        auto cur = Snake.front();
        board[cur.X][cur.Y] = 1;
        ans++;

        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) break;
        if(board[nx][ny] == 1) break;

        if(board[nx][ny] != 2){
            auto tail = Snake.back();
            board[tail.X][tail.Y] = 0;
            Snake.pop_back();
        }

        auto is_switch = Switch.front();
        if(is_switch.X == ans){
            if(is_switch.Y == 'L') dir += 3;
            else dir += 1;
            Switch.pop();
        }
        Snake.push_front({nx,ny});
    }
    cout << ans;
}