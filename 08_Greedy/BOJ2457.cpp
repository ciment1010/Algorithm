#include <bits/stdc++.h>
using namespace std;

int n, ans;
pair<int,int> f[100005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int m1, d1, m2, d2; 
        cin >> m1 >> d1 >> m2 >> d2;
        f[i] = {m1 * 100 + d1, m2 * 100 + d2};
    }
    int cur = 301;
    while(cur < 1201){
        int nxt = cur;
        for(int i = 0; i < n; i++){
            if(f[i].first <= cur && f[i].second > nxt)
                nxt = f[i].second;
        }
        if(nxt == cur){
            cout << 0;
            return 0;
        }
        ans++;
        cur = nxt;
    }
    cout << ans;
}