#include <bits/stdc++.h>
using namespace std;

int n;
using P = pair<int,string>;
P member[100001];

bool cmp(const P& p1, const P& p2){
    return p1.first < p2.first;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> member[i].first >> member[i].second;
    stable_sort(member, member + n, cmp);
    for(int i = 0; i < n; i++) cout << member[i].first << ' ' << member[i].second << '\n';
}