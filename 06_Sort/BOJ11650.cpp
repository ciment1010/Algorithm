#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> point[100001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> point[i].first >> point[i].second;
    sort(point, point + n);
    for(int i = 0; i < n; i++) cout << point[i].first << ' ' << point[i].second << '\n';
}