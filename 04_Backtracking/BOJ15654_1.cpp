#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
int temp[10];
int arr[10];
int used[10];

void func(int dep){
    if(dep == m){
        for(int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++){
        if(!used[i]){
            arr[dep] = temp[i];
            used[i] = true;
            func(dep+1);
            used[i] = false;
        }
    }
}

int main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> temp[i];
    sort(temp, temp+n);
    func(0);
    return 0;
}