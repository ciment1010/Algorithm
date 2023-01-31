#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> point[100001];

bool cmp(pair<int,int>& p1, pair<int,int>& p2){
    if(p1.second != p2.second) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> point[i].first >> point[i].second;
    sort(point, point + n, cmp);
    for(int i = 0; i < n; i++) cout << point[i].first << ' ' << point[i].second << '\n';
}