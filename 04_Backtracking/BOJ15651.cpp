#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
int arr[10];

void func(int k){
    if(k == m){
        for(int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++){
        arr[k] = i;
        func(k+1);
    }
}

int main(){
    fastio;
    cin >> n >> m;
    func(0);
    return 0;
}