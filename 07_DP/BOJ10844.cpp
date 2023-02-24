#include <bits/stdc++.h>
using namespace std;

#define MAX 105
#define MOD 1000000000
int n;
long long d[MAX][10], ans;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= 9; i++) d[1][i] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
            if(j == 0) d[i][j] = d[i-1][1];
            else if(j == 9) d[i][j] = d[i-1][8];
            else d[i][j] = d[i-1][j-1] + d[i-1][j+1];
            d[i][j] %= MOD;
        }
    }
    for(int i = 0; i <= 9; i++) ans += d[n][i];
    ans %= MOD;
    cout << ans;
}