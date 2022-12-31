#include <bits/stdc++.h>
using namespace std;

const string Q = "\"����Լ��� ������?\"";
const string A[3] = {
                    "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.",
                   "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.",
                   "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\""
                   };

void recursion(int n, int cnt){
    for(int i = 0; i < cnt; i++) cout << "____";
    cout << Q << '\n';

    if(n == 0){
        for(int i = 0; i < cnt; i++) cout << "____";
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        for(int i = 0; i < cnt; i++) cout << "____";
        cout << "��� �亯�Ͽ���.\n";
        return;
    }
    
    for(auto s : A){
        for(int i = 0; i < cnt; i++) cout << "____";
        cout << s << '\n';
    }

    recursion(n-1, cnt + 1);

    for(int i = 0; i < cnt; i++) cout << "____";
    cout << "��� �亯�Ͽ���.\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0; cin >> n;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

    recursion(n, cnt);
}