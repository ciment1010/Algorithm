#include <bits/stdc++.h>
using namespace std;

int n, s[505][505], d[505][505];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> s[i][j];
    d[1][1] = s[1][1];
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++)
            d[i][j] = max(d[i-1][j-1], d[i-1][j]) + s[i][j];
    cout << *max_element(d[n] + 1, d[n] + n + 1);
}