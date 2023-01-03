#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int l, c;
char alpha[20];
bool used[20];

bool aeiou(char x){
    return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

int main(){
    fastio;

    cin >> l >> c;
    vector<int> v;
    for(int i = 0; i < c; i++){
        cin >> alpha[i];
        v.push_back(i < l ? 0 : 1);
    }
    sort(alpha, alpha + c);
    
    do{
        string ans;
        int numv = 0, numc = 0;
        for(int i = 0; i < c; i++){
            if(v[i] == 0){
                ans += alpha[i];
                if(aeiou(alpha[i])) numv++;
                else numc++;
            }
        }

        if(numv >= 1 && numc >= 2) cout << ans << '\n';
    }while(next_permutation(v.begin(), v.end()));

    return 0;
}