#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, w, l;
/*
weight : 다리 위의 트럭 무게의 총합
ans : 최단 시간
nxt : 다음으로 다리 위에 건너려는 트럭 인덱스
*/
int weight, ans, nxt; 
int truck[1001], dist[1001]; // 트럭의 무게와 이동한 거리
deque<int> DQ; // 다리 위에 이동 중인 트럭의 인덱스 저장

int main(){
    fastio;

    cin >> n >> w >> l;
    for(int i = 0; i < n; i++) cin >> truck[i];
    while(dist[n-1] != w){
        if(!DQ.empty() && dist[DQ.front()] == w){
            weight -= truck[DQ.front()];
            DQ.pop_front();
        }
        if(nxt <= n - 1 && truck[nxt] <= l - weight && DQ.size() <= w){
            DQ.push_back(nxt);
            weight += truck[nxt];
            nxt++;
        }
        for(int i = 0; i < DQ.size(); i++) dist[DQ[i]]++;
        ans++;
    }
    cout << ans + 1 << '\n';
}