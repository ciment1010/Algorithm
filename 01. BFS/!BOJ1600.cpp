/*
bfs�� 3���� �迭�� ���� �� �����غ���.
���� �ִܱ��̿��� �� �ٸ� ������ �߰� �� �� ���ȴ�.
�ش� ������ �����Ǹ�, �ٷ� �������� �հ� ���� �װ����� bfs�� �����Բ�
->3������ ���Ǹ�, tuple�� ���� ���̹Ƿ� tie()�� �� ��������!
*/

#include <bits/stdc++.h>
using namespace std;

int board[202][202];
int dist[32][202][202];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int hx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
queue<tuple<int, int, int>> Q;
int w, h, k;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> h >> w;
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
            cin >> board[i][j];
    Q.push({0, 0, 0});

    while (!Q.empty()){
        int cnt, x, y;
        tie(cnt, x, y) = Q.front();
        if(x == w - 1 && y == h -1){
            cout << dist[cnt][x][y]; return 0;
        }
        Q.pop();

        if (cnt < k){
            for (int i = 0; i < 8; i++){
                int nx = x + hx[i], ny = y + hy[i];
                if (nx < 0 || ny < 0 || w <= nx || h <= ny)
                    continue;
                if (board[nx][ny])
                    continue;
                if (dist[cnt + 1][nx][ny])
                    continue;
                dist[cnt + 1][nx][ny] = dist[cnt][x][y] + 1;
                Q.push({cnt + 1, nx, ny});
            }
        }
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || w <= nx || h <= ny)
                continue;
            if (board[nx][ny])
                continue;
            if (dist[cnt][nx][ny])
                continue;
            dist[cnt][nx][ny] = dist[cnt][x][y] + 1;
            Q.push({cnt, nx, ny});
        }
    }
    cout << -1;
}