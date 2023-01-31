#include <bits/stdc++.h>
using namespace std;

int n, a[1000001];

bool cmp(int a, int b){
    return a > b;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++) cout << a[i] << '\n';
}