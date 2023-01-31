#include <bits/stdc++.h>
using namespace std;

int n, a[10001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int num; cin >> num; a[num]++;
    }
    for(int i = 0; i < 10001; i++)
        while(a[i]--)
            cout << i << '\n';
}