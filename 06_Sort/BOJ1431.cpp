#include <bits/stdc++.h>
using namespace std;

int n;
string serial[51];

bool cmp(const string& s1, const string& s2){
    // 1. 길이 비교
    int sz1 = s1.size(), sz2 = s2.size();
    if(sz1 != sz2) return sz1 < sz2;
    
    // 2. 숫자 합 비교
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < sz1; i++){
        if('0' <= s1[i] && s1[i] <= '9') sum1 += s1[i] - '0';
        if('0' <= s2[i] && s2[i] <= '9') sum2 += s2[i] - '0';
    }
    if(sum1 != sum2) return sum1 < sum2;

    // 3. 사전 순 비교
    return s1 < s2;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> serial[i];
    sort(serial, serial + n, cmp);
    for(int i = 0; i < n; i++) cout << serial[i] << '\n';
}