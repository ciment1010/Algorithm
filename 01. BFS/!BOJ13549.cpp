// 0-1 bfs

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int arr[200001];

int main(){
    fastio;

    int n, k; cin >> n >> k;
    for(int i = 0; i < 200001; i++) arr[i] = -1;
    queue<int> Q; Q.push(n); arr[n] = 0;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();

        if(cur == k){
            cout << arr[k]; return 0;
        }

        int dx[3] = {cur *2, cur - 1, cur + 1};
        for(int i = 0; i < 3; i++){
            if(dx[i] < 0 || dx[i] >= 200001) continue;
            if(arr[dx[i]] > -1) continue;

            if(i == 0) arr[dx[i]] = arr[cur];
            else arr[dx[i]] = arr[cur] + 1;

            Q.push(dx[i]);
        }
    }
}