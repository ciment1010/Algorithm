#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
int s[10];
int w[10];
int cnt, mx;

void func(int x){
    if(x == n){
        mx = max(mx, cnt);
        return;
    }

    if(s[x] <= 0 || cnt == n-1){
        func(x+1);
        return;
    }

    for(int i = 0; i < n; i++){
        if(i == x || s[i] <= 0) continue;

        s[x] -= w[i];
        s[i] -= w[x];
        if(s[x] <= 0) cnt++;
        if(s[i] <= 0) cnt++;
        func(x+1);
        if(s[x] <= 0) cnt--;
        if(s[i] <= 0) cnt--;
        s[x] += w[i];
        s[i] += w[x];
    } 
}

int main(){
    fastio;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i] >> w[i];
    func(0);
    cout << mx;
}