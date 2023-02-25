#include <bits/stdc++.h>
using namespace std;

int n, cur, ans;
pair<int,int> meet[100002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> meet[i].second >> meet[i].first;
    sort(meet, meet + n);
    for(int i = 0; i < n; i++){
        if(cur > meet[i].second) continue;
        ans++;
        cur = meet[i].first;
    }
    cout << ans;
}