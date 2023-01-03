#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int k;
int num[15];

int main(){
    fastio;

    while(cin >> k){
        if(k == 0) return 0;

        vector<int> a;
        for(int i = 0 ; i < k; i++){
            cin >> num[i];
            a.push_back(i < 6 ? 0 : 1);
        }
        
        do{
            for(int i = 0; i < k; i++)
                if(a[i] == 0) cout << num[i] << ' ';
            cout << '\n';
        }while(next_permutation(a.begin(), a.end()));
        cout << '\n';
    }
}