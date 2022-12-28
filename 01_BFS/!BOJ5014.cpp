/*
�������� ��쿡��, BFS�� Ư�� �� F�� ���� ��� ��츦
Ž�� ��.
����, �̹� �湮�� ���� �Ÿ���, �湮���� ���� ����
Ž���Ѵ�.
����, �׷��� �ʴٸ�, �湮�ߴ��� �ٽ� ť�� �� ��
�ְ�, ���� ���ҿ� ���� �ߺ��� �� �ִ�.
�׷���, �ð����⵵�� "���������� ����"�ϸ�,
ť�� �ſ� ���� ���Ұ� �� "�޸� �ʰ�"�� �߻��Ѵ�.
*/

#include <bits/stdc++.h>
#define fastio cin.tie(0) -> sync_with_stdio
using namespace std;

#define X first
#define Y second
int board[1000001];
int F, S, G, U, D;

int main(){
    fastio;
    
    cin >> F >> S >> G >> U >> D;

    F--; S--; G--;
    int dx[2] = {U, -D};
    fill(board, board+1000001, -1);

    queue<int> Q;
    Q.push(S); board[S] = 0;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();

        for(auto nxt : {cur + U, cur - D}){
            if(nxt < 0 || nxt > F || board[nxt] != -1)
                continue;

            board[nxt] = board[cur] + 1;
            Q.push(nxt);
        }
    }
    if(board[G] == -1) cout << "use the stairs";
    else cout << board[G];
}