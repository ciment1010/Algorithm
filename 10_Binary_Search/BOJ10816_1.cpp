#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, a[500005], m;

int lower_idx(int target, int len){
    int st = 0, en = len;
    while(st < en){
        int mid = (st + en) / 2;
        if(a[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_idx(int target, int len){
    int st = 0, en = len;
    while(st < en){
        int mid = (st + en) / 2;
        if(a[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main(void){
    fastio;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cin >> m;
    while(m--){
        int t; cin >> t;
        cout << upper_idx(t, n) - lower_idx(t, n) << '\n';
    }
}