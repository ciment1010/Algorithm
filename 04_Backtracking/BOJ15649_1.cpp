#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int arr[10];
bool used[10];
int n, m;

void func(int k){ // k는 몇 개가 사용되었는지
    if(k == m){
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++){    // 1 ~ n에 대해
        if(!used[i]){   // i가 사용되지 않았다면
            arr[k] = i; // k번째 수로 'i'를 택함
            used[i] = true; // i가 사용됨을 표시
            func(k+1); // 다음 수를 정함
            used[i] = false; // k번째 수로 'i'를 택한 모두 경우 확인했으니, 'i'를 초기화
        }
    }
}

int main(){
    fastio;
    cin >> n >> m;
    func(0);
    return 0;
}