#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, x[1000005];

int main(void){
    fastio;

    cin >> n;
    vector<int> tmp, uni;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        tmp.push_back(x[i]);
    }
    sort(tmp.begin(), tmp.end());
    for(int i = 0; i < n; i++){
        if(i == 0 || tmp[i - 1] != tmp[i])
            uni.push_back(tmp[i]);
    }
    for(int i = 0; i < n; i++){
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
    }
}