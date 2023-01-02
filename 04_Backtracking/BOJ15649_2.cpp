#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
vector<int> v;

int main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) v.push_back(i+1);
    do{
        for(int i = 0; i < m; i++) cout << v[i] << ' ';
        cout << '\n';
        reverse(v.begin() + m, v.end());
    }while(next_permutation(v.begin(), v.end()));
    return 0;
}