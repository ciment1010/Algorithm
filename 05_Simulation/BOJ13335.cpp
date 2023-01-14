#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, w, l;
/*
weight : �ٸ� ���� Ʈ�� ������ ����
ans : �ִ� �ð�
nxt : �������� �ٸ� ���� �ǳʷ��� Ʈ�� �ε���
*/
int weight, ans, nxt; 
int truck[1001], dist[1001]; // Ʈ���� ���Կ� �̵��� �Ÿ�
deque<int> DQ; // �ٸ� ���� �̵� ���� Ʈ���� �ε��� ����

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