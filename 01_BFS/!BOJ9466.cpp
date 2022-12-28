/*
BFS의 그래프적 사고 방식
꼭 큐를 사용해야한다는 편견을 버리기
*/

#include <bits/stdc++.h>
using namespace std;

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;
int arr[100005], state[100005];
int t, n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        fill(state+1, state+n+1, 0);

        for(int i = 1; i <= n; i++){
            if(state[i] == NOT_VISITED){
                int cur = i;
                while(true){
                    state[cur] = i;
                    cur = arr[cur];

                    if(state[cur] == i){
                        while(state[cur] != CYCLE_IN){
                            state[cur] = CYCLE_IN;
                            cur = arr[cur];
                        }
                        break;
                    }
                    else if(state[cur] != 0) break;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(state[i] != CYCLE_IN) ans++;
        }
        cout << ans << '\n';
    }
}