#include <bits/stdc++.h>
using namespace std;

int n, a, num[2000001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        num[1000000 + a]++;
    }
    for(int i = 0; i < 2000001; i++)
        while(num[i]--)
            cout << i - 1000000 << '\n';
}