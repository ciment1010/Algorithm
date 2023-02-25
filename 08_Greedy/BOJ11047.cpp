#include <bits/stdc++.h>
using namespace std;

int n, k, money[11], ans;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> money[i];
    for(int i = n - 1; i >= 0; i--){
        ans += k / money[i];
        k %= money[i];
    }
    cout << ans;
}