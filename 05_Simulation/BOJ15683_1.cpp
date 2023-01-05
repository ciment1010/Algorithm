#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
int board[10][10]; // 원본 배열
vector<pair<int,int>> V; // cctv 장소를 담는 큐
int mn = 100;

void Up(int cur_x, int cur_y){ // ↑
    for(int i = cur_x - 1; i >= 0; i--){
        if(board[i][cur_y] == 6) return;
        if(board[i][cur_y] == 0) board[i][cur_y] = 7;
    }
}
void Down(int cur_x, int cur_y){ // ↓
    for(int i = cur_x + 1; i < n; i++){
        if(board[i][cur_y] == 6) return;
        if(board[i][cur_y] == 0) board[i][cur_y] = 7;
    }
}
void Left(int cur_x, int cur_y){ // ←
    for(int i = cur_y - 1; i >= 0; i--){
        if(board[cur_x][i] == 6) break;
        if(board[cur_x][i] == 0) board[cur_x][i] = 7;
    }
}
void Right(int cur_x, int cur_y){ // →
    for(int i = cur_y + 1; i < m; i++){
        if(board[cur_x][i] == 6) break;
        else if(board[cur_x][i] == 0) board[cur_x][i] = 7;
    }
}

void Solve(int k){
    if(k == V.size()){
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == 0) cnt++;
        mn = min(mn, cnt);
        return;
    }

    int cur_x = V[k].first, cur_y = V[k].second;
    int temp[10][10];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            temp[i][j] = board[i][j];

    if(board[cur_x][cur_y] == 1){
        for(int dir = 0; dir < 4; dir++){
            if(dir == 0) Up(cur_x, cur_y);
            else if(dir == 1) Down(cur_x, cur_y);
            else if(dir == 2) Left(cur_x, cur_y);
            else Right(cur_x, cur_y);
            Solve(k + 1);
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    board[i][j] = temp[i][j];
        }
    }
    else if(board[cur_x][cur_y] == 2){
        for(int dir = 0; dir < 2; dir++){
            if(dir == 0){
                Up(cur_x, cur_y);
                Down(cur_x, cur_y);
            }
            else{
                Left(cur_x, cur_y);
                Right(cur_x, cur_y);
            }
            Solve(k + 1);
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    board[i][j] = temp[i][j];
        }
    }
    else if(board[cur_x][cur_y] == 3){
        for(int dir = 0; dir < 4; dir++){
            if(dir == 0){
                Left(cur_x, cur_y);
                Up(cur_x, cur_y);
            }
            else if(dir == 1){
                Up(cur_x, cur_y);
                Right(cur_x, cur_y);
            }
            else if(dir == 2){
                Right(cur_x, cur_y);
                Down(cur_x, cur_y);
            }
            else{
                Down(cur_x, cur_y);
                Left(cur_x, cur_y);
            }
            Solve(k + 1);
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    board[i][j] = temp[i][j];
        }
    }
    else if(board[cur_x][cur_y] == 4){
        for(int dir = 0; dir < 4; dir++){
            if(dir == 0){
                Up(cur_x, cur_y);
                Down(cur_x, cur_y);
                Left(cur_x, cur_y);
            }
            else if(dir == 1){
                Up(cur_x, cur_y);
                Down(cur_x, cur_y);
                Right(cur_x, cur_y);
            }
            else if(dir == 2){
                Left(cur_x, cur_y);
                Right(cur_x, cur_y);
                Up(cur_x, cur_y);
            }
            else{
                Left(cur_x, cur_y);
                Right(cur_x, cur_y);
                Down(cur_x, cur_y);
            }
            Solve(k + 1);
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    board[i][j] = temp[i][j];
        }
    }
    else if(board[cur_x][cur_y] == 5){
        Up(cur_x, cur_y);
        Down(cur_x, cur_y);
        Left(cur_x, cur_y);
        Right(cur_x, cur_y);
        Solve(k + 1);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                board[i][j] = temp[i][j];
    }
}

int main(){
    fastio;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] > 0 && board[i][j] < 6)
                V.push_back({i,j});
        }
    }
    Solve(0);
    cout << mn << '\n';
}