/*
BFS와 백트래킹 접목
-> 백트래킹으로 가능한 조합을 생각하고, 그것을 BFS로 확인
*/

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
string board[5];
bool mask[25];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans;

int main(){
    fastio;

    // 7명의 가능한 조합을 1차원으로 생각
    fill(mask+7, mask+25, true);
    for(int i = 0; i < 5; i++) cin >> board[i];
    
    do{
        queue<pair<int,int>> Q;
        // 가능한 조합을 표시, 방문한 칸 표시
        bool possible[5][5] = {}, vis[5][5] = {};

        // 각각의 경우에서, 가능한 1차원 조합을, 2차원으로 표현하여 큐에 추가
        for(int i = 0; i < 25; i++){
            if(mask[i] == 0){
                int x = i / 5;
                int y = i % 5;
                possible[x][y] = true;

                if(Q.empty()){
                    Q.push({x,y});
                    vis[x][y] = true;
                }
            }
        }

        // 다솜파의 인원, 주위 사람의 수
        int dasom = 0, around = 0;
        // 가능한 조합 중, 각각의 경우를 탐색함
        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            around++;
            if(board[cur.X][cur.Y] == 'S') dasom++;

            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                // 이미 방문한 칸, 가능하지 않은 조합을 방문
                if(vis[nx][ny] || !possible[nx][ny]) continue;

                Q.push({nx,ny}); vis[nx][ny] = true;
            }
        }
        if(dasom >= 4 && around >= 7) ans++;
    }while(next_permutation(mask, mask+25));
    
    cout << ans;
}