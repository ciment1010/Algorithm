#include <bits/stdc++.h>
using namespace std;

int n, ans;

bool isprime(int n){
    if(n == 1) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        ans += isprime(x);
    }
    cout << ans;
}