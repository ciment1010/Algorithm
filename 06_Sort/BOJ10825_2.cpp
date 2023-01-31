#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<int,int,int,string>> v;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        string name; int kor, eng, mat;
        cin >> name >> kor >> eng >> mat;
        v.push_back({-kor, eng, -mat, name});
    }
    sort(v.begin(), v.end());
    for(auto& s : v) cout << get<3>(s) << '\n';
}