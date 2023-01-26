/*
2. 백트래킹
*/
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n,mx = INT_MIN, mn = INT_MAX;
int num[12], op[4];

void Solve(int dep, int ans){
    if(dep == n){
        mx = max(mx, ans); mn = min(mn, ans);
        return;
    }

    for(int i = 0; i < 4; i++){
        if(op[i] == 0) continue;
        op[i]--;
        if(i == 0) Solve(dep + 1, ans + num[dep]);
        else if(i == 1) Solve(dep + 1, ans - num[dep]);
        else if(i == 2) Solve(dep + 1, ans * num[dep]);
        else Solve(dep + 1, ans / num[dep]);
        op[i]++;
    }
}

int main(){
    fastio;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 0; i < 4; i++) cin >> op[i];

    Solve(1, num[0]);
    cout << mx << '\n' << mn << '\n';
}