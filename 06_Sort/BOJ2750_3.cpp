#include <bits/stdc++.h>
using namespace std;

int n, a[1001];

void quick_sort(int st, int en){
    if(en <= st + 1) return;
    int pivot = a[st];
    int l = st + 1, r = en - 1;
    while(true){
        while(l <= r && a[l] <= pivot) l++;
        while(l <= r && a[r] >= pivot) r--;
        if(l > r) break;
        swap(a[l], a[r]);
    }
    swap(a[st], a[r]);
    quick_sort(st, r);
    quick_sort(r + 1, en);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    quick_sort(0, n);
    for(int i = 0; i < n; i++) cout << a[i] << '\n';
}