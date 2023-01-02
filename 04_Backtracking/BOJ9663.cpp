#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool issued1[40];   // y축
bool issued2[40];   // x + y축
bool issued3[40];   // x - y + n - 1 축
int n, cnt;

void func(int cur){ // cur번째 행에 퀸 배치
    if(cur == n){
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++){ //(cur, i)에 퀸 배치
        if(issued1[i] || issued2[cur+i] || issued3[cur-i+n-1])
            continue;
        issued1[i] = true;
        issued2[cur+i] = true;
        issued3[cur-i+n-1] = true;
        func(cur+1);
        issued1[i] = false;
        issued2[cur+i] = false;
        issued3[cur-i+n-1] = false;
    }
}

int main(){
    fastio;
    cin >> n;
    func(0);
    cout << cnt;
    return 0;
}