#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, a[100005], m;


int main(void){
    fastio;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cin >> m;
    while(m--){
        int t; cin >> t;
        cout << binary_search(a, a + n, t) << '\n';
    }
}