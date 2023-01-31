#include <bits/stdc++.h>
using namespace std;

int n, a[1001], tmp[1001];

void merge(int st, int en){
    int mid = (st + en) / 2;
    int lidx = st, ridx = mid;
    for(int i = st; i < en; i++){
        if(ridx == en) tmp[i] = a[lidx++];
        else if(lidx == mid) tmp[i] = a[ridx++];
        else if(a[lidx] <= a[ridx]) tmp[i] = a[lidx++];
        else tmp[i] = a[ridx++];
    }
    for(int i = st; i < en; i++) a[i] = tmp[i];
}

void merge_sort(int st, int en){
    if(en == st + 1) return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    merge_sort(0, n);
    for(int i = 0; i < n; i++) cout << a[i] << '\n';
}