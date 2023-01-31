#include <bits/stdc++.h>
using namespace std;

using T = tuple<string,int,int,int>;
int n;
vector<T> v;

bool cmp(const T& t1, const T& t2){
    string n1, n2; int k1, k2, e1, e2, m1, m2;
    tie(n1, k1, e1, m1) = t1;
    tie(n2, k2, e2, m2) = t2;

    if(k1 != k2) return k1 > k2;
    if(e1 != e2) return e1 < e2;
    if(m1 != m2) return m1 > m2;
    return n1 < n2;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        string name; int g1, g2, g3;
        cin >> name >> g1 >> g2 >> g3;
        v.push_back({name,g1,g2,g3});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto& s : v) cout << get<0>(s) << '\n';
}