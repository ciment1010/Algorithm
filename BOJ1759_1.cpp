#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int l, c;
char alpha[20];
char ans[20];
bool used[20];

bool aeiou(char x){
    return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

void func(int dep, int st){
    if(dep == l){
        int numv = 0, numc = 0;
        for(int i = 0; i < l; i++){
            if(aeiou(ans[i])) numv++;
            else numc++;
        }

        if(numv >= 1 && numc >=2){
            for(int i = 0; i < l; i++) cout << ans[i];
            cout << '\n';
        }
        return;
    }

    for(int i = st; i < c; i++){
        if(!used[i]){
            ans[dep] = alpha[i];
            used[i] = true;
            func(dep+1, i+1);
            used[i] = false;
        }
    }
}

int main(){
    fastio;

    cin >> l >> c;
    for(int i = 0; i < c; i++) cin >> alpha[i];
    sort(alpha, alpha + c);
    func(0, 0);
    return 0;
}