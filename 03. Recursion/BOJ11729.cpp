#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

void hanoi(int a, int b, int n){
    if(n == 1){
        cout << a << ' ' << b << '\n';
        return;
    }
    hanoi(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    hanoi(6-a-b, b, n-1);
}

int main(){
    fastio;
    int n; cin >> n;
    cout << (1<<n) -1 << '\n';
    hanoi(1, 3, n);
}