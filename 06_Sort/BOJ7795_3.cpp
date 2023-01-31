#include <bits/stdc++.h>
using namespace std;

int T, n, m;
int a[20001], b[20001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        int ans = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        sort(a, a + n); sort(b, b + m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i] > b[j]) ans++;
                else break;
            }
        }
        cout << ans << '\n';
    }
}