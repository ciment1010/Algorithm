#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define MAX 0x7f7f7f7f
int board[4][5][5][5]; // 원본 배열
int maze[5][5][5]; // 연산에 사용될 각 경우의 배열
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};


int Solve(){
    int dist[5][5][5] = {};
    
    // 입/출구가 0이라면 pass
    if(maze[0][0][0] == 0 || maze[4][4][4] == 0) return MAX;

    queue<tuple<int,int,int>> Q;
    Q.push({0,0,0}); dist[0][0][0] = 1;
    while(!Q.empty()){
        tuple<int,int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 6; dir++){
            int x, y, z; tie(x, y, z) = cur;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
            if(maze[nx][ny][nz] == 0) continue;
            if(dist[nx][ny][nz] != 0) continue;
            if(nx == 4 && ny == 4 && nz == 4) return dist[x][y][z];

            dist[nx][ny][nz] = dist[x][y][z] + 1;
            Q.push({nx,ny,nz});
        }
    }
    return MAX;
}

int main(){
    fastio;

    for(int i = 0; i < 5; i++){
        // 회전하지 않은 각 층에 대한 원본 저장
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++)
                cin >> board[0][i][j][k];
        
        // 각 층에 대해 90도씩 회전한 값을 저장
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++)
                board[1][i][j][k] = board[0][i][4 - k][j];
        
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++)
                board[2][i][j][k] = board[1][i][4 - k][j];
        
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++)
                board[3][i][j][k] = board[2][i][4 - k][j];
    }

    int ans = MAX;
    vector<int> order = {0, 1, 2, 3, 4};
    do{
        for(int tmp = 0; tmp < 1024; tmp++){
            int brute = tmp;
            for(int i = 0; i < 5; i++){ // 쌓을 순서에 대한 반복
                int dir =  brute % 4;
                brute /= 4;
                // 각 층에 대한 복사
                for(int j = 0; j < 5; j++)
                    for(int k = 0; k < 5; k++)
                        maze[i][j][k] = board[dir][order[i]][j][k];
            }
            ans = min(ans, Solve());
        }
    }while(next_permutation(order.begin(), order.end()));
    
    if(ans == MAX) cout << -1 << '\n';
    else cout << ans << '\n';
}