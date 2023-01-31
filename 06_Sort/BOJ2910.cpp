#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, c;

bool cmp(const pair<int,int>& p1, const pair<int,int>& p2){
    return p1.X > p2.X;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        int num; bool is_in = false;
        cin >> num;
        for(auto& p : v){
            if(num == p.Y){
                is_in = true;
                p.X++;
                break;
            }
        }
        if(!is_in) v.push_back({1,num});
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(auto p : v)
        while(p.X--) cout << p.Y << ' ';
}