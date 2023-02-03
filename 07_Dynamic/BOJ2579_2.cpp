#include <bits/stdc++.h>
using namespace std;

int s[305], n, d[305], ans;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        ans += s[i];
    }
    if(n <= 2){
        cout << ans;
        return 0;
    }
    d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
    for(int i = 4; i <= n; i++)
        d[i] = min(d[i-3], d[i-2]) + s[i];
    cout << ans - min(d[n-1], d[n-2]);
}