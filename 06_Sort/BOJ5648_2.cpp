#include <bits/stdc++.h>
using namespace std;

int n;
long long a[1000001];

void Reverse(){
    for(int i = 0; i < n; i++){
        long long num = 0;
        while(a[i] > 0){
            num = 10 * num + (a[i] % 10);
            a[i] /= 10;
        }
        a[i] = num;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    Reverse();
    sort(a, a + n);
    for(int i = 0; i < n; i++) cout << a[i] << '\n';
}