/*
1. next_permutation을 이용해 연산자를 순열로 배치
*/
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, mx = INT_MIN, mn = INT_MAX;
int num[12], op[12];

int main(){
    fastio;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 0, idx = 0; i < 4; i++){
        int x; cin >> x;
        while(x--) op[idx++] = i;
    }
        
    do{
        int ans = num[0];
        for(int i = 0; i < n-1; i++){
            if(op[i] == 0) ans += num[i+1];
            else if(op[i] == 1) ans -= num[i+1];
            else if(op[i] == 2) ans *= num[i+1];
            else ans /= num[i+1];
        }
        mx = max(mx, ans); mn = min(mn, ans);
    }while(next_permutation(op, op + (n - 1)));
    cout << mx << '\n' << mn << '\n';
}