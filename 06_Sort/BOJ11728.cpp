#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
int a[1000001], b[1000001], c[2000001];

int main(){
    fastio;

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int idx1 = 0, idx2 = 0;
    for(int i = 0; i < n + m; i++){
        if(idx1 >= n){c[i] = b[idx2++]; continue;}
        if(idx2 >= m){c[i] = a[idx1++]; continue;}
        
        if(a[idx1] > b[idx2]) c[i] = b[idx2++];
        else c[i] = a[idx1++];
    }    
    for(int i = 0; i < n + m; i++) cout << c[i] << ' ';
}