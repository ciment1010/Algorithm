#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
string field1[12];
string field2[12];
bool vis[12][6];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans;

bool BFS(int x, int y){
    queue<pair<int,int>> Q;
    vector<pair<int,int>> V;
    Q.push({x,y}); V.push_back({x,y});
    vis[x][y] = true;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if(field2[nx][ny] == '.') continue;
            if(vis[nx][ny] == true) continue;
            if(field2[cur.X][cur.Y] != field2[nx][ny]) continue;
            Q.push({nx,ny}); V.push_back({nx,ny});
            vis[nx][ny] = true;
        }
    }
    if(V.size() >= 4){
        for(auto i : V) field2[i.X][i.Y] = '.';
        return true;
    }
    return false;
}

void Gravity(){
    for(int i = 10; i >= 0; i--){
        for(int j = 0; j < 6; j++){
            if(field2[i][j] == '.') continue;
            int tmp = i;
            while(tmp < 11 && field2[tmp+1][j] == '.'){
                swap(field2[tmp][j], field2[tmp+1][j]);
                tmp++;
            }
        }
    }
}

int main(){
    fastio;

    for(int i = 0; i < 12; i++){
        cin >> field1[i];
        field2[i] = field1[i];
    } 

    while(true){
        fill(&vis[0][0], &vis[11][6], false);
        bool flag = false;
        for(int i = 0; i < 12; i++)
            for(int j = 0; j < 6; j++)
                if(field2[i][j] != '.' && vis[i][j] == false)
                    if(BFS(i,j)) flag = true;
                
        if(flag) ans++;
        else break;

        Gravity();
    }
    cout << ans;
}