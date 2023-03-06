#include <bits/stdc++.h>
using namespace std;

int t, n, s[1000001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> s[i];
        int mx = s[n-1];
        long long ans = 0;
        for(int i = n - 2; i >= 0; i--){
            if(s[i] > mx) mx = s[i];
            ans += mx - s[i];
        }
        cout << ans << '\n';
    }
}