#include <bits/stdc++.h>
using namespace std;

int sign = 1, sum, ans;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    for(auto c : s){
        if(c == '+' || c == '-'){
            ans += sum * sign;
            if(c == '-') sign = -1;
            sum = 0;
        }
        else{
            sum *= 10;
            sum += c - '0';
        }
    }
    ans += sum * sign;
    cout << ans;
}