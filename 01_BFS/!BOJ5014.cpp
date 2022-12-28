/*
정상적인 경우에서, BFS의 특성 상 F층 이하 모든 경우를
탐색 함.
따라서, 이미 방문한 층은 거르고, 방문하지 않은 층만
탐색한다.
만약, 그렇지 않다면, 방문했더라도 다시 큐에 들어갈 수
있고, 여러 원소에 대해 중복될 수 있다.
그래서, 시간복잡도는 "지수적으로 증가"하며,
큐에 매우 많은 원소가 들어가 "메모리 초과"가 발생한다.
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