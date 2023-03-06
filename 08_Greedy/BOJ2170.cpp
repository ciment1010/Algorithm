#include <bits/stdc++.h>
using namespace std;

int n, ans;
pair<int,int> line[1000010];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> line[i].first >> line[i].second;
    sort(line, line + n);
    int minL = line[0].first, maxR = line[0].second;
    for(int i = 1; i < n; i++){
        int l = line[i].first, r = line[i].second;
        if (l <= maxR && r >= maxR) maxR = r;
        else if(l > maxR){
            ans += maxR - minL;
            minL = l;
            maxR = r;
        }
    }
    cout << ans + maxR - minL;
}