#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int arr[25];
int n, s, cnt;

void func(int cur, int tot){
    if(cur == n){
       if(tot == s) cnt++;
       return; 
    }
    func(cur+1, tot);
    func(cur+1, tot+arr[cur]);
}

int main(){
    fastio;
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];
    func(0, 0);
    if(s == 0) cnt --;
    cout << cnt;
    return 0;
}