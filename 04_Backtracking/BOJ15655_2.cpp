#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
vector<int> v;
vector<int> a;

int main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x; cin >> x; v.push_back(x);
        a.push_back(i < m ? 0 : 1);
    }
    sort(v.begin(), v.end());
    do{
        for(int i = 0; i < n; i++)
            if(a[i] == 0) cout << v[i] << ' ';
        cout << '\n';
    }while(next_permutation(a.begin(), a.end()));
    return 0;
}