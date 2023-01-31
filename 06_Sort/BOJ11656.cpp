#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s; int sz = s.size();
    vector<string> v;
    for(int i = 0; i < sz; i++) v.push_back(s.substr(i, sz));
    sort(v.begin(), v.end());
    for(auto& i : v) cout << i << '\n';
}