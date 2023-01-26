/*
나는 next_permutation을 이용해 순열로 풀었음.
보통은 백트래킹을 활용하여 푸는 것 같고,
3중 for문을 이용한 방법도 있음
*/

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
int n, m, mx;
int board[10][10];
vector<int> v;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    fastio;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) v.push_back(1);
        }
    }
    fill(v.begin(), v.begin() + 3, 0);
    
    do{
        int tmp[10][10] = {}, idx = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                tmp[i][j] = board[i][j];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(tmp[i][j] == 0) tmp[i][j] = !v[idx++];

        queue<pair<int,int>> Q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(tmp[i][j] == 2) Q.push({i,j});
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(tmp[nx][ny] != 0) continue;
                tmp[nx][ny] = 2; Q.push({nx,ny});
            }
        }

        int safe = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(tmp[i][j] == 0) safe++;
            }
        }
        mx = max(mx, safe);
    }while(next_permutation(v.begin(), v.end()));
    cout << mx << '\n';
}