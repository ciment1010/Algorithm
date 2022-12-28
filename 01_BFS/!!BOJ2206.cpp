#include <bits/stdc++.h>
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string board[1000];
int dist[1000][1000][2];
// dist[x][y][0] : 벽을 하나도 부수지 않고 도달하는 시간
// dist[x][y][1] : 벽을 하나만 부수고 도달하는 시간
int N, M;

int bfs(){
    fill(&dist[0][0][0], &dist[999][999][1000], -1);
    dist[0][0][0] = dist[0][0][1] = 1;
    queue<tuple<int,int,int>> Q;
    Q.push({0,0,0});

    while(!Q.empty()){
        int x, y, broken;
        tie(x, y, broken) = Q.front();
        // 도달했을 때, 함수 탈출
        if(x == N-1 & y == M-1) return dist[x][y][broken];

        Q.pop();
        int nxtdist = dist[x][y][broken] + 1;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            // 다음 칸이 벽이 아니고, 방문한 적 없음
            if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1){
                dist[nx][ny][broken] = nxtdist;
                Q.push({nx, ny, broken});
            }
            // 다음 칸이 벽이고, 방문한 적 없음 -> 부술지 말지 선택
            if(!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1){
                dist[nx][ny][1] = nxtdist;
                Q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}

int main(){
    fastio;
    
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> board[i];
        
    cout << bfs();
    return 0;
}