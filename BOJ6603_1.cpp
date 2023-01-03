#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int k;
int num[15];
int arr[10];
bool used[15];

void func(int dep, int st){
    if(dep == 6){
        for(int i = 0; i < 6; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = st; i < k; i++){
        if(!used[i]){
            arr[dep] = num[i];
            used[i] = true;
            func(dep+1, i+1);
            used[i] = false;
        }
    }
}

int main(){
    fastio;

    while(cin >> k){
        if(k == 0) return 0;
        for(int i = 0 ; i < k; i++) cin >> num[i];
        func(0, 0);
        cout << '\n';
    }
}