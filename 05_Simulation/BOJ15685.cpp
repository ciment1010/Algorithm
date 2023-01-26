#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, X, Y, D, G, ans;
bool board[101][101];

int main(){
    fastio;

    cin >> N;
    while(N--){
        cin >> Y >> X >> D >> G;
        
        vector<int> v;
        v.push_back(D%4);
        board[X][Y] = true;

        while(G--){
            int vSize = v.size();
            for(int i = vSize - 1; i >= 0; i--)
                v.push_back((v[i]+1)%4);
        }

        for(int i = 0; i < v.size(); i++){
            int dir = v[i];
            if(dir == 0) Y++;
            else if(dir == 1) X--;
            else if(dir == 2) Y--;
            else X++;
            board[X][Y] = true;
        }
    }

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(!board[i][j]) continue;
            if(board[i+1][j] && board[i][j+1] && board[i+1][j+1])
                ans++;
        }
    }
    cout << ans;
}