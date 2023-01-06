/*
도형의 90도 회전
*/

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
int n, m, k;
int r, c;
int board[42][42]; // 노트북의 배열
int sticker[12][12];

// sticker를 90도씩 회전
void rotate(){
    int tmp[12][12];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            tmp[i][j] = sticker[i][j];
        
    for(int i = 0; i < c; i++)
        for(int j = 0; j < r; j++)
            sticker[i][j] = tmp[r - 1 - j][i];
    swap(r, c);
}

// board[x][y]에 sticker[0][0] ~ [r-1][c-1]까지 가능?
bool Check_space(int x, int y){
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(board[x + i][y + j] == 1 && sticker[i][j] == 1)
                return false;
        
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(sticker[i][j] == 1)
                board[x + i][y + j] = 1;
    return true;  
}

int main(){
    fastio;

    cin >> n >> m >> k;
    
    while(k--){
        cin >> r >> c;

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> sticker[i][j];

        for(int dir = 0; dir < 4; dir++){
            bool is_paste = false;
            for(int i = 0; i <= n - r; i++){
                if(is_paste) break;
                for(int j = 0; j <= m - c; j++){
                    if(Check_space(i, j)){
                        is_paste = true;
                        break;
                    }
                }
            }
            if(is_paste) break;
            rotate();
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cnt += board[i][j];
    cout << cnt << '\n';
}