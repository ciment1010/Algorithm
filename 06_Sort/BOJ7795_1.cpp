#include <bits/stdc++.h>
using namespace std;

int T, n, m;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> n >> m;
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++){
            int a; cin >> a; v.push_back({a,0});
        }
        for(int i = 0; i < m; i++){
            int a; cin >> a; v.push_back({a,1});
        }
        sort(v.begin(), v.end());
        int cnt = 0, ans = 0;
        for(int i = 0; i < n + m; i++){
            if(v[i].second == 0) ans += cnt;
            else cnt++;
        }
        cout << ans << '\n';
    }
}