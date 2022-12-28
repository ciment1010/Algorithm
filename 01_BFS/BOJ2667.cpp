#include <bits/stdc++.h>
#define fastio cin.tie(0) -> sync_with_stdio
using namespace std;

#define X first
#define Y second
string board[26];
int vis[26][26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N;

int main(){
    fastio;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> board[i];
    }

    int count = 0;
    vector<int> ans;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(vis[i][j] == 1 || board[i][j] == '0') continue;
            
            count++;
            int area = 1;
            queue<pair<int,int>> Q;
            Q.push({i,j}); vis[i][j] = 1;
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(board[nx][ny] == '0' || vis[nx][ny] == 1) continue;

                    area++; Q.push({nx,ny}); vis[nx][ny] = 1;
                }
            }
            ans.push_back(area);
        }
    }
    cout << count << '\n';
    sort(ans.begin(), ans.end());
    for(auto i : ans) cout << i << '\n';
}