#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int arr[10];
bool used[10];
int n, m;

void func(int k){ // k�� �� ���� ���Ǿ�����
    if(k == m){
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++){    // 1 ~ n�� ����
        if(!used[i]){   // i�� ������ �ʾҴٸ�
            arr[k] = i; // k��° ���� 'i'�� ����
            used[i] = true; // i�� ������ ǥ��
            func(k+1); // ���� ���� ����
            used[i] = false; // k��° ���� 'i'�� ���� ��� ��� Ȯ��������, 'i'�� �ʱ�ȭ
        }
    }
}

int main(){
    fastio;
    cin >> n >> m;
    func(0);
    return 0;
}