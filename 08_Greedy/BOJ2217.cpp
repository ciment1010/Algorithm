#include <bits/stdc++.h>
using namespace std;

int n, rope[100005], ans;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> rope[i];
    sort(rope, rope + n);
    for(int i = 1; i <= n; i++) ans = max(ans, rope[n - i] * i);
    cout << ans;
}