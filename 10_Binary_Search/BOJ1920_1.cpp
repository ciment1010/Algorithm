#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, a[100005], m;

int binarysearch(int target){
    int st = 0, en = n - 1;
    while(st <= en){
        int mid = (st + en) / 2;
        if(a[mid] < target) st = mid + 1;
        else if(a[mid] > target) en = mid - 1;
        else return 1;
    }
    return 0;
}

int main(void){
    fastio;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cin >> m;
    while(m--){
        int t; cin >> t;
        cout << binarysearch(t) << '\n';
    }
}