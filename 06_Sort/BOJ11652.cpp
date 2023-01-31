#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[100005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int cnt = 0, mxcnt = 0;
    long long mx = -(1ll << 62) - 1;
    for(int i = 0; i < n; i++){
        if(i == 0 || arr[i-1] == arr[i]) cnt++;
        else{
            if(cnt > mxcnt){
                mxcnt = cnt;
                mx = arr[i - 1];
            }
            cnt = 1;
        }
    }
    if(cnt > mxcnt) mx = arr[n - 1];
    cout << mx;
}