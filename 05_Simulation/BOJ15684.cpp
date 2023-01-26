#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
int n, m, h;
bool ladder[32][12];
vector<pair<int,int>> possible;

bool Check(){
    for(int i = 1; i <= n; i++){
        int cur = i;
        for(int j = 1; j <= h; j++){
            if(ladder[j][cur - 1]) cur--;
            else if(ladder[j][cur]) cur++;
        }
        if(cur != i) return false;
    }
    return true;
}

int main(){
    fastio;

    cin >> n >> m >> h;
    while(m--){
        int a, b; cin >> a >> b;
        ladder[a][b] = true;
    }

    for(int i = 1; i <= h; i++){
        for(int j = 1; j < n; j++){
            if(ladder[i][j-1] || ladder[i][j] || ladder[i][j+1]) continue;
            possible.push_back({i,j});
        }
    }

    if(Check()){cout << 0; return 0;}

    int ans = 0x7f7f7f7f;
    int size = possible.size();
    for(int i = 0; i < size; i++){
        ladder[possible[i].X][possible[i].Y] = true;
        if(Check()) ans = min(ans, 1);
        for(int j = i+1; j < size; j++){
            ladder[possible[j].X][possible[j].Y] = true;
            if(Check()) ans = min(ans, 2);
            for(int k = j+1; k < size; k++){
                ladder[possible[k].X][possible[k].Y] = true;
                if(Check()) ans = min(ans, 3);
                ladder[possible[k].X][possible[k].Y] = false;
            }
            ladder[possible[j].X][possible[j].Y] = false;
        }
        ladder[possible[i].X][possible[i].Y] = false;
    }
    if(ans == 0x7f7f7f7f) ans = -1;
    cout << ans;
}