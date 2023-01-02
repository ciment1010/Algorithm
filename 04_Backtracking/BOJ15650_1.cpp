#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
int arr[10];
bool used[10];

void func(int k){
    if(k == m){
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int start = 1;
    if(k != 0) start = arr[k-1] + 1;
    for(int i = start; i <= n; i++){
        if(!used[i]){
            arr[k] = i;
            used[i] = true;
            func(k+1);
            used[i] = false;
        }
    }
}

int main(){
    fastio;
    cin >> n >> m;
    func(0);
    return 0;
}