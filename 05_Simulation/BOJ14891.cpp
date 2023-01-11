#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

string Gear[4];
int Dirs[4];
int k, num, dir;

void Decide_dir(){
    fill(Dirs, Dirs + 4, 0);
    Dirs[num] = dir;

    // 왼쪽으로 회전 전파
    int idx = num;
    while(idx > 0 && Gear[idx][6] != Gear[idx-1][2]){
        Dirs[idx-1] = -Dirs[idx];
        idx--;
    }

    // 오른쪽으로 회전 전파
    idx = num;
    while(idx < 3 && Gear[idx][2] != Gear[idx+1][6]){
        Dirs[idx+1] = -Dirs[idx];
        idx++;
    }
    /*
    for(int i = num - 1; i >= 0; i--){
        if(Gear[i][2] == Gear[i+1][6]){
            Dirs[i] = 0;
        }
        else{
            Dirs[i] = -Dirs[i+1];
        }
    }
    for(int i = num + 1; i < 4; i++){
        if(Gear[i-1][2] == Gear[i][6]){
            Dirs[i] = 0;
        }
        else{
            Dirs[i] = -Dirs[i-1];
        }
    }
    */
}

void Rotate(){
    for(int num = 0; num < 4; num++){
        if(Dirs[num] == -1) // 반시계 방향
            rotate(Gear[num].begin(), Gear[num].begin()+1, Gear[num].end());
        else if(Dirs[num] == 1) // 시계 방향
            rotate(Gear[num].begin(), Gear[num].begin()+7, Gear[num].end());
        /*
        int tmp[8] = {};
        if(Dirs[num] == 1){ //시계 방향
            tmp[0] = Gear[num][7];
            for(int i = 1; i < 8; i++) tmp[i] = Gear[num][i-1];
        }
        else if(Dirs[num] == -1){ //반시계 방향
            for(int i = 0; i < 7; i++) tmp[i] = Gear[num][i+1];
            tmp[7] = Gear[num][0];
        }
        for(int i = 0; i < 8; i++) Gear[num][i] = tmp[i];
        */
    }
}

int main(){
    fastio;

    for(int i = 0; i < 4; i++) cin >> Gear[i];
    cin >> k;
    while(k--){
        cin >> num >> dir; num--;
        Decide_dir();
        Rotate();
    }
    int ans = 0;
    for(int i = 0; i < 4; i++)
        if(Gear[i][0] == '1') ans += (1 << i);
    cout << ans << '\n';
}