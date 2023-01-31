#include <bits/stdc++.h>
using namespace std;

int n;
string str[20001];

bool cmp(const string& s1, const string& s2){
    int sz1 = s1.size(), sz2 = s2.size();
    if(sz1 != sz2) return sz1 < sz2;
    return s1 < s2;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string s;
    for(int i = 0; i < n; i++) cin >> str[i];
    sort(str, str + n, cmp);
    for(int i = 0; i < n; i++){
        if(i > 0 && str[i] == str[i - 1]) continue;
        cout << str[i] << '\n';
    }
}